package leetcode.prob128

class Solution {
    fun longestConsecutive(nums: IntArray): Int {
        val set = nums.toSet()
        var maxLen = 0
        set.forEach {
            if (!set.contains(it - 1)){
                var currLen = 1
                var currNum = it + 1
                while (set.contains(currNum)){
                    currLen++
                    currNum++
                }
                maxLen = kotlin.math.max(currLen, maxLen)
            }
        }
        return maxLen
    }
}