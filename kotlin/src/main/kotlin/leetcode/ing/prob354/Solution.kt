package leetcode.ing.prob354

class Solution {
    lateinit var cache : IntArray
    lateinit var list : Array<IntArray>

    fun maxEnvelopes(envelopes: Array<IntArray>): Int {
        cache = IntArray(envelopes.size){-1}
        list = envelopes.sortedByDescending { it[0] * it[1] }.toTypedArray()
        var maximum = 0
        for (i in list.indices) {
            if (cache[i] != -1)
                maximum = kotlin.math.max(maximum, makeCache(i))
        }

        return maximum
    }

    private fun makeCache(idx : Int) : Int {
        if (cache[idx] != -1) return cache[idx]
        var result = 1

        val envelope = list[idx]
        for (checkIdx in idx + 1 until list.size) {
            if (cache[checkIdx] != -1 && cache[checkIdx] + 1< result) continue
            val checkEnvelope = list[checkIdx]
            if (envelope.isBig(checkEnvelope)) {
                val newResult = 1 + makeCache(checkIdx)
                if (newResult > result){
                    result = newResult
                }
            }
        }

        cache[idx] = result
        return result
    }

    private fun IntArray.isBig(target : IntArray) : Boolean {
        return (this.get(0) > target[0] && this.get(1) > target[1])
    }
}