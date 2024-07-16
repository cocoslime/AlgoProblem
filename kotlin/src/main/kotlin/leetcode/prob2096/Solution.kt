package leetcode.prob2096
import leetcode.TreeNode
import kotlin.math.min

class Solution {
    fun getDirections(root: TreeNode?, startValue: Int, destValue: Int): String {
        val (_, startPath, destPath) = dfs(root!!, startValue, destValue)

        return startPath+destPath
    }

    private fun dfs(node: TreeNode, startValue: Int, destValue: Int): Triple<Boolean, String?, String?> {
        val leftResult = node.left?.let { dfs(it, startValue, destValue) }
        if (leftResult?.first == true) return leftResult
        val rightResult = node.right?.let { dfs(it, startValue, destValue) }
        if (rightResult?.first == true) return rightResult

        val nextSecond = if (leftResult?.second != null) {
            leftResult.second + "U"
        } else if (rightResult?.second != null) {
            rightResult.second + "U"
        } else if (node.`val` == startValue) {
            ""
        } else {
            null
        }
        val nextThird = if (leftResult?.third != null) {
            "L" + leftResult.third
        } else if (rightResult?.third != null) {
            "R" + rightResult.third
        } else if (node.`val` == destValue) {
            ""
        } else null

        return if (nextSecond != null && nextThird != null) Triple(true, nextSecond, nextThird)
        else Triple(false, nextSecond, nextThird)
    }
}
