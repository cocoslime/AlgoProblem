package leetcode.prob20

import java.util.*

class Solution {
    fun isValid(s: String): Boolean {
        val stack = Stack<Char>()
        try {
            for (c in s) {
                when (c) {
                    in arrayOf('{', '(', '[') -> stack.push(c)
                    ']' -> if (stack.pop() != '[') return false
                    ')' -> if (stack.pop() != '(') return false
                    '}' -> if (stack.pop() != '{') return false
                }
            }
        } catch (e : EmptyStackException) {
            return false
        }

        return stack.empty()
    }
}