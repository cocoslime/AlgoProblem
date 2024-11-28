package leetcode.prob133

import java.util.*

/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var neighbors: ArrayList<Node?> = ArrayList<Node?>()
 * }
 */

class Solution {
    class Node(var `val`: Int) {
        var neighbors: ArrayList<Node?> = ArrayList<Node?>()
    }

    fun cloneGraph(node: Node?): Node? {
        if (node == null) return null

        val nodeMap = arrayOfNulls<Node?>(101) // for new node
        val stack = ArrayDeque<Node>() // for original node
        stack.push(node)

        val newNode = Node(node.`val`)
        nodeMap[newNode.`val`] = newNode

        while (stack.isNotEmpty()) {
            val currNode = stack.pop()
            val newCurrNode = nodeMap[currNode.`val`]!!

            currNode.neighbors.forEach { it ->
                if (it != null) {
                    if (nodeMap[it.`val`] == null) {
                        nodeMap[it.`val`] = Node(it.`val`)
                        stack.push(it)
                    }
                    newCurrNode.neighbors.add(nodeMap[it.`val`])
                }
            }
        }

        return newNode
    }
}