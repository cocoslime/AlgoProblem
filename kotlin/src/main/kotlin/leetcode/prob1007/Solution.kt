package leetcode.prob1007

import kotlin.math.min

class Solution {
    fun minDominoRotations(tops: IntArray, bottoms: IntArray): Int {
        val pairSet = mutableSetOf<Int>()
        var n = tops.size
        val topMap = HashMap<Int, Int>()
        val bottomMap = HashMap<Int, Int>()

        repeat(7){
            topMap[it] = 0
            bottomMap[it] = 0
        }

        repeat(tops.size) {
            val top = tops[it]
            val bottom = bottoms[it]
            if (top == bottom) {
                pairSet.add(top)
                n--
            }
            else {
                topMap[top] = topMap[top]!! + 1
                bottomMap[bottom] = bottomMap[bottom]!! + 1
            }
        }

        if (pairSet.size >= 2)
            return -1

        var minResult = Int.MAX_VALUE

        if (pairSet.isEmpty()){
            pairSet.addAll(arrayOf(1,2,3,4,5,6))
        }

        for (i in pairSet.toIntArray()){
            val topValue = topMap[i]!!
            val bottomValue = bottomMap[i]!!
            if (topValue + bottomValue == n) {
                minResult = min(minResult, min(topValue, bottomValue))
            }
        }

        if (minResult == Int.MAX_VALUE)
            return -1
        else
            return minResult
    }
}