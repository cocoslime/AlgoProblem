package leetcode.prob99

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

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}


class Solution {
    var isSwapped = false
    private var topRoot : TreeNode? = null

    fun recoverTree(root: TreeNode?): Unit {
        if (topRoot == null) topRoot = root
        if (root == null) return
        if (isSwapped) return

        val leftMaximum = root.left?.let{
            val max = findMaximum(it)
            if (max.`val` > root.`val`)
                max
            else
                null
        }
        val rightMinimum = root.right?.let {
            val min = findMinimum(it)
            if (min.`val` < root.`val`)
                min
            else
                null
        }

        if (leftMaximum == null && rightMinimum == null) {
            recoverTree(root.left)
            recoverTree(root.right)
        }
        else if (leftMaximum != null && rightMinimum != null){
            swap(leftMaximum, rightMinimum)
            return
        }
        else if (leftMaximum != null) {
            swap(leftMaximum, root)
            return
        }
        else if (rightMinimum != null){
            swap(rightMinimum, root)
            return
        }
        else {
            println("?")
        }
    }

    fun swap(node1 : TreeNode, node2 : TreeNode) {
        isSwapped = true

        val temp = node1.`val`
        node1.`val` = node2.`val`
        node2.`val` = temp
    }

    fun findMinimum(node : TreeNode) : TreeNode {
        val list = mutableListOf<TreeNode>(node)
        node.left?.let {
            list.add(findMinimum(it))
        }
        node.right?.let {
            list.add(findMinimum(it))
        }

        return list.sortedBy { it.`val` }[0]
    }

    fun findMaximum(node : TreeNode) : TreeNode {
        val list = mutableListOf<TreeNode>(node)
        node.left?.let {
            list.add(findMaximum(it))
        }
        node.right?.let {
            list.add(findMaximum(it))
        }

        return list.sortedByDescending { it.`val` }[0]
    }
}