package leetcode.prob62

import java.util.Arrays

class Solution {
    lateinit var cache : Array<Array<Int>>

    fun uniquePaths(m: Int, n: Int): Int {
        cache = Array(m) {
            Array<Int>(n) { 0 }
        }

        for (i in 0 until m) {
            for (j in 0 until n) {
                if (i == 0 || j == 0) cache[i][j] = 1
                else {
                    cache[i][j] = cache[i-1][j] + cache[i][j-1]
                }
            }
        }

        return cache[m-1][n-1]
    }
}