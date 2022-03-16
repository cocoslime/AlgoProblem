package leetcode.prob39

class Solution {
    val results : MutableList<List<Int>> = mutableListOf()

    fun findList(source : MutableList<Int>, result : MutableList<Int>, remainTarget : Int) {
        if (remainTarget == 0){
            results.add(result)
        }

        if (source.isEmpty())
            return
        if (source[0] > remainTarget)
            return

//        source.forEach { print("$it,") }
//        println()
//        result.forEach { print("$it,") }
//        println()
//        print("remain : $remainTarget\n")

        val result1 = result.toMutableList()
        // put no-remove
        result1.add(source[0])
        findList(source, result1, remainTarget - source[0])

        // no-put remove
        val newSource = source.toMutableList()
        newSource.removeAt(0)
        findList(newSource, result, remainTarget)

    }

    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        candidates.sort()
        findList(candidates.toMutableList(), mutableListOf(), target)

        return this.results
    }
}

fun main(args: Array<String>){
    val sol = Solution()
    val result = sol.combinationSum(candidates = intArrayOf(2,3,6,7), target = 7)
    for (i in result){
        i.forEach{print(it)}
        println()
    }
}