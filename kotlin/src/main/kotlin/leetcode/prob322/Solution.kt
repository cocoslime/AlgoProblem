package leetcode.prob322

class Solution {
    val cache = IntArray(10001){0}
    fun coinChange(coins: IntArray, amount: Int): Int {
        if (amount == 0) return 0
        if (cache[amount] != 0) return cache[amount]

        var fewest = Int.MAX_VALUE
        coins.forEach {
            if (amount >= it){
                val result = coinChange(coins, amount - it)
                if (result != -1) fewest = kotlin.math.min(fewest, 1 + result)
            }

        }

        if (fewest == Int.MAX_VALUE) fewest = -1

        cache[amount] = fewest
        return cache[amount]
    }
}