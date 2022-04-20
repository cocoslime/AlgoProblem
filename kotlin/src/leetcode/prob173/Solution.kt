package leetcode.prob173

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

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}

// https://leetcode.com/problems/binary-search-tree-iterator/discuss/52525/My-solutions-in-3-languages-with-Stack

class BSTIterator(root: TreeNode?) {
    val stack = LinkedList<TreeNode>()
    init {
        root?.let{
            addAll(it)
        }
    }

    fun addAll(node : TreeNode?) {
        var curr = node
        while (curr != null) {
            stack.add(curr)
            curr = curr.left
        }
    }

    fun next(): Int {
        val pop = stack.pollLast()
        addAll(pop.right)
        return pop.`val`
    }

    fun hasNext(): Boolean {
        return stack.isNotEmpty()
    }

}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */