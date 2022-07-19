package leetcode.prob118

class Solution {
    fun generate(numRows: Int): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        repeat(numRows){
            val size = it + 1
            val parent = if (result.isNotEmpty()) result.last() else emptyList()
            val current = mutableListOf<Int>()
            for (i in 0 until size){
                if (i == 0 || i == size - 1) {
                    current.add(1)
                }
                else {
                    current.add(parent[i-1] + parent[i])
                }
            }
            result.add(current)
        }
        return result
    }
}