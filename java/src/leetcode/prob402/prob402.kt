package leetcode.prob402

import java.util.*

class Solution {
    private fun trimZero(string: String) : String {
        for (i in string.indices) {
            if (string[i] != '0')
                return string.substring(i)
        }
        return "0"
    }

    fun removeKdigits(num: String, k: Int): String {
        if (num.length == k)
            return "0"

        val stack = Stack<Char>()
        var currentK = k

        stack.push(num[0])

        for ( i in 1 until num.length){
            while (currentK > 0 && stack.isNotEmpty() && stack.peek() > num[i]) {
                stack.pop()
                currentK--
            }

            stack.push(num[i])
        }

        if (stack.empty())
            return "0"

        val sb : StringBuilder = java.lang.StringBuilder()
        while (stack.isNotEmpty()){
            sb.insert(0, stack.pop())
        }

        val result = sb.toString()
        return trimZero(result.substring(0, num.length - k))
    }

}

fun main(args: Array<String>){
    val sol = Solution()
    System.out.println(sol.removeKdigits("10200", 1))
}