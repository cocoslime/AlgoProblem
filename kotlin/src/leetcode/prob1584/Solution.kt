package leetcode.prob1584

import java.util.PriorityQueue
import kotlin.math.abs

class Solution {
    fun minCostConnectPoints(points: Array<IntArray>): Int {
        val minHeap = PriorityQueue<Pair<Int, Int>>(compareBy { it.first })

        val manhattanList = points.mapIndexed { index, src ->
            points.mapIndexed { indexDest, dest ->
                if (index != indexDest)
                    calcManhattan(src, dest)
                else
                    Int.MAX_VALUE
            }
        }

        minHeap.add(0 to 0)

        val isChecked = BooleanArray(points.size)
        var pathNum = 0
        var totalDist = 0

        while (minHeap.isNotEmpty()){
            val node = minHeap.poll()
            if (isChecked[node.second])
                continue

            val dist = node.first


            isChecked[node.second] = true
            pathNum ++
            totalDist += dist

            if (pathNum == points.size)
                break

            manhattanList[node.second].forEachIndexed { index, newDist ->

                minHeap.add(newDist to index)
            }
        }

        return totalDist
    }

    private fun calcManhattan(src : IntArray, dest : IntArray) : Int {
        return abs(src[0] - dest[0]) + abs(src[1] - dest[1])
    }

}

fun main(){
    println(Solution().minCostConnectPoints(
        arrayOf(
            intArrayOf(2,-3), intArrayOf(-17,-8), intArrayOf(13,8), intArrayOf(-17,-15)
        )
    ))
}