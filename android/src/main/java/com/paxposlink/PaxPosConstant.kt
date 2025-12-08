package com.paxposlink

import com.facebook.react.bridge.WritableMap

object PaxPosConstant {
    const val DEFAULT_ID: String = ""
    const val PORT: String = "10009"
    const val TIMEOUT: Int = 3000
}

// Data holder for PAX request parameters
data class PaxRequestModel(
    var id: String? = "",
    var amount: Int? = 0,
    var tip: Int? = null,
    var paymentType: Int? = null,
    var ecrRefNum: String? = "",
)

data class PaxResponseModel(
    var status: Boolean = false,
    var data: WritableMap? = null,
    var message: String = "",
    var isPaymentSuccess: Boolean = false,
    var id: String = "",
    var transactionId: String = "",
    var transactionNo: String = "",
    var refNum: String = "",
    var ecrRefNum: String = "",
    var transactionDateTime: String = "",
    var cardType: String = "",
    var cardNumber: String = "",
    var cardHolder: String = "",
    var amount: String = "",
    var tipAmount: String = "",
    var surcharge: String = "",
    var entryMethod: String = "",
    var sn: WritableMap? = null,
)

data class PaxTerminalInfoModel(
    var serialNumber: String = "",
    var modelName: String = "",
    var appName: String = "",
)

enum class CreditTransactionType(
    val code: Int,
) {
    Credit(1),
    Debit(2),
    Empty(0),
    ;

    companion object {
        fun fromCode(code: Int): CreditTransactionType = entries.find { it.code == code } ?: Empty
    }
}
