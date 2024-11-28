package leetcode.prob17

class Solution {
    val letterMap = listOf("", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz")
    fun letterCombinations(digits: String): List<String> {
        if (digits.isEmpty()) return listOf()
        return addLetter(digits, 0, "")
    }

    private fun addLetter(digits: String, idx : Int, prefix : String) : List<String> {
        if (idx == digits.length) return listOf(prefix)

        val letters = letterMap[digits.substring(idx, idx + 1).toInt()]
        val result = mutableListOf<String>()
        for (letter in letters){
            result += addLetter(digits, idx + 1, prefix + letter)
        }

        return result
    }
}