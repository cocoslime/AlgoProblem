package leetcode.prob200

class Solution {
    private val WATER = -2
    private val LAND = -1
    var colorId = 0

    fun numIslands(grid: Array<CharArray>): Int {
        val coloredGrid = grid.map {
            it.map {ch ->
                if (ch == '0') WATER
                else LAND
            }.toIntArray()
        }.toTypedArray()

        for (i in grid.indices){
            for (j in 0 until grid[i].size) {
                if (coloredGrid[i][j] == LAND) {
                    coloring(i, j, coloredGrid)
                    colorId++
                }
            }
        }

        return colorId
    }

    private fun coloring(i: Int, j:Int, colorGrid:Array<IntArray>) {
        if (i < 0 || j < 0 || i >= colorGrid.size || j >= colorGrid[0].size || colorGrid[i][j] != LAND) return

        colorGrid[i][j] = colorId
        coloring(i + 1, j, colorGrid)
        coloring(i - 1, j, colorGrid)
        coloring(i, j + 1, colorGrid)
        coloring(i, j - 1, colorGrid)
    }
}