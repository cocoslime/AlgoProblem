package leetcode.prob907


class Solution {
    val MOD = 1000000007

    fun sumSubarrayMins(arr: IntArray): Int {
        val current = arr.toMutableList()
        var sum = 0L
        for (stage in 0 until arr.size) {
            val minIdx = current.findMinimumIndex()
        }
        return (sum + arr.sum() % MOD).toInt()
    }

    fun MutableList<Int>.findMinimumIndex(): Int {
        var minIdx = -1
        var minValue = Int.MAX_VALUE
        forEachIndexed { index, i ->
            if (i < minValue) {
                minValue = i
                minIdx = index
            }
        }
        return minIdx
    }
}