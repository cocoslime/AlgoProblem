package leetcode.prob410

import java.lang.Integer.max
import java.lang.Integer.min

class Solution {
    val dp = Array<IntArray>(1001){
        IntArray(1001) {
            -1
        }
    }

    fun splitArray(nums: IntArray, m: Int): Int {
        return findMinMax(nums, 0, m)
    }

    fun findMinMax(nums : IntArray, start : Int, m : Int) : Int {
        if (dp[start][m] != -1)
            return dp[start][m]
        else if (m == 1) {
            var sum = 0
            for (i in start until nums.size)
                sum += nums[i]
            dp[start][m] = sum
            return sum
        }

        var currSum = 0
        var minMax = Int.MAX_VALUE
        for (i in start .. nums.size - m) {
            currSum += nums[i]
            val currMax = Integer.max(findMinMax(nums, i + 1, m - 1), currSum)
            minMax = Integer.min(minMax, currMax)
        }

        dp[start][m] = minMax
        return minMax
    }
}

fun main(){
    println(Solution().splitArray(intArrayOf(7,2,5,10,8), 2))
}