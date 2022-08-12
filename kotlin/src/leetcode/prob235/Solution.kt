package leetcode.prob235

/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
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
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        if (root == null) return null

        val leftChild = lowestCommonAncestor(root.left, p, q)
        val rightChild = lowestCommonAncestor(root.right, p, q)

        val list = listOf(root, leftChild, rightChild)

        if (p in list && q in list) return root
        else if (p in list) return p
        else if (q in list) return q
        else if (leftChild != null) return leftChild
        else return rightChild
    }
}