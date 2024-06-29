package leetcode.prob1260

class Solution {
    fun shiftGrid(grid: Array<IntArray>, k: Int): List<List<Int>> {
        val n = grid.size
        val m = grid[0].size
        val modK = k % (n * m)

        val newGrid = Array<Array<Int>>(n){
            Array<Int>(m){0}
        }

        for (i in 0 until n) {
            for (j in 0 until m) {
                var newJ = j + (modK % m)
                var newI = i + (modK / m)

                if (newJ >= m) {
                    newJ -= m
                    newI += 1
                }
                if (newI >= n) {
                    newI -= n
                }

                newGrid[newI][newJ] = grid[i][j]
            }
        }

        return newGrid.map{
            it.toList()
        }
    }
}