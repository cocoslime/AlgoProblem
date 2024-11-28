package leetcode.prob6

class Solution {
    fun convert(s: String, numRows: Int): String {
        if (numRows == 1) return s
        var result = ""
        for (start in 0 until numRows) {
            var i = start
            val downUpStep = (numRows - 1 - start) * 2
            val upDownStep = start * 2
            var isDown = downUpStep != 0

            while (i < s.length) {
                result += s[i]
                if (isDown) {
                    i += downUpStep
                    if (upDownStep != 0) isDown = false
                } else {
                    i += upDownStep
                    if (downUpStep != 0) isDown = true
                }
            }
        }

        return result
    }
}

fun main(){
    println(Solution().convert("PAYPALISHIRING", 3))
}