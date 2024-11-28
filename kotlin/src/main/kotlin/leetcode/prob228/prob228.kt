package leetcode.prob228

class Solution {
    fun summaryRanges(nums: IntArray): List<String> {
        val result = mutableListOf<String>()
        if (nums.isEmpty()) return result

        var currStart = 0
        var currEnd = 0

        result.add(nums[currStart].toString())

        for (i in 0 until nums.size - 1) {
            if (nums[i] + 1 == nums[i + 1])
            {
                currEnd++
            }
            else {
                if (currStart != currEnd)
                    result[result.lastIndex] += ("->"+nums[currEnd].toString())

                currStart = i+1
                currEnd = i+1

                result.add(nums[currStart].toString())
            }
        }

        if (currStart != currEnd)
            result[result.lastIndex] += ("->"+nums[currEnd].toString())

        return result
    }
}