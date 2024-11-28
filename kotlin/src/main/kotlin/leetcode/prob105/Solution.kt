package leetcode.prob105

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

fun makeTreeNode(list: List<Int?>): TreeNode? {
    val treeNodeList = mutableListOf<TreeNode?>()
    for (i in 0 until list.size) {
        if (list[i] == null){
            treeNodeList.add(null)
        }
        else
            treeNodeList.add(TreeNode(list[i] as Int))
    }
    for (i in 0 until list.size) {
        if (treeNodeList[i] != null){
            if ((i + 1) * 2 - 1 < list.size) {
                treeNodeList[i]!!.left = treeNodeList[(i + 1) * 2 - 1]
            }
            if ((i + 1) * 2 < list.size){
                treeNodeList[i]!!.right = treeNodeList[(i + 1) * 2]
            }
        }
    }
    return treeNodeList[0]
}


class Solution {
    var preorderCurrent = 0

    fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
        if (inorder.size == 0) return null

        val pre = preorder[preorderCurrent++]
        val root = TreeNode(pre)
        val idx = inorder.indexOf ( pre )

        if (idx == 0 && inorder.size == 1) return root
        else if (idx < 0) throw IllegalStateException("")

        val left = buildTree(preorder, inorder.sliceArray(0 until idx))
        left?.let{
            root.left = it
        }

        val right = buildTree(preorder, inorder.sliceArray(idx + 1 until inorder.size))
        right?.let{
            root.right = it
        }

        return root
    }
}