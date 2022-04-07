package leetcode.prob1046

import java.lang.Math.abs
import java.util.*

class Solution {
    fun lastStoneWeight(stones: IntArray): Int {
        val sorted = stones.sortedDescending()
        val list = LinkedList(sorted)
        while (list.size > 1) {
            val stone1 = list.pollFirst()
            val stone2 = list.pollFirst()
            if (stone1 != stone2) {
                val newValue = abs(stone1 - stone2)
                val idx = list.binarySearch(newValue, compareByDescending { it }).let {
                    if (it < 0) {
                        -it - 1
                    }
                    else
                        it
                }
                list.add(idx, newValue)
            }
        }
        return if (list.isEmpty()) 0 else list[0]
    }
}