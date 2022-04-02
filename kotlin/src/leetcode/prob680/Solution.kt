package leetcode.prob680

class Solution {
    fun validPalindrome(s: String): Boolean {
        if (isPalindrome(s))
            return true

        for (i in 0 until s.length / 2) {
            val opposite = s.length - 1 - i
            if (s[i] != s[opposite]){
                if (isPalindrome(s.removeRange(i, i + 1)) || isPalindrome(s.removeRange(opposite, opposite + 1)))
                    return true
                break
            }
        }

        return false
    }

    private fun isPalindrome(s : String) : Boolean {
        for (i in 0 until s.length / 2) {
            val opposite = s.length - 1 - i
            if (s[i] != s[opposite])
                return false
        }
        return true
    }
}