package leetcode.prob847

import java.util.*

// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/135809/Fast-BFS-Solution-(46ms)-Clear-Detailed-Explanation-Included

class Solution {
    fun shortestPathLength(graph: Array<IntArray>): Int {
        val N = graph.size
        val isChecked = HashSet<Path>() // 현재 경로를 확인했는지. 같은 경로라면 먼저 확인 한것이 비용이 적은 것이므로 버림.
        val queue = LinkedList<Path>() // BFS Queue

        for (i in 0 until N) { // Add all nodes for starting
            val path = Path(1 shl i, i, 0)
            isChecked.add(path)
            queue.add(path)
        }

        while (queue.isNotEmpty()) {
            val currPath = queue.removeFirst()

            if (currPath.bitmask == (1 shl N) - 1) { // Check all nodes?
                return currPath.cost
            }

            val neighbors = graph[currPath.curr]
            for (neighbor in neighbors) { // BFS
                val checkPath = Path(currPath.bitmask or (1 shl neighbor), neighbor, 0)
                if (!isChecked.contains(checkPath)) { // 확인한 경로가 아니면
                    queue.add(Path(checkPath.bitmask, checkPath.curr, currPath.cost + 1))
                    isChecked.add(checkPath)
                }
            }
        }

        return 0
    }

    data class Path(val bitmask: Int, val curr: Int, val cost: Int) {}
}