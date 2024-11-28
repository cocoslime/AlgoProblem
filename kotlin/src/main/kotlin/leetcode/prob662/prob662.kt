package leetcode.prob662

import leetcode.TreeNode
import leetcode.makeTreeNode
import java.util.*

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
    fun widthOfBinaryTree(root: TreeNode?): Int {
        if (root == null) return 0

        var maximumWidth = 1

        var queue = ArrayDeque<Pair<TreeNode, Int>>()
        queue.push(Pair(root, 1))

        while (queue.isNotEmpty()) {
            val newQueue = ArrayDeque<Pair<TreeNode, Int>>()
            var leftMost = 0
            var currentWidth = 0

            while (queue.isNotEmpty()) {
                val curr = queue.removeFirst()

                if (leftMost == 0) {
                    leftMost = curr.second
                    currentWidth = 1
                }
                else {
                    currentWidth = curr.second - leftMost + 1
                }

                if (curr.first.left != null)
                    newQueue.add(Pair(curr.first.left!!, curr.second * 2))
                if (curr.first.right != null)
                    newQueue.add(Pair(curr.first.right!!, curr.second * 2 + 1))
            }

            maximumWidth = Math.max(maximumWidth, currentWidth)
            queue = newQueue
        }

        return maximumWidth
    }
}

fun main() {
    val list = listOf(1, 3, 2, 5, 3, null, 9)
    val root = makeTreeNode(list)

    print(Solution().widthOfBinaryTree(root))
}
