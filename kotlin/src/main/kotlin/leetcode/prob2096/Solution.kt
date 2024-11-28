package leetcode.prob2096
import leetcode.TreeNode
import kotlin.math.min

class Solution {
    fun getDirections(root: TreeNode?, startValue: Int, destValue: Int): String {
        val queue = ArrayDeque<Pair<TreeNode, String>>()
        var startPath: String? = null
        var destPath: String? = null

        queue.add(root!! to "")
        while (queue.isNotEmpty() || !(startPath != null && destPath != null)) {
            val (node, path) = queue.removeFirst()
            if (node.`val` == startValue) {
                startPath = path
            }
            if (node.`val` == destValue) {
                destPath = path
            }

            node.left?.let {
                queue.add(it to (path + "L"))
            }
            node.right?.let {
                queue.add(it to (path + "R"))
            }
        }

        var dropCount = 0
        for (i in 0 until min(startPath.length, destPath.length)) {
            if (startPath[i] != destPath[i]) {
                dropCount = i
                break
            }
            dropCount++
        }

        return String(CharArray(startPath.length - dropCount) { 'U' }) + destPath.drop(dropCount)
    }
}
