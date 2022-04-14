package leetcode.prob700

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
    fun searchBST(root: TreeNode?, `val`: Int): TreeNode? {
        var node = root
        while (node != null && node.`val` != `val`) {
            if (node.`val` > `val`) {
                node = node.left
            }
            else
                node = node.right
        }
        return node
    }
}