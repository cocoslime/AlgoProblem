package leetcode.prob1679

class Solution {
    fun maxOperations(nums: IntArray, k: Int): Int {
        val sortedNums = nums.sorted()
        var operation = 0
        var front = 0
        var back = nums.size - 1
        while (front < back) {
            val frontValue = sortedNums[front]
            val backValue = sortedNums[back]

            when {
                frontValue + backValue > k -> back--
                frontValue + backValue < k -> front++
                else -> {
                    operation++
                    back--
                    front++
                }
            }
        }

        return operation
    }
}