package leetcode.prob1631

import java.util.PriorityQueue

class Solution {
    var row = 0
    var column = 0

    fun minimumEffortPath(heights: Array<IntArray>): Int {
        val adjMat = Array<MutableList<Pair<Int, Int>>>(heights.size * heights[0].size){
            mutableListOf()
        }

        row = heights.size
        column = heights[0].size

        for (i in 0 until row){
            for (j in 0 until column){
                val idx = i * heights[0].size + j
                val height = heights[i][j]
                if (i != 0){
                    addNeighbor(heights, adjMat, idx, height, i-1, j)
                }
                if (i != row - 1){
                    addNeighbor(heights, adjMat, idx, height, i+1, j)
                }
                if (j != 0){
                    addNeighbor(heights, adjMat, idx, height, i, j - 1)
                }
                if (j != column - 1){
                    addNeighbor(heights, adjMat, idx, height, i, j + 1)
                }
            }
        }

        val destination = row * column - 1
        val dist = IntArray(row*column){-1}

        val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second }) // <idx, dist>
        pq.add(0 to 0)

        while (pq.isNotEmpty()) {
            val curr = pq.poll()
            if (dist[curr.first] != -1)
                continue
            println(curr)

            dist[curr.first] = curr.second
            if (curr.first == destination) break

            val neighbors = adjMat[curr.first]
            neighbors.forEach {
                if (dist[it.first] == -1){
                    pq.add(it.first to kotlin.math.max(curr.second, it.second))
                }
            }
        }

        return dist[destination]
    }

    private fun addNeighbor(heights: Array<IntArray>, adjMat : Array<MutableList<Pair<Int, Int>>>, idx : Int, height : Int, i : Int, j : Int) {
        val neighborIdx = i * column + j
        val neighborHeight = heights[i][j]
        val dist = kotlin.math.abs(height - neighborHeight)
        adjMat[idx].add(neighborIdx to dist)
    }
}