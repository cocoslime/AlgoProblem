package leetcode.prob763

class Solution {
    fun partitionLabels(s: String): List<Int> {
        val map = HashMap<Char, Int>()
        var currGroup = 0
        val mark = mutableListOf<Int>()

        s.forEachIndexed { index, it ->
            if (map.containsKey(it)) {
                val groupIndex = map[it]!!
                val startIndex = mark.binarySearch (
                    groupIndex
                )

                if (startIndex < 0)
                    throw IllegalStateException("$startIndex, $groupIndex, $index, $it\n${mark}")

                for (i in startIndex until index) {
                    mark[i] = groupIndex
                    map[s[i]] = groupIndex
                }
                currGroup = groupIndex
            }
            map[it] = currGroup
            mark.add(currGroup++)
        }

        val result = mark.groupBy {
            it
        }.map { it.value.size}

        return result
    }
}

fun main(){
    println(Solution().partitionLabels("ababcbacadefegdehijhklij"))
}