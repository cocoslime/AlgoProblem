package leetcode.prob997

class Solution {
    fun findJudge(n: Int, trust: Array<IntArray>): Int {
        val canBeJudge = Array<Boolean>(n){ true }
        val trustCount = Array<Int>(n){0}

        for (direction in trust) {
            val a = direction[0] - 1
            val b = direction[1] - 1

            canBeJudge[a] = false
            trustCount[b]++
        }

        var judgeCandidate = -1
        for (i in 0 until n) {
            if (canBeJudge[i] && trustCount[i] == n - 1) {
                if (judgeCandidate == -1) judgeCandidate = i + 1
                else return -1
            }
        }
        return judgeCandidate
    }
}