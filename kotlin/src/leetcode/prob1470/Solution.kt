package leetcode.prob1470

class Solution {
    fun shuffle(nums: IntArray, n: Int): IntArray {
        val result = nums.clone()
        for (i in 0 until n) {
            result[i * 2] = nums[i]
            result[i * 2 + 1] = nums[n + i]
        }
        return result
    }
}