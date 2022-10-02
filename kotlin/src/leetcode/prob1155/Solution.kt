package leetcode.prob1155

class Solution {
    val MOD = 1000000000 + 7
    val cache = Array(1001) {
        Array(30){
            -1
        }
    }

    fun numRollsToTarget(n: Int, k: Int, target: Int): Int {
        if (cache[target][n] != -1) return cache[target][n]
        if (n == 1) {
            if (target > 0 && target <= k) return 1
            else return 0
        }

        var sum = 0L
        for (i in 1 .. k) {
            if (target - i == 0) break
            sum += numRollsToTarget(n - 1, k, target - i)
            sum %= MOD
        }

        cache[target][n] = sum.toInt()
        return cache[target][n]
    }
}