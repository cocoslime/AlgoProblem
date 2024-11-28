package leetcode.prob318

class Solution {
    fun maxProduct(words: Array<String>): Int {
        var maxLength = 0
        for (i in 0 until words.size - 1) {
            for (j in i + 1 until words.size) {
                if (hasNoCommon(words[i], words[j])){
                    maxLength = kotlin.math.max(maxLength, words[i].length * words[j].length)
                }
            }
        }
        return maxLength
    }

    fun hasNoCommon(str1 : String, str2 : String) : Boolean {
        val str1Set = str1.toSet()

        str2.forEach {
            if (str1Set.contains(it)) return@hasNoCommon false
        }
        return true
    }
}