package com.paxposlink

import android.util.Log
import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.ReadableMap
import com.facebook.react.bridge.WritableMap
import com.pax.poscore.commsetting.TcpSetting
import com.pax.poscore.internal.ExecutionCode
import com.pax.poslinkadmin.ExecutionResult
import com.pax.poslinkadmin.constant.ContinuousScreen
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
import com.pax.poslinksemiintegration.transaction.DoCreditRequest
import com.pax.poslinksemiintegration.transaction.DoCreditResponse
import com.pax.poslinksemiintegration.util.AccountRequest
import com.pax.poslinksemiintegration.util.AccountResponse
import com.pax.poslinksemiintegration.util.AutoRental
import com.pax.poslinksemiintegration.util.AvsRequest
import com.pax.poslinksemiintegration.util.CashierRequest
import com.pax.poslinksemiintegration.util.CheckRequest
import com.pax.poslinksemiintegration.util.CommercialRequest
import com.pax.poslinksemiintegration.util.FleetCardRequest
import com.pax.poslinksemiintegration.util.HostGateway
import com.pax.poslinksemiintegration.util.Lodging
import com.pax.poslinksemiintegration.util.MotoECommerceRequest
import com.pax.poslinksemiintegration.util.Original
import com.pax.poslinksemiintegration.util.PaymentEmvTag
import com.pax.poslinksemiintegration.util.Restaurant
import com.pax.poslinksemiintegration.util.TraceRequest
import com.pax.poslinksemiintegration.util.TransactionBehavior
import com.paxposlink.Utils

class PaxPosLinkModule(
    reactApplicationContext: ReactApplicationContext,
) : ReactContextBaseJavaModule() {
    private var reactContext: ReactApplicationContext? = reactApplicationContext
    private var posLink: POSLinkSemi? = POSLinkSemi.getInstance()
    private var salesRequest: PaxRequestModel? = null
    private var terminal: Terminal? = null

    override fun getName(): String = "PaxPoslink"

    @ReactMethod
    fun logEvent(message: String) {
        Log.d("PaxPosLinkModule", "Log event: $message")
    }

    @ReactMethod
    fun initPOSLink(
        ip: String,
        promise: Promise,
    ) {
        val tcpSetting =
            TcpSetting().apply {
                this.ip = ip
                this.port = PaxPosConstant.PORT
                this.timeout = PaxPosConstant.TIMEOUT
            }
        Log.i("TcpSetting", "tcpSetting info: ip=$ip, port=${tcpSetting.port}, timeout=${tcpSetting.timeout}")
        val map = Arguments.createMap()

        terminal = posLink?.getTerminal(reactContext, tcpSetting)
        Log.e("terminal", terminal.toString())
        return if (terminal != null) {
            Log.d("Success Init", "Create terminal success")
            map.putString("message", "Create terminal success")
            map.putBoolean("status", true)
            promise.resolve(map)
        } else {
            Log.d("Failed Init", "Create terminal failed!")
            map.putString("message", "Create terminal failed!")
            map.putBoolean("status", false)
            promise.resolve(map)
        }
    }

    @ReactMethod
    fun payment(
        data: ReadableMap,
        promise: Promise,
    ) {
        val salesRequest =
            PaxRequestModel(
                id = data.getString("id"),
                amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getInt("amount") ?: 0,
                tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                ecrRefNum = data.getString("ecrRefNum") ?: "",
            )

        this.salesRequest = salesRequest
        if (terminal !== null) {
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
                        return
                    }
                }
            } catch (e: Exception) {
                Log.d("Error", e.toString())
            }
        } else {
            Log.d("Error", "Don't connect")
            promise.reject("NO_TERMINAL", "Please connect PAX terminal first")
        }
    }

    private fun PaxResponseModel.toWritableMap(): WritableMap {
        val map = Arguments.createMap()
        map.putBoolean("status", this.status)
        map.putString("message", this.message)
        map.putMap("data", Utils.toWritableMap(this.data))
        map.putBoolean("isPaymentSuccess", this.isPaymentSuccess)
        map.putString("cardHolder", this.cardHolder)
        map.putString("cardNumber", this.cardNumber)
        map.putString("refNum", this.refNum)
        map.putString("transactionId", this.transactionId)
        map.putString("transactionDateTime", this.transactionDateTime)
        map.putString("entryMethod", this.entryMethod)
        map.putString("amount", this.amount)
        map.putString("tipAmount", this.tipAmount)
        map.putString("surcharge", this.surcharge)
        map.putString("cardType", this.cardType)
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
        val req = setCreditRequest(TransactionType.SALE)
        val rsp = DoCreditResponse()
        val result = terminal?.transaction?.doCredit(req)
        return buildTransactionResponse(rsp, result)
    }

    @ReactMethod
    fun void(
        data: ReadableMap,
        promise: Promise,
    ) {
        try {
            val salesRequest =
                PaxRequestModel(
                    id = data.getString("id"),
                    amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getInt("amount") ?: 0,
                    tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                    paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                    ecrRefNum = data.getString("ecrRefNum") ?: "",
                )
            this.salesRequest = salesRequest
            val req = setCreditRequest(TransactionType.VOID_SALE)
            val rsp = DoCreditResponse()
            val result = terminal?.transaction?.doCredit(req)
            val data = buildTransactionResponse(rsp, result)
            promise.resolve(data)
        } catch (e: Exception) {
            return promise.resolve("Error to void transaction")
        }
    }

    @ReactMethod
    fun refund(
        data: ReadableMap,
        promise: Promise,
    ) {
        try {
            val salesRequest =
                PaxRequestModel(
                    id = data.getString("id"),
                    amount = data.takeIf { it.hasKey("amount") && !it.isNull("amount") }?.getInt("amount") ?: 0,
                    tip = data.takeIf { it.hasKey("tip") && !it.isNull("tip") }?.getInt("tip"),
                    paymentType = data.takeIf { it.hasKey("paymentType") && !it.isNull("paymentType") }?.getInt("paymentType"),
                    ecrRefNum = data.getString("ecrRefNum") ?: "",
                )
            this.salesRequest = salesRequest
            val req = setCreditRequest(TransactionType.RETURN)
            val rsp = DoCreditResponse()
            val result = terminal?.transaction?.doCredit(req)
            val data = buildTransactionResponse(rsp, result)
            promise.resolve(data)
        } catch (e: Exception) {
            return promise.resolve("Error to return transaction")
        }
    }

    @ReactMethod
    fun batchCloseout(promise: Promise) {
        try {
            val batchCloseReq = BatchCloseRequest()
            val batchCloseRsp = BatchCloseResponse()
            val result = terminal?.batch?.batchClose(batchCloseReq)
            if (result?.code() == ExecutionCode.OK) {
                promise.resolve("Batch close successfully")
            }
        } catch (e: Exception) {
            promise.reject("Failed", "Batch close error")
        }
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
            accountInformation = getAccountReq()
            traceInformation = getTraceReq(type)
            avsInformation = getAvsReq()
            cashierInformation = getCashierReq()
            commercialInformation = getCommercialReq()
            motoECommerceInformation = getMotoECommerceReq()
            restaurant = getRestaurantReq()
            hostGateway = getHostGatewayReq()
            transactionBehavior = getTransactionBehaviorReq()
            original = getOriginalReq()
            multiMerchant = getMultiMerchantReq()
            fleetCard = getFleetCardReq()
            lodging = getLodgingInfoReq()
            autoRental = getAutoRentalInfoReq()
            posEchoData = ""
            continuousScreen = ContinuousScreen.NOT_SET
        }

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
                putString("timeStamp", trace?.timeStamp())
                putString("authorizationCode", trace?.authorizationResponse())
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
                putString("vehicleNumber", fleet?.vehicleNumber)
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

    private fun buildTransactionResponse(
        response: DoCreditResponse,
        result: ExecutionResult<DoCreditResponse>?,
    ): PaxResponseModel {
        val rsp = result?.response()
        return if (result?.code() == ExecutionCode.OK) {
            PaxResponseModel().apply {
                status = true
                data = convertDoCreditResponseToMap(rsp)
                message = rsp?.responseMessage().toString()
                isPaymentSuccess = true
                cardHolder = rsp?.accountInformation()?.cardHolder().toString()
                cardNumber = rsp?.accountInformation()?.account().toString()
                cardType =
                    rsp
                        ?.paymentEmvTag()
                        ?.appLabel()
                        .toString()
                        .uppercase()
                refNum = rsp?.traceInformation()?.referenceNumber().toString()
                transactionId = rsp?.paymentTransactionInformation()?.globalUid().toString()
                transactionDateTime = rsp?.traceInformation()?.timeStamp().toString()
                entryMethod =
                    rsp
                        ?.paymentEmvTag()
                        ?.let { rsp.accountInformation()?.let { it1 -> getEntryMethod(it1, it) } }
                        .toString()
                tipAmount = rsp?.amountInformation()?.tipAmount().toString()
                amount = salesRequest?.amount.toString()
                id = salesRequest?.id.toString()
                surcharge = rsp?.amountInformation()?.merchantFee().toString()
            }
        } else {
            PaxResponseModel().apply {
                status = false
                data = null
                message = DoCreditResponse().responseMessage()
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

//    private fun getTotalTransactionCount(): Int {
//        val request = LocalDetailReportRequest().apply { edcType = EdcType.ALL }
//        val response = LocalDetailReportResponse()
//        val result = terminal?.report?.localDetailReport(request)
//        return if (result?.code() == ExecutionCode.OK) {
//            response.totalRecord()?.toIntOrNull() ?: 0
//        } else 0
//    }
//
//    private fun getTotalTransactionAmount(): Int {
//        val request = LocalTotalReportRequest().apply { edcType = EdcType.ALL }
//        val response = LocalTotalReportResponse()
//        val result = terminal?.report?.localTotalReport(request)
//        return if (result?.code() == ExecutionCode.OK) {
//            val sale = response.totals().creditTotals().returnAmount().toIntOrNull() ?: 0
//            val refund = response.totals().creditTotals().returnAmount().toIntOrNull() ?: 0
//            sale - refund
//        } else 0
//    }
//
//    private fun getBatchStartDate(): Int {
//        val request = LocalDetailReportRequest().apply { edcType = EdcType.ALL }
//        val response = LocalDetailReportResponse()
//        val result = terminal?.report?.localDetailReport(request)
//        return if (result?.code() == ExecutionCode.OK) {
//            response.traceInformation().ecrReferenceNumber().toIntOrNull() ?: 0
//        } else 0
//    }

//    private fun getTerminalInfo(): PaxTerminalInfoModel? {
//        return terminal?.manage?.init()?.let {
//            PaxTerminalInfoModel(
//                serialNumber = "",
//                modelName = it.modelName,
//                appName = it.appName
//            )
//
//        }
//    }

    private fun getAmountReq(transType: TransactionType?): AmountRequest =
        AmountRequest().apply {
            transactionAmount = salesRequest?.amount?.toString()
            tipAmount = salesRequest?.tip.toString()
            cashBackAmount = null
            merchantFee = null
            taxAmount = null
            fuelAmount = null
            serviceFee = null
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

    private fun getCheckReq() =
        CheckRequest().apply {
            saleType = null
            routingNumber = null
            account = null
            number = null
            type = null
            idType = null
            idValue = null
            birth = null
            phoneNumber = null
            zipCode = null
        }

    private fun getTraceReq(transType: TransactionType): TraceRequest =
        TraceRequest().apply {
            val ecrRefNum = salesRequest?.ecrRefNum?.split("-")?.firstOrNull()
            ecrRefNum?.let {
                this.ecrReferenceNumber =
                    if (transType in listOf(TransactionType.SALE, TransactionType.VOID_SALE, TransactionType.RETURN)) it else null
                this.originalEcrReferenceNumber = if (transType == TransactionType.VOID_SALE) it else null
            }
            invoiceNumber = null
            authorizationCode = null
            originalReferenceNumber = null
            timeStamp = null
            ecrTransactionId = null
            originalTraceNumber = null
            originalTransactionIdentifier = null
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

    private fun getHostGatewayReq() =
        HostGateway().apply {
            hostReferenceNumber = null
            gatewayId = null
            tokenRequestFlag = null
            token = null
            cardType = null
            passThruData = null
            returnReason = null
            stationId = null
            globalUid = null
            customizeData1 = null
            customizeData2 = null
            customizeData3 = null
            ewicDiscountAmount = null
            tokenSerialNumber = null
        }

    private fun getTransactionBehaviorReq() =
        TransactionBehavior().apply {
            val tip = salesRequest?.tip
            signatureCaptureFlag = null
            tipRequestFlag =
                if (tip != null && tip > 0) TipRequestFlag.NOT_NEED_ENTER_TIP_ON_TERMINAL else TipRequestFlag.NEED_ENTER_TIP_ON_TERMINAL
            signatureUploadFlag = null
            statusReportFlag = null
            acceptedCardType = null
            programPromptsFlag = null
            signatureAcquireFlag = null
            entryMode = null
            receiptPrintFlag = ReceiptPrintFlag.NO_RECEIPT
            cardPresentMode = null
            debitNetwork = null
            userLanguage = null
            additionalResponseDataFlag = null
            forceCc = null
            forceFsa = null
            forceDuplicate = "1"
            accessibilityPinPad = null
            cofIndicator = null
            cofInitiator = null
//        giftCardIndicator = null
            transactionPromptBitmap = null
        }

    private fun getOriginalReq() =
        Original().apply {
            transactionDate = null
            pan = null
            expiryDate = null
            transactionTime = null
            settlementDate = null
            amount = null
            batchNumber = null
            paymentService2000 = null
            authorizationResponse = null
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
