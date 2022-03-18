package leetcode.prob316

class Solution {
    fun removeDuplicateLetters(s: String): String {
        if (s.isEmpty()) return ""

        val set = s.toSet()
        for (c in set.sorted()) {
            val index = s.indexOfFirst {
                it == c
            }
            val sub = s.substring(index)
            if (sub.toSet() == set) {
                return c + removeDuplicateLetters(sub.replace(c.toString(), ""))
            }
        }

        return ""
    }
}

fun main(){
    println(Solution().removeDuplicateLetters("cbacdcbc"))
}
//s = "cbacdcbc"