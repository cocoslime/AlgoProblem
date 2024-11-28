package leetcode.prob2359

class Solution {
    fun closestMeetingNode(edges: IntArray, node1: Int, node2: Int): Int {
        val count1 = Array<Int>(edges.size){ -1 }

        var current = node1
        var distance = 0
        while (count1[current] == -1) {
            count1[current] = distance++
            if (edges[current] != -1) {
                current = edges[current]
            } else {
                break
            }
        }

        val count2 = Array<Int>(edges.size){ -1 }
        current = node2
        distance = 0
        while (count2[current] == -1) {
            count2[current] = distance++
            if (edges[current] != -1) {
                current = edges[current]
            } else {
                break
            }
        }


        var minIndex = -1
        var minValue = Int.MAX_VALUE
        for (i in edges.indices) {
            if (count1[i] != -1 && count2[i] != -1) {
                val value = kotlin.math.max(count1[i], count2[i])
                if (value < minValue) {
                    minIndex = i
                    minValue = value
                }
            }
        }

        return minIndex
    }
}