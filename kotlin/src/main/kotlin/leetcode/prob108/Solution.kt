package leetcode.prob108

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
    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        return when (nums.size) {
            0 -> null
            1 -> TreeNode(nums[0])
            else -> {
                val rootIdx = nums.size / 2
                val root = TreeNode(nums[rootIdx])
                root.left = sortedArrayToBST(nums.sliceArray(0 until rootIdx + 1))
                root.right = sortedArrayToBST(nums.sliceArray(rootIdx + 1 until nums.size + 1))
                return root
            }
        }
    }
}