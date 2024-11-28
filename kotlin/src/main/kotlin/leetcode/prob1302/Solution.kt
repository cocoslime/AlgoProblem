package leetcode.prob1302

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}

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
    fun deepestLeavesSum(root: TreeNode?): Int {
        val deepestLevel = findDeepestLeave(root!!)
        val result = addAtLevel(root, 1, deepestLevel)
        return result
    }

    fun addAtLevel(node: TreeNode, level : Int, targetLevel : Int) : Int {
        if (level == targetLevel)
            return node.`val`

        var result = 0
        node.left?.let{
            result += addAtLevel(it, level + 1, targetLevel)
        }
        node.right?.let{
            result += addAtLevel(it, level + 1, targetLevel)
        }
        return result
    }

    private fun findDeepestLeave(node : TreeNode) : Int {
        val left = node.left
        val right = node.right

        val maxLevel = if (right == null && left == null) 0
        else if (right == null && left != null) findDeepestLeave(left)
        else if (left == null && right != null)  findDeepestLeave(right)
        else kotlin.math.max(findDeepestLeave(left!!), findDeepestLeave(right!!))

        return 1 + maxLevel
    }
}