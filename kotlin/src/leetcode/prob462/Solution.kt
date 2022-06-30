package leetcode.prob462

class Solution {
    fun minMoves2(nums: IntArray): Int {
        val sorted = nums.sorted()
        val mid = sorted[sorted.size / 2]
        return nums.fold(0) { i, acc ->
            acc + kotlin.math.abs(i - mid)
        }
    }
}