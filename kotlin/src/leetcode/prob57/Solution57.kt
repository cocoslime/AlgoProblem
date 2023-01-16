package leetcode.prob57

class Solution {
    fun insert(intervals: Array<IntArray>, newInterval: IntArray): Array<IntArray> {
        var isDone = false
        var newStart = newInterval[0]
        var newEnd = newInterval[1]

        val result = mutableListOf<IntArray>()
        for (interval in intervals) {
            if (isDone) {
                result.add(interval)
            } else {
                if (interval[1] < newStart) {
                    result.add(interval)
                } else if (newEnd < interval[0]) {
                    result.add(intArrayOf(newStart, newEnd))
                    result.add(interval)
                    isDone = true
                } else {
                    newStart = kotlin.math.min(interval[0], newStart)
                    newEnd = kotlin.math.max(interval[1], newEnd)
                }
            }
        }

        if (!isDone) {
            result.add(intArrayOf(newStart, newEnd))
        }

        return result.toTypedArray()
    }
}