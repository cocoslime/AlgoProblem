package leetcode.prob1202

/**
 * Union-Find
 */
class Solution {
    lateinit var parents : Array<Int>

    fun smallestStringWithSwaps(s: String, pairs: List<List<Int>>): String {
        val resultList = s.map { it }.toMutableList()

        parents = s.mapIndexed { index, c -> index }.toTypedArray()

        pairs.forEach {
            val src = it[0]
            val dest = it[1]
            union(src, dest)
        }

        val groups = mutableMapOf<Int, MutableList<Int>>()
        resultList.forEachIndexed { index, c ->
            val parent = find(index)
            val group = groups[parent]
            if (group == null)
                groups[parent] = mutableListOf()
            groups[parent]?.add(index)
        }

        groups.forEach { entry ->
            val group = entry.value.sorted()
            val charSortedList = group.map{
                s[it]
            }.sortedBy { it }

            group.forEachIndexed { index, loc ->
                resultList[loc] = charSortedList[index]
            }
        }

        return String(resultList.toCharArray())
    }

    private fun union(a : Int, b : Int) {
        val rootA = find(a)
        val rootB = find(b)

        if (rootA != rootB) {
            parents[rootA] = rootB
        }
    }

    private fun find(idx : Int) : Int{
        if (parents[idx] == idx)
            return idx
        else {
            val parent = find(parents[idx])
            parents[idx] = parent
            return parent
        }
    }

}