package leetcode.prob34


class Solution {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        if (nums.isEmpty()) return intArrayOf(-1, -1)

        val start = searchRangeStart(0, nums.size - 1, nums, target)
        val end = searchRangeEnd(0, nums.size - 1, nums, target)
        return intArrayOf(start, end)
    }

    private fun searchRangeStart(start : Int, end : Int, nums : IntArray, target: Int) : Int {
        if (end == start) {
            return if (nums[start] == target) start
            else -1
        }
        else if (start > end) return -1

        val midIdx = (end + start) / 2
        return if (nums[midIdx] == target) {
            val next = searchRangeStart(start, midIdx - 1, nums, target)
            if (next == -1) midIdx
            else next
        } else if (nums[midIdx] > target){
            searchRangeStart(start, midIdx - 1, nums, target)
        } else {
            searchRangeStart(midIdx + 1 , end, nums, target)
        }
    }

    private fun searchRangeEnd(start : Int, end : Int, nums : IntArray, target: Int) : Int {
        if (end == start) {
            if (nums[start] == target) return start
            else return -1
        }
        else if (start > end) return -1

        val midIdx = (end + start) / 2
        if (nums[midIdx] == target) {
            val next = searchRangeEnd(midIdx + 1, end, nums, target)
            if (next == -1) return midIdx
            else return next
        }
        else if (nums[midIdx] > target){
            return searchRangeEnd(start, midIdx - 1, nums, target)
        }
        else {
            return searchRangeEnd(midIdx + 1 , end, nums, target)
        }
    }
}