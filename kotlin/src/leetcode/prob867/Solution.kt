package leetcode.prob867

class Solution {
    fun transpose(matrix: Array<IntArray>): Array<IntArray> {
        val transposed = Array<IntArray>(matrix[0].size){
            IntArray(matrix.size){0}
        }

        for (i in matrix.indices){
            for (j in matrix[i].indices){
                transposed[j][i] = matrix[i][j]
            }
        }

        return transposed
    }
}