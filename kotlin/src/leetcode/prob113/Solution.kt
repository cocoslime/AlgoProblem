package leetcode.prob113


class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}

class Solution {
    var targetSum = 0

    fun pathSum(root: TreeNode?, targetSum: Int): List<List<Int>> {
        this.targetSum = targetSum
        return recursive(root, 0, emptyList())
    }

    fun recursive(current: TreeNode?, totalSum: Int, totalPath: List<Int>) : List<List<Int>> {
        if (current == null) {
            return emptyList()
        }

        val currentSum = totalSum + current.`val`
        if (current.left == null && current.right == null) {
            return if (currentSum == targetSum) listOf(totalPath.plus(current.`val`))
            else emptyList()
        }
        else {
            val answerCandidate = mutableListOf<List<Int>>()
            current.left?.let{left ->
                val result = recursive(left, currentSum, totalPath.plus(current.`val`))
                if (result.isNotEmpty()) answerCandidate += result
            }
            current.right?.let{right ->
                val result = recursive(right, currentSum, totalPath.plus(current.`val`))
                if (result.isNotEmpty()) answerCandidate += result
            }
            return answerCandidate
        }
    }
}