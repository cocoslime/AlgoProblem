package leetcode.prob347

class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        val map = hashMapOf<Int, Int>()
        nums.forEach {
            if (map[it] == null)
                map[it] = 0
            map[it] = map[it]!! + 1
        }

        val sorted = map.toList().sortedByDescending { it.second }
        return sorted.take(k).map{ it.first }.toIntArray()
    }
}