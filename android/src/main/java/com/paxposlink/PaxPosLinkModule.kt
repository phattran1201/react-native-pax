package com.paxposlink

import android.bluetooth.BluetoothAdapter
import android.hardware.usb.UsbDevice
import android.os.Build
import android.util.Log
import androidx.annotation.RequiresApi
import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.ReadableMap
import com.facebook.react.bridge.WritableArray
import com.facebook.react.bridge.WritableMap
import com.pax.gl.commhelper.IBtScanner
import com.pax.gl.commhelper.impl.PaxGLComm
import com.pax.poscomm.usb.utils.USBUtil
import com.pax.poscore.commsetting.AidlSetting
import com.pax.poscore.commsetting.BluetoothSetting
import com.pax.poscore.commsetting.CommunicationSetting
import com.pax.poscore.commsetting.HttpSetting
import com.pax.poscore.commsetting.HttpsSetting
import com.pax.poscore.commsetting.SslSetting
import com.pax.poscore.commsetting.TcpSetting
import com.pax.poscore.commsetting.UartSetting
import com.pax.poscore.commsetting.UsbSetting
import com.pax.poscore.internal.ExecutionCode
import com.pax.poslinkadmin.ExecutionResult
import com.pax.poslinkadmin.constant.ContinuousScreen
import com.pax.poslinkadmin.constant.EdcType
import com.pax.poslinkadmin.constant.EntryMode
import com.pax.poslinkadmin.constant.ReceiptPrintFlag
import com.pax.poslinkadmin.constant.TransactionType
import com.pax.poslinkadmin.util.AmountRequest
import com.pax.poslinkadmin.util.MultiMerchant
import com.pax.poslinksemiintegration.POSLinkSemi
import com.pax.poslinksemiintegration.Terminal
import com.pax.poslinksemiintegration.batch.BatchCloseRequest
import com.pax.poslinksemiintegration.batch.BatchCloseResponse
import com.pax.poslinksemiintegration.constant.CardPresentIndicator
import com.pax.poslinksemiintegration.constant.TipRequestFlag
import com.pax.poslinksemiintegration.constant.VehicleClassId
import com.pax.poslinksemiintegration.report.HistoryReportRequest
import com.pax.poslinksemiintegration.report.HistoryReportResponse
import com.pax.poslinksemiintegration.report.LocalDetailReportRequest
import com.pax.poslinksemiintegration.report.LocalTotalReportRequest
import com.pax.poslinksemiintegration.transaction.DoCreditRequest
import com.pax.poslinksemiintegration.transaction.DoCreditResponse
import com.pax.poslinksemiintegration.transaction.DoDebitRequest
import com.pax.poslinksemiintegration.transaction.DoDebitResponse
import com.pax.poslinksemiintegration.util.AccountRequest
import com.pax.poslinksemiintegration.util.AccountResponse
import com.pax.poslinksemiintegration.util.AutoRental
import com.pax.poslinksemiintegration.util.AvsRequest
import com.pax.poslinksemiintegration.util.CashierRequest
import com.pax.poslinksemiintegration.util.CommercialRequest
import com.pax.poslinksemiintegration.util.FleetCardRequest
import com.pax.poslinksemiintegration.util.HostInformationRequest
import com.pax.poslinksemiintegration.util.HostInformationResponse
import com.pax.poslinksemiintegration.util.Lodging
import com.pax.poslinksemiintegration.util.MotoECommerceRequest
import com.pax.poslinksemiintegration.util.Original
import com.pax.poslinksemiintegration.util.PaymentEmvTag
import com.pax.poslinksemiintegration.util.Restaurant
import com.pax.poslinksemiintegration.util.TorResponse
import com.pax.poslinksemiintegration.util.TraceRequest
import com.pax.poslinksemiintegration.util.TransactionBehaviorRequest
import com.pax.serialport.SerialPortFinderPax
import com.paxposlink.Utils

class PaxPosLinkModule(
    reactApplicationContext: ReactApplicationContext,
) : ReactContextBaseJavaModule() {
    private var reactContext: ReactApplicationContext? = reactApplicationContext
    private var posLink: POSLinkSemi? = POSLinkSemi.getInstance()
    private var salesRequest: PaxRequestModel? = null
    private var terminal: Terminal? = null

    // Bluetooth scan state (mô hình poll giống demo: quét nền, gom vào list, UI poll getBluetoothDeviceList).
    private data class BtDev(
        val name: String,
        val mac: String,
        val rssi: Int,
    )

    private var btScanner: IBtScanner? = null
    private val btLock = Any()
    private val btDevices = LinkedHashMap<String, BtDev>() 

    override fun getName(): String = "PaxPoslink"

    @ReactMethod
    fun logEvent(message: String) {
        Log.d("PaxPosLinkModule", "Log event: $message")
    }

    @ReactMethod
    fun initPOSLink(
        ip: String,
        port: String?,
        timeout: Int?,
        promise: Promise,
    ) {
        val tcpSetting =
            TcpSetting().apply {
                this.ip = ip
                this.port = port ?: PaxPosConstant.PORT
                this.timeout = timeout ?: PaxPosConstant.TIMEOUT
            }
        val tcpSettingInfo = "=>: type=TCP, ip=$ip, port=${tcpSetting.port}, timeout=${tcpSetting.timeout}"
        Log.i("TcpSetting", tcpSettingInfo)
        finalizeTerminal(tcpSetting, tcpSettingInfo, timeout ?: PaxPosConstant.TIMEOUT, promise)
    }

    /**
     * Khởi tạo kết nối tới terminal cho mọi kiểu giao tiếp mà SDK hỗ trợ.     *
     * config:
     *  - type: "TCP" | "SSL" | "HTTP" | "HTTPS" | "UART" | "USB" | "AIDL" | "BLUETOOTH"
     *  - ip, port            : dùng cho TCP/SSL/HTTP/HTTPS
     *  - serialPort, baudRate: dùng cho UART
     *  - deviceName          : dùng cho USB (tuỳ chọn)
     *  - macAddr             : dùng cho BLUETOOTH
     *  - timeout             : chung cho tất cả (ms)
     */
    @ReactMethod
    fun initPOSLinkConn(
        config: ReadableMap,
        promise: Promise,
    ) {
        val type = (config.getString("type") ?: "TCP").uppercase()
        val timeout =
            if (config.hasKey("timeout") && !config.isNull("timeout")) config.getInt("timeout") else PaxPosConstant.TIMEOUT
        val ip = config.getString("ip") ?: ""
        val port = config.getString("port") ?: PaxPosConstant.PORT
        try {
            when (type) {
                "TCP" ->
                    finalizeTerminal(TcpSetting(ip, port, timeout), "=>: type=TCP, ip=$ip, port=$port, timeout=$timeout", timeout, promise)
                "SSL" ->
                    finalizeTerminal(SslSetting(ip, port, timeout), "=>: type=SSL, ip=$ip, port=$port, timeout=$timeout", timeout, promise)
                "HTTP" ->
                    finalizeTerminal(HttpSetting(ip, port, timeout), "=>: type=HTTP, ip=$ip, port=$port, timeout=$timeout", timeout, promise)
                "HTTPS" ->
                    finalizeTerminal(HttpsSetting(ip, port, timeout), "=>: type=HTTPS, ip=$ip, port=$port, timeout=$timeout", timeout, promise)
                "UART" -> {
                    val serialPort = config.getString("serialPort") ?: "COM1"
                    val baudRate = config.getString("baudRate") ?: "9600"
                    finalizeTerminal(
                        UartSetting(serialPort, baudRate, timeout),
                        "=>: type=UART, serialPort=$serialPort, baudRate=$baudRate, timeout=$timeout",
                        timeout,
                        promise,
                    )
                }
                "AIDL" -> finalizeTerminal(AidlSetting(), "=>: type=AIDL", timeout, promise)
                "BLUETOOTH", "BLE" -> {
                    val macAddr = config.getString("macAddr") ?: ""
                    val btSetting =
                        BluetoothSetting().apply {
                            this.macAddr = macAddr
                            this.timeout = timeout
                        }
                    finalizeTerminal(btSetting, "=>: type=BLUETOOTH, macAddr=$macAddr, timeout=$timeout", timeout, promise)
                }
                "USB" -> connectUsb(timeout, config.getString("deviceName"), promise)
                else -> promise.reject("UNSUPPORTED_CONN_TYPE", "Unsupported connection type: $type")
            }
        } catch (e: Exception) {
            promise.reject("INIT_ERROR", e)
        }
    }

    private fun finalizeTerminal(
        setting: CommunicationSetting,
        settingInfo: String,
        timeoutMs: Int,
        promise: Promise,
    ) {
        val settled = java.util.concurrent.atomic.AtomicBoolean(false)

        val worker =
            Thread {
                try {
                    terminal = posLink?.getTerminal(reactContext, setting)
                    Log.e("terminal", terminal.toString())
                    if (terminal == null) {
                        Log.d("Failed Init", "getTerminal null — $settingInfo")
                        if (settled.compareAndSet(false, true)) {
                            promise.reject("CONNECT_FAILED", "Could not connect to terminal. Check connection settings.")
                        }
                        return@Thread
                    }

                    // init() là round-trip thật xuống terminal → đây mới là lúc biết kết nối OK hay không.
                    val initResult = terminal?.manage?.init()
                    val resp = initResult?.response()
                    val serialNumber = resp?.sn().orEmpty()

                    if (resp != null && serialNumber.isNotEmpty()) {
                        Log.d("Success Init", "Create terminal success")
                        if (settled.compareAndSet(false, true)) {
                            val modelName = resp.modelName().orEmpty()
                            val info =
                                PaxTerminalInfoModel(
                                    serialNumber = serialNumber,
                                    modelName = modelName,
                                    appName = resp.appName().orEmpty(),
                                ).toWritableMap()
                            val message =
                                if (modelName.isNotEmpty()) {
                                    "Connected to terminal successfully (SN: $serialNumber, model: $modelName)"
                                } else {
                                    "Connected to terminal successfully (SN: $serialNumber)"
                                }
                            val map = Arguments.createMap()
                            map.putString("message", message)
                            map.putBoolean("status", true)
                            map.putMap("serialNumber", info)
                            promise.resolve(map)
                        }
                    } else {
                        // Lộ lý do thật: code (TIMEOUT/ERROR/…) + message từ SDK, thay vì che bằng settingInfo.
                        val code = try { initResult?.code()?.toString() } catch (e: Exception) { null } ?: "NO_RESPONSE"
                        val msg = initResult?.message().orEmpty()
                        Log.d("Failed Init", "init failed code=$code msg=$msg — $settingInfo")
                        if (settled.compareAndSet(false, true)) {
                            promise.reject(
                                "CONNECT_FAILED",
                                "Terminal did not respond to init (code=$code" +
                                    (if (msg.isNotEmpty()) ", msg=$msg" else "")  + " $settingInfo" +
                                    ") ",
                            )
                        }
                    }
                } catch (e: Throwable) {
                    Log.d("Failed Init", "init throwable: ${e.message} — $settingInfo")
                    if (settled.compareAndSet(false, true)) promise.reject("INIT_ERROR", "${e.message ?: e.toString()} ($settingInfo)", e)
                }
            }
        worker.start()

        val watchdogMs = timeoutMs.coerceAtLeast(0).toLong()
        Thread {
            try {
                worker.join(watchdogMs)
            } catch (_: InterruptedException) {
            }
            if (settled.compareAndSet(false, true)) {
                val reason = if (worker.isAlive) "terminal not responding" else "connection ended unexpectedly (no response)"
                Log.d("Failed Init", "Connect timeout/aborted after ${watchdogMs}ms — $settingInfo")
                promise.reject(
                    "CONNECT_TIMEOUT",
                    "Connection timed out (${watchdogMs}ms): $reason.",
                )
            }
        }.start()
    }

    @ReactMethod
    fun requestUsbPermission(promise: Promise) {
        val ctx = reactContext?.currentActivity ?: reactContext
        if (ctx == null) {
            promise.reject("NO_CONTEXT", "No available activity/context to request USB permission")
            return
        }
        try {
            if (USBUtil.hasPermission(ctx)) {
                promise.resolve(true)
                return
            }
            // Không có thiết bị USB nào → dialog sẽ không bật, callback không bao giờ fire.
            // Resolve false ngay để tránh await treo vĩnh viễn.
            if (USBUtil.getDevices(ctx).isEmpty()) {
                promise.resolve(false)
                return
            }
            // Chưa có quyền → đăng ký lắng nghe rồi bật dialog; resolve theo kết quả user chọn.
            USBUtil.registerPermissionGrantBroadcast(
                ctx,
                object : USBUtil.UsbPermissionCallback {
                    override fun onGranted(device: UsbDevice?) {
                        promise.resolve(true)
                    }

                    override fun onFail() {
                        promise.resolve(false)
                    }
                },
                null,
            )
            USBUtil.requestUSBPermissionIfNeed(ctx)
        } catch (e: Exception) {
            promise.reject("USB_PERMISSION_ERROR", e.message, e)
        }
    }

    /**
     * Liệt kê các thiết bị USB đang cắm để UI cho user chọn (type: 'USB' → deviceName).
     * Mỗi phần tử: { deviceName, productName, vendorId, productId }.
     */
    @ReactMethod
    fun listUsbDevices(promise: Promise) {
        val ctx = reactContext?.currentActivity ?: reactContext
        if (ctx == null) {
            promise.reject("NO_CONTEXT", "No available activity/context to list USB devices")
            return
        }
        try {
            val arr = Arguments.createArray()
            USBUtil.getDevices(ctx).forEach { device ->
                val m = Arguments.createMap()
                m.putString("deviceName", device.deviceName)
                m.putString("productName", device.productName ?: "")
                m.putInt("vendorId", device.vendorId)
                m.putInt("productId", device.productId)
                arr.pushMap(m)
            }
            promise.resolve(arr)
        } catch (e: Exception) {
            promise.reject("USB_LIST_ERROR", e)
        }
    }

    /**
     * Trả về danh sách baud rate hợp lệ để UI dựng dropdown cho kết nối UART.
     */
    @ReactMethod
    fun getSupportedBaudRates(promise: Promise) {
        try {
            val arr = Arguments.createArray()
            UartSetting.getSupportedBaudRate().forEach { arr.pushString(it) }
            promise.resolve(arr)
        } catch (e: Exception) {
            promise.reject("BAUD_ERROR", e)
        }
    }

    /**
     * Quét các cổng serial (UART) hiện có trên thiết bị để UI dựng dropdown chọn `serialPort`.
     * Trả về danh sách đường dẫn cổng, ví dụ ["/dev/ttyS0", "/dev/ttyUSB0", ...].
     */
    @ReactMethod
    fun listSerialPorts(promise: Promise) {
        try {
            val arr = Arguments.createArray()
            SerialPortFinderPax().getAllDevicesPath()?.forEach { arr.pushString(it) }
            promise.resolve(arr)
        } catch (e: Exception) {
            promise.reject("SERIAL_LIST_ERROR", e)
        }
    }

    /**
     * Kiểm tra Bluetooth đã bật chưa (UI nên nhắc bật trước khi quét).
     * @return true nếu adapter tồn tại và đang bật.
     */
    @ReactMethod
    fun checkBluetoothEnable(promise: Promise) {
        try {
            val adapter = BluetoothAdapter.getDefaultAdapter()
            promise.resolve(adapter != null && adapter.isEnabled)
        } catch (e: Exception) {
            promise.reject("BT_CHECK_ERROR", e)
        }
    }

    /**
     * Bắt đầu quét thiết bị Bluetooth. Kết quả gom vào list nội bộ (dedupe theo MAC);
     * UI poll [getBluetoothDeviceList] để hiển thị realtime, rồi gọi [stopBluetoothSearch] khi đóng.
     * @param useBle true = quét BLE, false = quét Bluetooth classic (mặc định giống demo).
     * @param timeout thời lượng quét truyền cho scanner (theo demo: 1000). <=0 sẽ dùng mặc định 1000.
     */
    @ReactMethod
    fun startBluetoothSearch(
        useBle: Boolean,
        timeout: Int,
        promise: Promise,
    ) {
        val ctx = reactContext?.applicationContext ?: reactContext
        if (ctx == null) {
            promise.reject("NO_CONTEXT", "No available context for bluetooth search")
            return
        }
        try {
            synchronized(btLock) { btDevices.clear() }
            val gl = PaxGLComm.getInstance(ctx)
            val scanner = if (useBle) gl.getBleScanner() else gl.getBtScanner()
            btScanner = scanner
            scanner.start(
                object : IBtScanner.IBtScannerListener {
                    override fun onDiscovered(device: IBtScanner.IBtDevice?) {
                        val dev = device ?: return
                        val mac = dev.getIdentifier() ?: return
                        synchronized(btLock) {
                            btDevices[mac] = BtDev(dev.getName() ?: "", mac, dev.getRSSI())
                        }
                    }

                    override fun onFinished() {}
                },
                if (timeout > 0) timeout else 1000,
            )
            promise.resolve(true)
        } catch (e: Exception) {
            promise.reject("BT_SEARCH_ERROR", e)
        }
    }

    /** Dừng quét Bluetooth và xoá list nội bộ. */
    @ReactMethod
    fun stopBluetoothSearch(promise: Promise) {
        try {
            btScanner?.stop()
            btScanner = null
            synchronized(btLock) { btDevices.clear() }
            promise.resolve(true)
        } catch (e: Exception) {
            promise.reject("BT_STOP_ERROR", e)
        }
    }

    /**
     * Trả về list thiết bị Bluetooth đã phát hiện kể từ [startBluetoothSearch].
     * Mỗi phần tử: { name, mac, rssi }. UI poll định kỳ (vd mỗi 1s) rồi tap chọn `mac`.
     */
    @ReactMethod
    fun getBluetoothDeviceList(promise: Promise) {
        try {
            val arr = Arguments.createArray()
            synchronized(btLock) {
                btDevices.values.forEach { d ->
                    val m = Arguments.createMap()
                    m.putString("name", d.name)
                    m.putString("mac", d.mac)
                    m.putInt("rssi", d.rssi)
                    arr.pushMap(m)
                }
            }
            promise.resolve(arr)
        } catch (e: Exception) {
            promise.reject("BT_LIST_ERROR", e)
        }
    }

    /**
     * Kết nối USB — phần connect dùng chung luồng [finalizeTerminal] như mọi kiểu khác.
     * USB chỉ khác ở quyền runtime: nếu đã có quyền thì kết nối luôn; nếu chưa thì
     * **tự động bật dialog xin quyền** và chỉ kết nối khi user cấp (onGranted),
     * user từ chối thì reject `USB_PERMISSION_DENIED`.
     *
     * Ngoài ra app vẫn có thể chủ động gọi [requestUsbPermission] để xin quyền trước.
     */
    private fun connectUsb(
        timeout: Int,
        deviceName: String?,
        promise: Promise,
    ) {
        val ctx = reactContext?.currentActivity ?: reactContext
        if (ctx == null) {
            promise.reject("NO_CONTEXT", "No available activity/context for USB connection")
            return
        }

        // Build setting + đẩy qua luồng kết nối chung.
        fun doConnect() {
            val usbSetting =
                UsbSetting().apply {
                    this.timeout = timeout
                    if (!deviceName.isNullOrEmpty()) this.deviceName = deviceName
                }
            val usbSettingInfo = "=>: type=USB, deviceName=${usbSetting.deviceName ?: ""}, timeout=${usbSetting.timeout}"
            Log.i("UsbSetting", usbSettingInfo)
            finalizeTerminal(usbSetting, usbSettingInfo, timeout, promise)
        }

        // Đã có quyền → kết nối luôn.
        if (USBUtil.hasPermission(ctx)) {
            doConnect()
            return
        }

        // Không có thiết bị USB → dialog không bật, callback không fire → sẽ treo.
        // Reject rõ ràng thay vì chờ vô hạn.
        if (USBUtil.getDevices(ctx).isEmpty()) {
            promise.reject("NO_USB_DEVICE", "Không tìm thấy thiết bị USB nào đang cắm.")
            return
        }

        // Chưa có quyền → tự bật dialog, chỉ kết nối khi user cấp quyền.
        try {
            USBUtil.registerPermissionGrantBroadcast(
                ctx,
                object : USBUtil.UsbPermissionCallback {
                    override fun onGranted(device: UsbDevice?) {
                        doConnect()
                    }

                    override fun onFail() {
                        Log.d("Failed Init", "USB permission denied")
                        promise.reject("USB_PERMISSION_DENIED", "USB permission denied by user")
                    }
                },
                null,
            )
            USBUtil.requestUSBPermissionIfNeed(ctx)
        } catch (e: Exception) {
            promise.reject("INIT_USB_ERROR", e)
        }
    }

    @ReactMethod
    fun payment(
        data: ReadableMap,
        promise: Promise,
    ) {
        val salesRequest =
            PaxRequestModel(
                id = data.getString("transactionId") ?: data.getString("id"),
                amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getInt("amount") ?: 0,
                tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                ecrRefNum = data.getString("ecrRefNum") ?: "",
                showTip = data.takeIf { it.hasKey("showTip") && !it.isNull("showTip") }?.getBoolean("showTip") ?: false,
            )

        Thread {
            this.salesRequest = salesRequest
            if (terminal == null) {
                promise.reject("NO_TERMINAL", "Please connect PAX terminal first")
                return@Thread
            }

            try {
                when (salesRequest.paymentType) {
                    CreditTransactionType.Credit.code -> {
                        val result = paymentCredit(salesRequest)
                        promise.resolve(result.toWritableMap())
                    }
                    CreditTransactionType.Debit.code -> {
                        val result = paymentDebit(salesRequest)
                        promise.resolve(result.toWritableMap())
                    }
                    else -> {
                        promise.reject("INVALID_TYPE", "Please select transaction command (credit/ debit)!")
                        return@Thread
                    }
                }
            } catch (e: Exception) {
                promise.reject("PAYMENT_ERROR", e.message, e)
            }
        }.start()
    }

    private fun PaxResponseModel.toWritableMap(): WritableMap {
        val map = Arguments.createMap()
        map.putBoolean("status", this.status)
        map.putString("message", this.message)
        this.data?.let { map.putMap("data", it) } ?: map.putNull("data")
        map.putBoolean("isPaymentSuccess", this.isPaymentSuccess)
        map.putString("execCode", this.execCode)
        map.putString("execMessage", this.execMessage)
        map.putString("responseCode", this.responseCode)
        map.putString("responseMessage", this.responseMessage)
        map.putString("hostResponseCode", this.hostResponseCode)
        map.putString("hostResponseMessage", this.hostResponseMessage)
        map.putString("issuerResponseCode", this.issuerResponseCode)
        map.putString("cardHolder", this.cardHolder)
        map.putString("cardNumber", this.cardNumber)
        map.putString("refNum", this.refNum)
        map.putString("ecrRefNum", this.ecrRefNum)
        map.putString("transactionId", this.transactionId)
        map.putString("transactionDateTime", this.transactionDateTime)
        map.putString("entryMethod", this.entryMethod)
        map.putString("amount", this.amount)
        map.putString("tipAmount", this.tipAmount)
        map.putString("surcharge", this.surcharge)
        map.putString("cardType", this.cardType)
        map.putMap("sn", this.sn)
        return map
    }

    private fun PaxTerminalInfoModel.toWritableMap(): WritableMap {
        val map = Arguments.createMap()
        map.putString("serialNumber", this.serialNumber)
        map.putString("appName", this.appName)
        map.putString("modelName", this.modelName)
        return map
    }

    private fun paymentCredit(request: PaxRequestModel): PaxResponseModel {
        this.salesRequest = request
        val req = setCreditRequest(TransactionType.SALE)
        val rsp = DoCreditResponse()
        val result = terminal?.transaction?.doCredit(req)
        return buildTransactionResponse(rsp, result)
    }

    private fun paymentDebit(request: PaxRequestModel): PaxResponseModel {
        this.salesRequest = request
        val req = setDebitRequest(TransactionType.SALE)
        val result = terminal?.transaction?.doDebit(req)
        return buildDebitTransactionResponse(result)
    }

    @RequiresApi(Build.VERSION_CODES.O)
    @ReactMethod
    fun checkVoidOrRefundTransaction(
        ercRefNum: String?,
        promise: Promise,
    ) {
        Thread {
            try {
                val transaction =
                    LocalDetailReportRequest().apply {
                        this.ecrReferenceNumber = ercRefNum
                        this.edcType = EdcType.ALL
                    }
                val result = terminal?.report?.localDetailReport(transaction)
                val map: WritableMap = Arguments.createMap()
                map.putString("code", result?.code().toString())
                map.putString("message", result?.message().toString())
                map.putString("status", result?.response()?.responseMessage())
                map.putMap("serialNumber", getTerminalInfo())
                promise.resolve(map)
            } catch (e: Exception) {
                promise.reject("CHECK_STATUS_ERROR", e.message, e)
            }
        }.start()
    }

    @ReactMethod
    fun voidTransaction(
        data: ReadableMap,
        promise: Promise,
    ) {
        println("Received data void1: ${data.toHashMap()}")
        Thread {
            try {
                val salesRequest =
                    PaxRequestModel(
                        id = data.getString("transactionId") ?: data.getString("id"),
                        amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getDouble("amount")?.let { Math.round(it).toInt() } ?: 0,
                        tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                        paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                        ecrRefNum = data.getString("ecrRefNum") ?: "",
                    )
                this.salesRequest = salesRequest
                val req = setCreditRequest(TransactionType.VOID_SALE)
                val rsp = DoCreditResponse()
                val result = terminal?.transaction?.doCredit(req)
                val data = buildTransactionResponse(rsp, result)
                promise.resolve(data.toWritableMap())
            } catch (e: Exception) {
                promise.reject("VOID_ERROR", e.message, e)
            }
        }.start()
    }

    @ReactMethod
    fun voidRefund(
        data: ReadableMap,
        promise: Promise,
    ) {
        println("Received data voidRefund1: ${data.toHashMap()}")

        Thread {
            try {
                val salesRequest =
                    PaxRequestModel(
                        id = data.getString("transactionId") ?: data.getString("id"),
                        amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getDouble("amount")?.let { Math.round(it).toInt() } ?: 0,
                        tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                        paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                        ecrRefNum = data.getString("ecrRefNum") ?: "",
                    )
                this.salesRequest = salesRequest
                val req = setCreditRequest(TransactionType.VOID_SALE)
                val rsp = DoCreditResponse()
                val result = terminal?.transaction?.doCredit(req)
                val data = buildTransactionResponse(rsp, result)
                promise.resolve(data.toWritableMap())
            } catch (e: Exception) {
                promise.reject("VOID_REFUND_ERROR", e.message, e)
            }
        }.start()
    }

    @ReactMethod
    fun refund(
        data: ReadableMap,
        promise: Promise,
    ) {
        println("Received data refund1: ${data.toHashMap()}")
        Thread {
            try {
                val salesRequest =
                    PaxRequestModel(
                        id = data.getString("transactionId") ?: data.getString("id"),
                        amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getDouble("amount")?.let { Math.round(it).toInt() } ?: 0,
                        tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                        paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                        ecrRefNum = data.getString("ecrRefNum") ?: "",
                    )
                this.salesRequest = salesRequest
                val req = setCreditRequest(TransactionType.RETURN)
                val rsp = DoCreditResponse()
                val result = terminal?.transaction?.doCredit(req)
                val data = buildTransactionResponse(rsp, result)
                promise.resolve(data.toWritableMap())
            } catch (e: Exception) {
                promise.reject("REFUND_ERROR", e.message, e)
            }
        }.start()
    }

    @ReactMethod
    fun batchCloseout(promise: Promise) {
        Thread {
            try {
                val batchCloseReq = BatchCloseRequest()
                val result = terminal?.batch?.batchClose(batchCloseReq)
                val paxResponse = buildBatchCloseResponse(result)
                promise.resolve(paxResponse.toWritableMap())
            } catch (e: Exception) {
                promise.reject("BATCH_CLOSE_ERROR", e.message, e)
            }
        }.start()
    }

    @ReactMethod
    fun getBatchInformation(promise: Promise) {
        Thread {
            try {
                val map = Arguments.createMap()
                val request = HistoryReportRequest()
                val result = terminal?.report?.historyReport(request)
                if (result?.code() == ExecutionCode.OK) {
                    val rsp = result.response()
                    map.putBoolean("status", true)
                    map.putInt("ecrReferenceNumber", getBatchStartDate())
                    map.putInt("totalRecord", getTotalTransactionCount())
                    map.putInt("totalAmount", getTotalTransactionAmount())
                    map.putBoolean("status", true)
                    map.putString("message", rsp?.responseMessage() ?: "Success")
                    map.putMap("data", convertHistoryReportResponseToMap(rsp))
                    promise.resolve(map)
                } else {
                    promise.reject("GET_BATCH_INFORMATION_FAILED", result?.message() ?: "Failed to get batch info")
                }
            } catch (e: Exception) {
                promise.reject("GET_BATCH_INFORMATION_ERROR", e.message, e)
            }
        }.start()
    }

    private fun convertHistoryReportResponseToMap(rsp: HistoryReportResponse?): WritableMap {
        val map = Arguments.createMap()
        if (rsp == null) return map
        map.putString("batchNumber", rsp.batchNumber())
        map.putString("timeStamp", rsp.timeStamp())

        rsp.edcTotalCount()?.let {
            val countMap = Arguments.createMap()
            countMap.putString("creditCount", it.creditCount())
            countMap.putString("debitCount", it.debitCount())
            countMap.putString("ebtCount", it.ebtCount())
            countMap.putString("giftCount", it.giftCount())
            countMap.putString("loyaltyCount", it.loyaltyCount())
            countMap.putString("cashCount", it.cashCount())
            map.putMap("totalCount", countMap)
        }

        rsp.edcTotalAmount()?.let {
            val amountMap = Arguments.createMap()
            amountMap.putString("creditAmount", it.creditAmount())
            amountMap.putString("debitAmount", it.debitAmount())
            amountMap.putString("ebtAmount", it.ebtAmount())
            amountMap.putString("giftAmount", it.giftAmount())
            amountMap.putString("loyaltyAmount", it.loyaltyAmount())
            amountMap.putString("cashAmount", it.cashAmount())
            map.putMap("totalAmount", amountMap)
        }
        return map
    }

    @ReactMethod
    fun cancelTransaction(promise: Promise) {
        Thread {
            try {
                terminal?.cancel()
                promise.resolve("Cancel transaction requested")
            } catch (e: Exception) {
                promise.reject("CANCEL_FAILED", e.message, e)
            }
        }.start()
    }

//    fun voidOrRefundTransaction(startDate: Int, serialNumber: String): String {
//        if (startDate == 0) return ""
//        val batchStartDate = getBatchStartDate()
//        if (batchStartDate == 0 || startDate < batchStartDate) return "Refund"
//        return if (getTerminalInfo()?.serialNumber != serialNumber) "" else "Void"
//    }
    private fun setCreditRequest(type: TransactionType): DoCreditRequest =
        DoCreditRequest().apply {
            transactionType = type
            amountInformation = getAmountReq(type)
            traceInformation = getTraceReq(type)
            transactionBehavior = getTransactionBehaviorReq()
        }

    private fun setDebitRequest(type: TransactionType): DoDebitRequest =
        DoDebitRequest().apply {
            transactionType = type
            amountInformation = getAmountReq(type)
            traceInformation = getTraceReq(type)
            transactionBehavior = getTransactionBehaviorReq()
        }

    private fun buildBatchCloseResponse(result: ExecutionResult<BatchCloseResponse>?): PaxResponseModel {
        val rsp = result?.response()
        return if (result?.code() == ExecutionCode.OK) {
            PaxResponseModel().apply {
                status = true
                data = convertBatchCloseResponseToMap(rsp)
                message = rsp?.responseMessage() ?: "Batch close successfully"
                isPaymentSuccess = true
                sn = getTerminalInfo()
                refNum = rsp?.hostInformation()?.batchNumber() ?: ""
                transactionDateTime = rsp?.timeStamp().orEmpty()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), rsp?.hostInformation())
            }
        } else {
            PaxResponseModel().apply {
                status = false
                message = result?.message() ?: "Batch close error"
                sn = getTerminalInfo()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), rsp?.hostInformation())
            }
        }
    }

    private fun convertBatchCloseResponseToMap(rsp: BatchCloseResponse?): WritableMap {
        val map = Arguments.createMap()
        if (rsp == null) return map

        map.putString("responseCode", rsp.responseCode())
        map.putString("responseMessage", rsp.responseMessage())
        map.putString("tid", rsp.tid())
        map.putString("mid", rsp.mid())
        map.putString("timeStamp", rsp.timeStamp())
        map.putString("failedCount", rsp.failedCount())
        map.putString("failedTransactionNumber", rsp.failedTransactionNumber())
        map.putString("safFailedCount", rsp.safFailedCount())
        map.putString("safFailedTotal", rsp.safFailedTotal())

        rsp.hostInformation()?.let {
            val hostMap = Arguments.createMap()
            hostMap.putString("hostResponseCode", it.hostResponseCode())
            hostMap.putString("hostResponseMessage", it.hostResponseMessage())
            hostMap.putString("authorizationCode", it.authorizationCode())
            hostMap.putString("hostReferenceNumber", it.hostReferenceNumber())
            hostMap.putString("batchNumber", it.batchNumber())
            hostMap.putString("gatewayTransactionId", it.gatewayTransactionId())
            hostMap.putString("hostDetailedMessage", it.hostDetailedMessage())
            hostMap.putString("transactionIntegrityClass", it.transactionIntegrityClass())
            hostMap.putString("retrievalReferenceNumber", it.retrievalReferenceNumber())
            hostMap.putString("issuerResponseCode", it.issuerResponseCode())
            hostMap.putString("paymentAccountReferenceId", it.paymentAccountReferenceId())
            map.putMap("hostInformation", hostMap)
        }

        rsp.totalCount()?.let {
            val countMap = Arguments.createMap()
            countMap.putString("creditCount", it.creditCount())
            countMap.putString("debitCount", it.debitCount())
            countMap.putString("ebtCount", it.ebtCount())
            countMap.putString("giftCount", it.giftCount())
            countMap.putString("loyaltyCount", it.loyaltyCount())
            countMap.putString("cashCount", it.cashCount())
            map.putMap("totalCount", countMap)
        }

        rsp.totalAmount()?.let {
            val amountMap = Arguments.createMap()
            amountMap.putString("creditAmount", it.creditAmount())
            amountMap.putString("debitAmount", it.debitAmount())
            amountMap.putString("ebtAmount", it.ebtAmount())
            amountMap.putString("giftAmount", it.giftAmount())
            amountMap.putString("loyaltyAmount", it.loyaltyAmount())
            amountMap.putString("cashAmount", it.cashAmount())
            map.putMap("totalAmount", amountMap)
        }

        // torInformation - mapping it as an array as requested by user ("list")
        // Even if SDK returns single, wrapping in array for flexibility if user expects a list
        val torArray = Arguments.createArray()
        val tor = rsp.torInformation()
        if (tor != null) {
            convertTorResponseToMap(tor, torArray)
        }
        map.putArray("torInformation", torArray)

        return map
    }

    private fun convertTorResponseToMap(
        tor: TorResponse,
        torArray: WritableArray,
    ) {
        val map = Arguments.createMap()
        map.putString("batchNumber", tor.batchNumber())
        map.putString("gatewayTransactionId", tor.gatewayTransactionId())
        map.putString("hostReferenceNumber", tor.hostReferenceNumber().toString())
        map.putString("hostResponseCode", tor.hostResponseCode())
        map.putString("hostResponseMessage", tor.hostResponseMessage())
        map.putString("maskedPan", tor.maskedPan())
        map.putString("originalAmount", tor.originalAmount())
        map.putString("originalTransactionAuthorizationCode", tor.originalTransactionAuthorizationCode())
        map.putString("originalTransactionDateTime", tor.originalTransactionDateTime())
        map.putString("originalTransactionType", tor.originalTransactionType()?.name)
        map.putString("recordType", tor.recordType()?.name)
        map.putString("reversalAuthorizationCode", tor.reversalAuthorizationCode())
        map.putString("reversalTimeStamp", tor.reversalTimeStamp())

        torArray.pushMap(map)
    }

    /* Không còn dùng — đã bỏ field "data" lồng khỏi response giao dịch. Giữ lại để tham khảo.
    private fun convertDoCreditResponseToMap(rsp: DoCreditResponse?): WritableMap {
        val map = Arguments.createMap()
        if (rsp == null) return map

        map.putString("responseCode", rsp.responseCode())
        map.putString("responseMessage", rsp.responseMessage())
        map.putString(
            "entryMethod",
            rsp.paymentEmvTag()?.let { emv ->
                rsp.accountInformation()?.let { getEntryMethod(it, emv) }
            },
        )

        // accountInformation
        val acc = rsp.accountInformation()
        val accMap =
            Arguments.createMap().apply {
                putString("account", acc?.account())
                putString("cardHolder", acc?.cardHolder())
                putString("cardExpireDate", acc?.expireDate())
            }
        map.putMap("accountInformation", accMap)

        // traceInformation
        val trace = rsp.traceInformation()
        val traceMap =
            Arguments.createMap().apply {
                putString("referenceNumber", trace?.referenceNumber())
                putString("ecrReferenceNumber", trace?.ecrReferenceNumber())
                putString("timeStamp", trace?.timeStamp())
                putString("authorizationCode", rsp.hostInformation()?.authorizationCode())
            }
        map.putMap("traceInformation", traceMap)

        // amountInformation
        val amount = rsp.amountInformation()
        val amountMap =
            Arguments.createMap().apply {
                putString("transactionAmount", amount?.transactionRemainingAmount())
                putString("tipAmount", amount?.tipAmount())
                putString("merchantFee", amount?.merchantFee())
            }
        map.putMap("amountInformation", amountMap)

        // transactionId
        val trans = rsp.paymentTransactionInformation()
        map.putString("transactionId", trans?.globalUid())

        // avsInformation
        val avs = rsp.avsInformation()
        val avsMap =
            Arguments.createMap().apply {
                putString("zipCode", avs?.zipCode())
                putString("address", avs?.address1())
            }
        map.putMap("avsInformation", avsMap)

        // cardInformation
        val card = rsp.cardInformation()
        val cardMap =
            Arguments.createMap().apply {
                putString("cardType", card?.cardBin())
            }
        map.putMap("cardInformation", cardMap)

        // commercialInformation
        val commercial = rsp.commercialInformation()
        val commMap =
            Arguments.createMap().apply {
                putString("poNumber", commercial?.poNumber())
            }
        map.putMap("commercialInformation", commMap)

        // fleetCard
        val fleet = rsp.fleetCard()
        val fleetMap =
            Arguments.createMap().apply {
                putString("vehicleNumber", fleet?.vehicleNumber())
            }
        map.putMap("fleetCard", fleetMap)

        // multiMerchant
        val multi = rsp.multiMerchant()
        val multiMap =
            Arguments.createMap().apply {
                putString("multiMerchantId", multi?.multiMerchantId)
                putString("multiMerchantName", multi?.multiMerchantName)
            }
        map.putMap("multiMerchant", multiMap)

        // restaurant
        val restaurant = rsp.restaurant()
        val restMap =
            Arguments.createMap().apply {
                putString("tableNumber", restaurant?.tableNumber)
                putString("ticketNumber", restaurant?.ticketNumber)
            }
        map.putMap("restaurant", restMap)

        // emv
        val emv = rsp.paymentEmvTag()
        val emvMap =
            Arguments.createMap().apply {
                putString("emvLabel", emv.appLabel())
                putString("emvPreferName", emv.appPreferName())
            }
        map.putMap("emv", emvMap)

        return map
    }
    */

    /**
     * Gắn các mã gốc (raw codes) vào response để bên JS tự phân loại lỗi.
     * Native KHÔNG phân loại — chỉ báo cáo trung thực mọi mã/message từ SDK, terminal và host.
     */
    private fun PaxResponseModel.applyRawCodes(
        result: ExecutionResult<*>?,
        responseCode: String?,
        responseMessage: String?,
        host: HostInformationResponse?,
    ) {
        execCode = result?.code()?.name ?: "ERROR"
        execMessage = result?.message().orEmpty()
        this.responseCode = responseCode.orEmpty()
        this.responseMessage = responseMessage.orEmpty()
        hostResponseCode = host?.hostResponseCode().orEmpty()
        hostResponseMessage = host?.hostResponseMessage().orEmpty()
        issuerResponseCode = host?.issuerResponseCode().orEmpty()
    }

    private fun buildTransactionResponse(
        response: DoCreditResponse,
        result: ExecutionResult<DoCreditResponse>?,
    ): PaxResponseModel {
        val rsp = result?.response()
        return if (result?.code() == ExecutionCode.OK) {
            PaxResponseModel().apply {
                status = true
                message = rsp?.responseMessage().orEmpty()
                isPaymentSuccess = true
                cardHolder = rsp?.accountInformation()?.cardHolder().orEmpty()
                cardNumber = rsp?.accountInformation()?.account().orEmpty()
                cardType =
                    rsp
                        ?.paymentEmvTag()
                        ?.appLabel()
                        .orEmpty()
                        .uppercase()
                refNum = rsp?.traceInformation()?.referenceNumber().orEmpty()
                ecrRefNum = rsp?.traceInformation()?.ecrReferenceNumber().orEmpty()
                transactionId = rsp?.paymentTransactionInformation()?.globalUid().orEmpty()
                transactionDateTime = rsp?.traceInformation()?.timeStamp().orEmpty()
                entryMethod =
                    (
                        rsp
                            ?.paymentEmvTag()
                            ?.let { rsp.accountInformation()?.let { it1 -> getEntryMethod(it1, it) } }
                    ).orEmpty()
                tipAmount = rsp?.amountInformation()?.tipAmount().orEmpty()
                amount = salesRequest?.amount?.toString().orEmpty()
                id = salesRequest?.id.orEmpty()
                surcharge = rsp?.amountInformation()?.merchantFee().orEmpty()
                sn = getTerminalInfo()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), rsp?.hostInformation())
            }
        } else {
            val host = rsp?.hostInformation()
            PaxResponseModel().apply {
                status = false
                isPaymentSuccess = false
                // Lấy message lỗi THẬT theo thứ tự ưu tiên (không tạo object rỗng mới)
                message =
                    rsp?.responseMessage()
                        ?: host?.hostResponseMessage()
                        ?: result?.message()
                        ?: "Transaction failed"
                ecrRefNum = salesRequest?.ecrRefNum.orEmpty()
                id = salesRequest?.id.orEmpty()
                sn = getTerminalInfo()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), host)
            }
        }
    }

    /* Không còn dùng — đã bỏ field "data" lồng khỏi response giao dịch. Giữ lại để tham khảo.
    private fun convertDoDebitResponseToMap(rsp: DoDebitResponse?): WritableMap {
        val map = Arguments.createMap()
        if (rsp == null) return map

        map.putString("responseCode", rsp.responseCode())
        map.putString("responseMessage", rsp.responseMessage())
        map.putString(
            "entryMethod",
            rsp.paymentEmvTag()?.let { emv ->
                rsp.accountInformation()?.let { getEntryMethod(it, emv) }
            },
        )

        // accountInformation
        val acc = rsp.accountInformation()
        val accMap =
            Arguments.createMap().apply {
                putString("account", acc?.account())
                putString("cardHolder", acc?.cardHolder())
                putString("cardExpireDate", acc?.expireDate())
            }
        map.putMap("accountInformation", accMap)

        // traceInformation
        val trace = rsp.traceInformation()
        val traceMap =
            Arguments.createMap().apply {
                putString("referenceNumber", trace?.referenceNumber())
                putString("ecrReferenceNumber", trace?.ecrReferenceNumber())
                putString("timeStamp", trace?.timeStamp())
                putString("authorizationCode", rsp.hostInformation()?.authorizationCode())
            }
        map.putMap("traceInformation", traceMap)

        // amountInformation
        val amount = rsp.amountInformation()
        val amountMap =
            Arguments.createMap().apply {
                putString("transactionAmount", amount?.transactionRemainingAmount())
                putString("tipAmount", amount?.tipAmount())
                putString("merchantFee", amount?.merchantFee())
            }
        map.putMap("amountInformation", amountMap)

        // transactionId
        val trans = rsp.paymentTransactionInformation()
        map.putString("transactionId", trans?.globalUid())

        // cardInformation
        val card = rsp.cardInformation()
        val cardMap =
            Arguments.createMap().apply {
                putString("cardType", card?.cardBin())
            }
        map.putMap("cardInformation", cardMap)

        // fleetCard
        val fleet = rsp.fleetCard()
        val fleetMap =
            Arguments.createMap().apply {
                putString("vehicleNumber", fleet?.vehicleNumber())
            }
        map.putMap("fleetCard", fleetMap)

        // multiMerchant
        val multi = rsp.multiMerchant()
        val multiMap =
            Arguments.createMap().apply {
                putString("multiMerchantId", multi?.multiMerchantId)
                putString("multiMerchantName", multi?.multiMerchantName)
            }
        map.putMap("multiMerchant", multiMap)

        // restaurant
        val restaurant = rsp.restaurant()
        val restMap =
            Arguments.createMap().apply {
                putString("tableNumber", restaurant?.tableNumber)
                putString("ticketNumber", restaurant?.ticketNumber)
            }
        map.putMap("restaurant", restMap)

        // emv
        val emv = rsp.paymentEmvTag()
        val emvMap =
            Arguments.createMap().apply {
                putString("emvLabel", emv.appLabel())
                putString("emvPreferName", emv.appPreferName())
            }
        map.putMap("emv", emvMap)

        return map
    }
    */

    private fun buildDebitTransactionResponse(result: ExecutionResult<DoDebitResponse>?): PaxResponseModel {
        val rsp = result?.response()
        return if (result?.code() == ExecutionCode.OK) {
            PaxResponseModel().apply {
                status = true
                message = rsp?.responseMessage().orEmpty()
                isPaymentSuccess = true
                cardHolder = rsp?.accountInformation()?.cardHolder().orEmpty()
                cardNumber = rsp?.accountInformation()?.account().orEmpty()
                cardType =
                    rsp
                        ?.paymentEmvTag()
                        ?.appLabel()
                        .orEmpty()
                        .uppercase()
                refNum = rsp?.traceInformation()?.referenceNumber().orEmpty()
                ecrRefNum = rsp?.traceInformation()?.ecrReferenceNumber().orEmpty()
                transactionId = rsp?.paymentTransactionInformation()?.globalUid().orEmpty()
                transactionDateTime = rsp?.traceInformation()?.timeStamp().orEmpty()
                entryMethod =
                    (
                        rsp
                            ?.paymentEmvTag()
                            ?.let { rsp.accountInformation()?.let { it1 -> getEntryMethod(it1, it) } }
                    ).orEmpty()
                tipAmount = rsp?.amountInformation()?.tipAmount().orEmpty()
                amount = salesRequest?.amount?.toString().orEmpty()
                id = salesRequest?.id.orEmpty()
                surcharge = rsp?.amountInformation()?.merchantFee().orEmpty()
                sn = getTerminalInfo()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), rsp?.hostInformation())
            }
        } else {
            val host = rsp?.hostInformation()
            PaxResponseModel().apply {
                status = false
                isPaymentSuccess = false
                message =
                    rsp?.responseMessage()
                        ?: host?.hostResponseMessage()
                        ?: result?.message()
                        ?: "Transaction failed"
                ecrRefNum = salesRequest?.ecrRefNum.orEmpty()
                id = salesRequest?.id.orEmpty()
                sn = getTerminalInfo()
                applyRawCodes(result, rsp?.responseCode(), rsp?.responseMessage(), host)
            }
        }
    }

    private fun getEntryMethod(
        accountRsp: AccountResponse,
        paymentEmvTag: PaymentEmvTag,
    ): String {
        val temp = accountRsp.entryMode() ?: return ""

        return when (temp) {
            EntryMode.MANUAL -> {
                if (accountRsp.cardPresentIndicator() === CardPresentIndicator.CARD_NOT_PRESENT) {
                    "KEYED_CNP"
                } else {
                    "KEYED_CP"
                }
            }
            EntryMode.SWIPE -> "SWIPED_MSD"
            EntryMode.CONTACTLESS -> {
                if (!paymentEmvTag.tc().isNullOrEmpty()) {
                    "CONTACTLESS_CHIP"
                } else {
                    "CONTACTLESS_MSD"
                }
            }
            EntryMode.LASER_SCANNER -> "SCANNER"
            EntryMode.CHIP -> "CONTACT_CHIP"
            EntryMode.CHIP_FALL_BACK_SWIPE -> "FALLBACK_SWIPED"
            else -> ""
        }
    }

    private fun getTotalTransactionCount(): Int {
        try {
            val request = LocalDetailReportRequest().apply { edcType = EdcType.ALL }
            val result = terminal?.report?.localDetailReport(request)
            return if (result?.code() == ExecutionCode.OK) {
                result.response().totalRecord()?.toIntOrNull() ?: 0
            } else {
                0
            }
        } catch (e: Exception) {
            throw Exception("Error totalTransactionCount: ${e.message}")
        }
    }

    private fun getTotalTransactionAmount(): Int {
        try {
            val request = LocalTotalReportRequest().apply { edcType = EdcType.ALL }
            val result = terminal?.report?.localTotalReport(request)
            return if (result?.code() == ExecutionCode.OK) {
                val totals = result.response().totals()
                val creditSale = totals.creditTotals().saleAmount().toIntOrNull() ?: 0
                val creditRefund = totals.creditTotals().returnAmount().toIntOrNull() ?: 0
                val debitSale = totals.debitTotals().saleAmount().toIntOrNull() ?: 0
                val debitRefund = totals.debitTotals().returnAmount().toIntOrNull() ?: 0
                (creditSale - creditRefund) + (debitSale - debitRefund)
            } else {
                0
            }
        } catch (e: Exception) {
            throw Exception("Error totalTransactionAmount: ${e.message}")
        }
    }

    private fun getBatchStartDate(): Int {
        try {
            val request = LocalDetailReportRequest().apply { edcType = EdcType.ALL }
            val result = terminal?.report?.localDetailReport(request)
            return if (result?.code() == ExecutionCode.OK) {
                result
                    .response()
                    .traceInformation()
                    .ecrReferenceNumber()
                    .toIntOrNull() ?: 0
            } else {
                0
            }
        } catch (e: Exception) {
            throw Exception("Error batchStartDate: ${e.message}")
        }
    }

    private fun getTerminalInfo(): WritableMap =
        try {
            val initResult = terminal?.manage?.init()
            val response = initResult?.response()
            if (response == null) {
                PaxTerminalInfoModel().toWritableMap()
            } else {
                PaxTerminalInfoModel(
                    serialNumber = response.sn().orEmpty(),
                    modelName = response.modelName().orEmpty(),
                    appName = response.appName().orEmpty(),
                ).toWritableMap()
            }
        } catch (e: Exception) {
            PaxTerminalInfoModel().toWritableMap()
        }

    private fun getAmountReq(transType: TransactionType?): AmountRequest =
        AmountRequest().apply {
            transactionAmount = salesRequest?.amount?.toString()
            tipAmount = salesRequest?.tip?.takeIf { it > 0 }?.toString()
            cashBackAmount = null
            merchantFee = null
            taxAmount = null
            fuelAmount = null
            serviceFee = null
            // SDK khởi tạo originalAmount = "" → packer V2.02.00 reject. Phải ép null.
            originalAmount = null
        }

    private fun getAccountReq() =
        AccountRequest().apply {
            account = null
            cardExpireDate = null
            cvvCode = null
            ebtType = null
            voucherNumber = null
            firstName = null
            lastName = null
            countryCode = null
            stateCode = null
            cityName = null
            emailAddress = null
            giftCardType = null
            cvvBypassReason = null
            giftTenderType = null
        }

    private fun getTraceReq(transType: TransactionType): TraceRequest =
        TraceRequest().apply {
            val ecrRefNum = salesRequest?.ecrRefNum
            ecrRefNum?.let {
                this.ecrReferenceNumber =
                    if (transType in listOf(TransactionType.SALE, TransactionType.VOID_SALE, TransactionType.RETURN)) it else null
                this.originalEcrReferenceNumber = if (transType == TransactionType.VOID_SALE) it else null
            }
            invoiceNumber = null
            originalReferenceNumber = null
            timeStamp = null
            // SDK khởi tạo các field này = "" → packer V2.02.00 reject. Phải ép null.
            globalUid = null
            originalTransactionDate = null
            originalTransactionTime = null
        }

    private fun getAvsReq() =
        AvsRequest().apply {
            zipCode = null
            address = null
            address2 = null
        }

    private fun getCashierReq() =
        CashierRequest().apply {
            clerkId = null
            shiftId = null
        }

    private fun getCommercialReq() =
        CommercialRequest().apply {
            poNumber = null
            customerCode = null
            taxExempt = null
            taxExemptId = null
            merchantTaxId = null
            destinationZipCode = null
            productDescription = null
            shipFromZipCode = null
            destinationCountryCode = null
            summaryCommodityCode = null
            discountAmount = null
            freightAmount = null
            dutyAmount = null
            orderDate = null
            taxDetails = null
            lineItemDetails = null
        }

    private fun getMotoECommerceReq() =
        MotoECommerceRequest().apply {
            mode = null
            transactionType = null
            secureType = null
            orderNumber = null
            installments = null
            currentInstallment = null
        }

    private fun getRestaurantReq() =
        Restaurant().apply {
            tableNumber = null
            guestNumber = null
            ticketNumber = null
        }

    // V2.02.00: HostGateway -> HostInformationRequest. Most legacy gateway/token fields were
    // removed by the SDK; only the fields below remain available.
    private fun getHostInformationReq() =
        HostInformationRequest().apply {
            authorizationCode = null
            returnReason = null
            statementDescriptor = null
            // null thay vì "" — chuỗi rỗng non-null bị packer V2.02.00 đóng gói rồi reject ("Packer error").
            posEchoData = null
        }

    private fun getTransactionBehaviorReq() =
        TransactionBehaviorRequest().apply {
            val tip = salesRequest?.tip
            val showTip = salesRequest?.showTip ?: false
            tipRequestFlag =
                if (showTip) {
                    if (tip != null && tip > 0) {
                        TipRequestFlag.NOT_NEED_ENTER_TIP_ON_TERMINAL
                    } else {
                        TipRequestFlag.NEED_ENTER_TIP_ON_TERMINAL
                    }
                } else {
                    TipRequestFlag.NOT_NEED_ENTER_TIP_ON_TERMINAL
                }
            statusReportFlag = null
            acceptedCardType = null
            programPromptsFlag = null
            entryMode = null
            receiptPrintFlag = ReceiptPrintFlag.NO_RECEIPT
            cardPresentMode = null
            debitNetwork = null
            userLanguage = null
            additionalResponseDataFlag = null
            forceDuplicate = "1"
            accessibilityPinPad = null
//        giftCardIndicator = null
            transactionPromptBitmap = null
            // V2.02.00: continuousScreen moved from DoCredit/DoDebitRequest to TransactionBehaviorRequest.
            // Signature flags (capture/upload/acquire), forceCc/forceFsa and cofIndicator/cofInitiator
            // were removed from the behavior request in this SDK version.
            continuousScreen = ContinuousScreen.NOT_SET
        }

    private fun getOriginalReq() =
        Original().apply {
            transactionDate = null
            pan = null
            expiryDate = null
            transactionTime = null
            amount = null
            transactionType = TransactionType.NOT_SET
        }

    private fun getMultiMerchantReq() =
        MultiMerchant().apply {
            multiMerchantId = null
            multiMerchantName = null
        }

    private fun getFleetCardReq() =
        FleetCardRequest().apply {
            odometer = null
            vehicleNumber = null
            jobNumber = null
            driverId = null
            employeeNumber = null
            licenseNumber = null
            jobId = null
            departmentNumber = null
            customerData = null
            userId = null
            vehicleId = null
            fleetPromptCode = null
        }

    private fun getLodgingInfoReq() =
        Lodging().apply {
            roomNumber = null
            folioNumber = null
            chargeType = null
            noShowFlag = null
            checkInDate = null
            checkOutDate = null
            specialProgramCode = null
            departureAdjustedAmount = null
            roomRates = null
            lodgingItems = null
        }

    private fun getAutoRentalInfoReq() =
        AutoRental().apply {
            agreementNumber = null
            dailyRate = null
            rentalDuration = null
            insuranceAmount = null
            milesAllocated = null
            mileRate = null
            name = null
            driverLicenseNumber = null
            rentalProgramType = null
            pickupLocationName = null
            pickupCity = null
            pickupState = null
            pickupCountryCode = null
            pickupDatetime = null
            returnLocation = null
            returnCity = null
            returnState = null
            returnCountryCode = null
            returnDatetime = null
            totalMiles = null
            customerTaxId = null
            extraChargesAmount = null
            vehicleClassId = VehicleClassId.NOT_SET
            extraChargeItems = null
        }
}
