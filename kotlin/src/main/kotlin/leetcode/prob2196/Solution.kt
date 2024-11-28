package leetcode.prob2196

import leetcode.TreeNode

/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    val nodes = Array<TreeNode?>(100001) { null }
    val isParent = Array<Boolean?>(100001) { null }

    fun createBinaryTree(descriptions: Array<IntArray>): TreeNode? {
        descriptions.forEach { (parent, child, isLeft) ->
            val childTreeNode = nodes[child] ?: TreeNode(child)
            val parentTreeNode = nodes[parent] ?: TreeNode(parent)

            if (isLeft == 1) {
                parentTreeNode.left = childTreeNode
            } else {
                parentTreeNode.right = childTreeNode
            }
            nodes[child] = childTreeNode
            nodes[parent] = parentTreeNode

            if (isParent[parent] == null) isParent[parent] = true
            isParent[child] = false
        }

        val root = isParent.indexOfFirst { it == true }
        return nodes[root]
    }
}

fun main() {
    Solution().createBinaryTree(
        descriptions = arrayOf(
            intArrayOf(20, 15, 1),
            intArrayOf(20, 17, 0),
            intArrayOf(50, 20, 1),
            intArrayOf(50, 80, 0),
            intArrayOf(80, 19, 1)
        )
    ).toString().let { println(it) }
    Solution().createBinaryTree(
        descriptions = arrayOf(
            intArrayOf(1, 2, 1),
            intArrayOf(2, 3, 0),
            intArrayOf(3, 4, 1),
        )
    ).toString().let { println(it) }
}