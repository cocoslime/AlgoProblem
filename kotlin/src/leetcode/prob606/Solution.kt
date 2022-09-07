package leetcode.prob606

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
    fun tree2str(root: TreeNode?): String {
        val result = root?.let{
            val buffer = StringBuffer(it.`val`.toString())
            buffer.append(it.left?.let{ left ->
                "(" + tree2str(left) + ")"
            } ?: "")
            buffer.append(it.right?.let{ right ->
                val pre = if (it.left == null) "()" else ""
                pre + "(" + tree2str(right) + ")"
            } ?: "")
            buffer.toString()
        } ?: ""
        return result
    }
}