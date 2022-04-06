package leetcode.prob923

import kotlin.math.pow

class Solution {
    fun threeSumMulti(arr: IntArray, target: Int): Int {
        val map = arr.toList().groupBy {
            it
        }.map {
            it.key to it.value.size.toLong()
        }.toMap()

        val modular = (10.toDouble().pow(9) + 7).toLong()
        val keyList = map.keys.toList()
        var result = 0L
        for (i in keyList.indices) {
            for (j in i until keyList.size) {
                for (k in j until keyList.size) {
                    if (keyList[i] + keyList[j] + keyList[k] == target) {
                        if (i == j && j == k){
                            val valueI = map[keyList[i]]!!
                            result += combination(valueI, 3)
                        } else if (i == j){
                            val valueI = map[keyList[i]]!!
                            val valueK = map[keyList[k]]!!
                            result += combination(valueI, 2) * valueK
                        } else if (j == k){
                            val valueJ = map[keyList[j]]!!
                            val valueI = map[keyList[i]]!!
                            result += combination(valueJ, 2) * valueI
                        } else {
                            val valueI = map[keyList[i]]!!
                            val valueJ = map[keyList[j]]!!
                            val valueK = map[keyList[k]]!!
                            result += valueI * valueJ * valueK
                        }

                        result %= modular
                    }
                }
            }
        }
        return result.toInt()
    }

    private fun combination(n : Long, r : Long) : Long {
        if (n == r) return 1
        else if (n < r) return 0

        var result = 1L
        for (i in n downTo n - r + 1)
            result *= i
        for (i in r downTo 1 )
            result /= i
        return result
    }

}

fun main() {
    Solution().threeSumMulti(intArrayOf(1, 1, 2, 2, 2, 2), 5)
}