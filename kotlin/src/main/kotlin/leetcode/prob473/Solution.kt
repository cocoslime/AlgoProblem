package leetcode.prob473

class Solution {
    var target = 0

    fun makesquare(matchsticks: IntArray): Boolean {
        target = matchsticks.sum() / 4
        if (matchsticks.sum() % 4 > 0) return false

        println(target)

        return func(4, matchsticks.asList())
    }

    private fun func(stage : Int, remain : List<Int>) : Boolean{
        if (stage == 0) return remain.isEmpty()
        else {
            if (stage * target != remain.sum()) return false
        }

        val removeCandidate : List<List<Int>> = func2(remain, 0, emptyList(), 0)
        val nextRemainList = mutableListOf<List<Int>>()
        removeCandidate.forEach {
            val newRemain = remain.toMutableList()
            for (i in it.size - 1 downTo 0){
                newRemain.removeAt(it[i])
            }
            nextRemainList.add(newRemain)
        }

        for (i in nextRemainList.indices){
            if (func(stage - 1, nextRemainList[i]))
                return true
        }
        return false
    }

    private fun func2(remain: List<Int>, idx : Int, pickIdxList: List<Int>, currentSum : Int) : List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        if (currentSum == target) return listOf(pickIdxList)
        else if (idx == remain.size) return emptyList()

        result.addAll(func2(remain, idx + 1, pickIdxList, currentSum))
        val mutableNewList = pickIdxList.toMutableList()

        if (currentSum + remain[idx] <= target) {
            mutableNewList.add(idx)
            result.addAll(func2(remain, idx + 1, mutableNewList, currentSum + remain[idx]))
        }

        return result
    }
}