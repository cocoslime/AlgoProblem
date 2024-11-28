package leetcode.prob581

class Solution {
    fun findUnsortedSubarray(nums: IntArray): Int {
        var start = -1
        var end = -1
        var biggest = Int.MIN_VALUE
        var smallest = Int.MAX_VALUE

        for (idx in nums.indices) {
            if (biggest > nums[idx]){
                end = idx
                smallest = kotlin.math.min(smallest, nums[idx])
            }
            else {
                biggest = nums[idx]
            }
        }

        for (idx in nums.indices) {
            if (smallest < nums[idx]) {
                start = idx
                break
            }
        }

        if (start == end) return 0
        else return (end - start + 1)
    }
}