package leetcode.prob1996
class Solution {
    fun numberOfWeakCharacters(properties: Array<IntArray>): Int {
        val sorted = properties.sortedWith(compareByDescending<IntArray>{it[0]}.thenBy { it[1] })

        var maxY = sorted[0][1]
        var weak = 0

        for (i in sorted.indices) {
            if (sorted[i][1] < maxY) {
                weak++
            }
            else if (sorted[i][1] > maxY) {
                maxY = sorted[i][1]
            }
        }

        return weak
    }
}