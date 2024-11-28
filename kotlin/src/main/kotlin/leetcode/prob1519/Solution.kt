package leetcode.prob1519

class Solution {
    fun countSubTrees(n: Int, edges: Array<IntArray>, labels: String): IntArray {
        val children = List(n) { mutableListOf<Int>() }
        edges.forEach {
            children[it[0]].add(it[1])
            children[it[1]].add(it[0])
        }

        val visited = BooleanArray(n) { false }
        val result = Array<Int>(n) { 0 }

        fun dfs(current: Int) : IntArray {
            visited[current] = true

            val count = IntArray(30){ 0 }
            children[current].forEach { child ->
                if (!visited[child]) {
                    val nextResult = dfs(child)
                    for (i in 0 until 30) count[i] += nextResult[i]
                }
            }
            count[labels[current] - 'a']++
            result[current] = count[labels[current] - 'a']
            return count
        }

        dfs(0)

        return result.toIntArray()
    }
}

fun main() {
    val edges = arrayOf(intArrayOf(0,1),intArrayOf(0,2),intArrayOf(1,4),intArrayOf(1,5),intArrayOf(2,3),intArrayOf(2,6))
    println(Solution().countSubTrees(7, edges, "abaedcd").asList())
}