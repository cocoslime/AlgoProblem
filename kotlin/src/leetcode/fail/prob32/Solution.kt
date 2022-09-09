package leetcode.fail.prob32

import java.util.*

class Solution {
    fun longestValidParentheses(s: String): Int {
        val stack = Stack<Int>()
        var longest = 0
        var current = 0

        s.forEachIndexed { index, c ->
            when(c){
                '(' -> {
                    stack.add(index)
                }
                ')' -> {
                    if (stack.isNotEmpty()){
                        val last = stack.pop()
                        if (stack.isEmpty()){
                            current += index - last + 1
                            longest = kotlin.math.max(current, longest)
                        }
                        else {
                            longest = kotlin.math.max(index - last + 1, longest)
                        }
                    }
                    else {
                        current = 0
                    }
                }
            }
        }

        return longest
    }
}

interface Contract {
    var name : String
}

class Me(val myName : String) : Contract{
    override var name = myName
}

val me = Me("Me")

class You() : Contract by me {
    fun other() {
        print("other")
    }
}

