package leetcode.prob338

class Solution {
    fun countBits(n: Int): IntArray {
        val result = IntArray(n+1){0}
        if (n >= 1) result[1] = 1

        var base = 1
        var sub = 0

        for (i in 2..n) {
            if (i == base * 2){
                base = i
                sub = 0
            }
            result[i] = (1 + result[sub++])
        }

        return result
    }
}