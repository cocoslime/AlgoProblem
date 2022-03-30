package leetcode.prob74

class Solution {
    var m : Int = 0
    var n : Int = 0

    fun binarySearch(start : Int, end : Int, matrix: Array<IntArray>, target : Int) : Boolean {
        if (end < start) return false
        val idx = (end + start) / 2
        val mIdx = idx / n
        val nIdx = idx % n

        println("$start to $end : $mIdx, $nIdx, ${matrix[mIdx][nIdx]}")

        return when {
            matrix[mIdx][nIdx] == target -> true
            end == start -> false
            matrix[mIdx][nIdx] < target -> {
                binarySearch(idx + 1, end, matrix, target)
            }
            else -> {
                binarySearch(start, idx, matrix, target)
            }
        }
    }

    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
        m = matrix.size
        n = matrix[0].size

        return binarySearch(0, m * n - 1, matrix, target)
    }
}

fun main() {
    print(Solution().searchMatrix(arrayOf(intArrayOf(1,3,5,7), intArrayOf(10,11,16,20), intArrayOf(23,30,34,60)), 3))
}