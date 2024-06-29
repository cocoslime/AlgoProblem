package leetcode.prob844

class Solution {
    fun backspaceCompare(s: String, t: String): Boolean {
        val convertedS = processBackspace(s)
        val convertedT = processBackspace(t)

        return convertedS == convertedT
    }

    fun processBackspace(str : String) : String {
        val stack = mutableListOf<Char>()
        str.forEach{
            if (it == '#') {
                if (stack.isNotEmpty()) {
//                    stack.removeLast()
                    stack.removeAt(stack.size - 1)
                }
            }
            else {
                stack.add(it)
            }
        }

        return String(stack.toCharArray())
    }
}