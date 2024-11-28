package leetcode.ing.prob1480

class Solution {
    fun runningSum(nums: IntArray): IntArray {
        var currentSum = 0
        val result = nums.clone()

        for (i in result.indices){
            result[i] = currentSum + result[i]
            currentSum = result[i]
        }

        return result
    }
}