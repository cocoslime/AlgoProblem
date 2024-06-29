package leetcode.prob1342

class Solution {
    fun numberOfSteps(num: Int): Int {
        return if (num == 0) 0
        else if (num % 2 == 0) {
            1 + numberOfSteps(num / 2)
        } else {
            1 + numberOfSteps(num - 1)
        }
    }
}