package leetcode.prob71

class Solution {
    fun simplifyPath(path: String): String {
        val splitBySlash = path.split("/")
        val stack = arrayListOf<String>()

        splitBySlash.forEach {
            when (it) {
                "" -> {}
                "." -> {}
                ".." -> {
                    if (stack.isNotEmpty()) {
                        stack.removeAt(stack.size - 1)
                    }
                }
                else -> {
                    stack.add(it)
                }
            }
        }

        var result = ""
        stack.forEach {
            result += "/"
            result += it
        }
        if (result.isBlank())
            return "/"
        return result
    }
}

fun main(){
    println(Solution().simplifyPath("/home/"))
    println(Solution().simplifyPath("/../"))
    println(Solution().simplifyPath("/home/"))
}