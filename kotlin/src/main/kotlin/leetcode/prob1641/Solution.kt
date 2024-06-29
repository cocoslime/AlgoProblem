package leetcode.prob1641

class Solution {
    fun countVowelStrings(r: Int): Int {
        val n = 5
        if (r == 1) return 5

        val child = if (n - 1 < r) permutation(n + r - 1, n - 1) else permutation(n + r - 1, r)
        val mom = if (n - 1 < r) factorial(n - 1) else factorial(r)

        return (child / mom).toInt()
    }

    private fun permutation(n : Int, r : Int) : Long{
        var result : Long = 1L

        for (i in 0 until r) {
            result *= (n - i)
        }
        return result
    }

    fun factorial(n : Int) : Long {
        var result = 1L
        for (i in 1..n){
            result *= i
        }
        return result
    }
}