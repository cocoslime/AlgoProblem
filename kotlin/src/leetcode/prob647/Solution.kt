package leetcode.prob647

class Solution {
    fun countSubstrings(s: String): Int {
        var result = 0
        for (gap in 1 ..s.length) {
            for (start in 0 .. s.length - gap) {
                if (isPalindrome(start, gap, s)) {
                    result += 1
                }
            }
        }

        return result
    }

    private fun isPalindrome(start : Int, diff : Int, s:String) : Boolean{
        var i = start
        var j = start + diff - 1
        while (i < j) {
            if (s[i] != s[j]) return false
            i++
            j--
        }

        return true
    }
}