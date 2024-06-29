package leetcode.prob456

import java.util.*

class Solution {
    fun find132pattern(nums: IntArray): Boolean {
        if (nums.size < 3) return false

        val stack = LinkedList<Pair<Int, Int>>()
        var currentMin = nums[0]
        nums.forEach { num ->
            stack.forEach { (min, max) ->
                if (num in (min + 1) until max) return true
            }

            if (stack.isNotEmpty() && num > stack.peekLast().second){
                val top = stack.pollLast()
                stack.add(top.copy(second = num))
            }
            else if (num < currentMin)
                currentMin = num
            else if (num > currentMin)
                stack.add(currentMin to num)
        }

        return false
    }
}