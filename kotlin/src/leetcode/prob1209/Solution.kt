package leetcode.prob1209

import java.util.LinkedList

class Solution {
    fun removeDuplicates(s: String, k: Int): String {
        val stack = LinkedList<Pair<Char, Int>>()

        s.forEach{ ch ->
            if (stack.isEmpty()){
                stack.add(ch to 1)
            }
            else {
                val poppedPair = stack.pollLast()
                if (poppedPair.first == ch){
                    stack.addLast(poppedPair.copy(second = poppedPair.second + 1))
                }
                else{
                    stack.addLast(poppedPair)
                    stack.addLast(ch to 1)
                }
            }

            if (stack.peekLast().second == k){
                stack.pollLast()
            }
        }

        val builder = StringBuilder()
        stack.forEach {
            repeat(it.second){ _ ->
                builder.append(it.first)
            }
        }
        return builder.toString()
    }
}