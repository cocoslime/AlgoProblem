package leetcode.prob171

class Solution {
    fun titleToNumber(columnTitle: String): Int {
        var result = 0
        for (i in 0 until columnTitle.length){
            val c = columnTitle[i]
            result = result * 26 + (c - 'A' + 1)
        }
        return result
    }
}

fun main(args: Array<String>) {
    print(Solution().titleToNumber("BA"))
}