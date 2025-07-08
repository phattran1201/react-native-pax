package com.paxposlink

import com.facebook.react.bridge.*
import com.google.gson.Gson
import org.json.*

object Utils {
    private val gson = Gson()

    @JvmStatic
    fun toWritableMap(data: Any?): WritableMap {
        if (data == null) return Arguments.createMap()
        return try {
            val jsonObject = JSONObject(gson.toJson(data))
            convertJsonToMap(jsonObject)
        } catch (e: JSONException) {
            e.printStackTrace()
            Arguments.createMap()
        }
    }

    @JvmStatic
    fun toWritableArray(data: Any?): WritableArray {
        if (data == null) return Arguments.createArray()
        return try {
            val jsonArray = JSONArray(gson.toJson(data))
            convertJsonToArray(jsonArray)
        } catch (e: JSONException) {
            e.printStackTrace()
            Arguments.createArray()
        }
    }

    @JvmStatic
    fun convertJsonToMap(jsonObject: JSONObject?): WritableMap {
        val map = Arguments.createMap()
        if (jsonObject == null) return map
        try {
            val keys = jsonObject.names() ?: return map
            for (i in 0 until keys.length()) {
                val key = keys.optString(i)
                val value = jsonObject.opt(key)
                putValueToMap(map, key, value)
            }
        } catch (e: Exception) {
            e.printStackTrace()
        }
        return map
    }

    @JvmStatic
    fun convertJsonToArray(jsonArray: JSONArray?): WritableArray {
        val array = Arguments.createArray()
        if (jsonArray == null) return array
        try {
            for (i in 0 until jsonArray.length()) {
                val value = jsonArray.opt(i)
                pushValueToArray(array, value)
            }
        } catch (e: Exception) {
            e.printStackTrace()
        }
        return array
    }

    private fun putValueToMap(map: WritableMap, key: String, value: Any?) {
        try {
            when (value) {
                is JSONObject -> map.putMap(key, convertJsonToMap(value))
                is JSONArray -> map.putArray(key, convertJsonToArray(value))
                is Boolean -> map.putBoolean(key, value)
                is Int -> map.putInt(key, value)
                is Long -> map.putDouble(key, value.toDouble()) // RN does not have putLong
                is Float, is Double -> map.putDouble(key, (value as Number).toDouble())
                JSONObject.NULL, null -> map.putNull(key)
                else -> map.putString(key, value.toString())
            }
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    private fun pushValueToArray(array: WritableArray, value: Any?) {
        try {
            when (value) {
                is JSONObject -> array.pushMap(convertJsonToMap(value))
                is JSONArray -> array.pushArray(convertJsonToArray(value))
                is Boolean -> array.pushBoolean(value)
                is Int -> array.pushInt(value)
                is Long -> array.pushDouble(value.toDouble())
                is Float, is Double -> array.pushDouble((value as Number).toDouble())
                JSONObject.NULL, null -> array.pushNull()
                else -> array.pushString(value.toString())
            }
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }
}
