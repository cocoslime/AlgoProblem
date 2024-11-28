package leetcode.prob1642

import java.util.PriorityQueue

class Solution {
    fun furthestBuilding(heights: IntArray, bricks: Int, ladders: Int): Int {
        val needLadder = PriorityQueue<Int>()
        var needBricks = 0

        repeat(ladders){
            needLadder.add(0)
        }

        for (i in 0 until heights.size - 1) {
            val gap = heights[i + 1] - heights[i]
            val shortestAmongLadder = if (ladders > 0) needLadder.peek() else Int.MAX_VALUE
            if (gap > 0) {
                if (gap > shortestAmongLadder){
                    needBricks += shortestAmongLadder
                    needLadder.poll()
                    needLadder.add(gap)
                }
                else{
                    needBricks += gap
                }

                if (needBricks > bricks) {
                    return i
                }
            }
        }

        return heights.size - 1
    }
}