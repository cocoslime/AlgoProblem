package leetcode.prob669


class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}

class Solution {
    fun trimBST(root: TreeNode?, low: Int, high: Int): TreeNode? {
        if (root == null) return null

        if (root.`val` < low)
            return trimBST(root.right, low, high)
        if (root.`val` > high)
            return trimBST(root.left, low, high)

        root.left = trimBST(root.left, low, high)
        root.right = trimBST(root.right, low, high)

        return root
    }
}