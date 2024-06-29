package leetcode.prob936

class Solution {
    var maxStage = 0
    var currentStage = 0

    fun movesToStamp(stamp: String, target: String): IntArray {
        maxStage = target.length * 10

        val s = target.map { '*' }.toMutableList()

        return stampping(stamp, target, s)
    }

    fun stampping(stamp: String, target: String, s:MutableList<Char>) : IntArray {
        if (currentStage++ > maxStage) return intArrayOf()

        for (i in 0 .. target.length - stamp.length) {
            if (canStamp(stamp, target, s, i)) {
                doStamp(stamp, s, i)
                if (s.count { it == '*' } == 0) return intArrayOf(i)

                val nextLevel = stampping(stamp, target, s)
                return if (nextLevel.isEmpty()) intArrayOf()
                else nextLevel + intArrayOf(i)
            }
        }

        return intArrayOf()
    }

    fun canStamp(stamp: String, target: String, s:MutableList<Char>, i : Int) : Boolean {
        var targetIdx = i
        var alreadyStampped = true

        for (stampIdx in stamp.indices){
            if (s[targetIdx] == '*') {
                alreadyStampped = false
                if (stamp[stampIdx] != target[targetIdx]) return false
            }
            targetIdx++
        }
        return !alreadyStampped
    }

    fun doStamp(stamp: String, s:MutableList<Char>, i: Int) {
        var targetIdx = i
        for (stampIdx in stamp.indices){
            if (s[targetIdx] == '*') {
                s[targetIdx] = stamp[stampIdx]
            }
            targetIdx++
        }
    }
}