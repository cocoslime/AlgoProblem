package leetcode.prob1689

class Solution {
    fun minPartitions(n: String): Int {
        val numList = n.map {
            // char to int
            Character.getNumericValue(it)
        }

        var need = 0
        numList.forEach {
            if (it - need > 0)
                need += it - need
        }

        return need
    }
}