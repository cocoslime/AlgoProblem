package leetcode.prob905

class Solution {
    fun sortArrayByParity(nums: IntArray): IntArray {
        val result = mutableListOf<Int>()
        val oddStack = mutableListOf<Int>()

        nums.forEach {
            if (it % 2 == 1)
                oddStack.add(it)
            else
                result.add(it)
        }

        result += oddStack
        return result.toIntArray()
    }
}