package leetcode.prob138

/**
 * Example:
 * var ti = Node(5)
 * var v = ti.`val`
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var next: Node? = null
 *     var random: Node? = null
 * }
 */

class Node(var `val`: Int) {
    var next: Node? = null
    var random: Node? = null
}

class Solution {
    fun copyRandomList(node: Node?): Node? {
        return if (node != null) {
            val nodeMap = HashMap<Node, Node>()
            var currNode = node
            while (currNode != null){
                if (!nodeMap.contains(currNode)){
                    nodeMap[currNode] = Node(currNode.`val`)
                }
                val newCurrNode = nodeMap[currNode]!!

                newCurrNode.next = currNode.next?.let {
                    if (!nodeMap.contains(it)) {
                        nodeMap[it] = Node(it.`val`)
                    }
                    nodeMap[it]
                }

                newCurrNode.random = currNode.random?.let {
                    if(!nodeMap.contains(it)) {
                        nodeMap[it] = Node(it.`val`)
                    }
                    nodeMap[it]
                }

                currNode = currNode.next
            }

            nodeMap[node]
        } else {
            null
        }
    }
}