package leetcode.prob215

class Solution {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        val sorted = nums.sortedDescending()
        return sorted[k - 1]
    }
}