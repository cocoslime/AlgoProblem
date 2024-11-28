package leetcode.prob268

class Solution {
    fun missingNumber(nums: IntArray): Int {
        val sum = nums.reduce { acc, i -> acc + i }
        val answer = ((nums.size) * (nums.size + 1)) / 2
        return answer - sum
    }
}