package leetcode.prob1091

import java.util.*

class Solution {
    var n = 0

    fun shortestPathBinaryMatrix(grid: Array<IntArray>): Int {
        n = grid.size
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1

        val minHeap = PriorityQueue<Pair<Int, Int>>(compareBy { it.first })
        minHeap.add(1 to calcIndex(0, 0))

        val visited = BooleanArray(n * n){false}

        while (minHeap.isNotEmpty()){
            val minDest = minHeap.poll()
            if (minDest.second == n * n - 1) return minDest.first

            if (visited[minDest.second])
                continue
            visited[minDest.second] = true

            val x = minDest.second / n
            val y = minDest.second % n
            val dist = minDest.first

            for (xd in -1..1){
                for (yd in -1 .. 1){
                    if (xd == 0 && yd == 0) continue
                    if ((x + xd in 0 until n) && (y + yd in 0 until n)){
                        if (grid[x+xd][y+yd] == 0)
                            minHeap.add(dist + 1 to calcIndex(x + xd, y + yd))
                    }
                }
            }
        }

        return -1
    }

    private fun calcIndex(x : Int, y : Int) : Int {
        return x * n + y
    }
}