package leetcode.prob114

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
    fun flatten(root: TreeNode?): Unit {
        if (root == null) {
            return
        }

        val right = root.right
        flatten(root.right)
        flatten(root.left)
        root.right = root.left
        root.left = null

        var tail : TreeNode = root
        while (tail.right != null){
            tail = tail.right!!
        }

        tail.right = right
    }
}