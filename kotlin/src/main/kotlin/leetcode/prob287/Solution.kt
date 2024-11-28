package leetcode.prob287

class Solution {
    fun findDuplicate(nums: IntArray): Int {
        val n = nums.size
        val map = MutableList<Int>(n){0}
        nums.forEach {
            map[it]++
            if (map[it] > 1) return it
        }
        return 0
    }
}