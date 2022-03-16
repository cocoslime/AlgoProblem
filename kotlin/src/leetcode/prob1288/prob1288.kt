package leetcode.prob1288

class Solution {
    fun isCover(big : IntArray, small : IntArray) : Boolean {
        return big[0] <= small[0] && big[1] >= small[1]
    }

    fun removeCoveredIntervals(intervals: Array<IntArray>): Int {
        val sortedIntervals = intervals.sortedWith(compareBy<IntArray>{it[0]}.thenByDescending { it[1] })
        val isRemoved = BooleanArray(sortedIntervals.size){false}
        var result = 0

        for (i in 0 until sortedIntervals.size - 1) {
            if (isRemoved[i])
                continue

            for (j in i+1 until sortedIntervals.size) {
                if (isRemoved[j])
                    continue

                if (isCover(sortedIntervals[i], sortedIntervals[j])){
                    isRemoved[j] = true
                    result += 1
                }
            }
        }

        return sortedIntervals.size - result
    }
}


fun main(args: Array<String>){
    val sol = Solution()

    print(sol.removeCoveredIntervals(arrayOf(intArrayOf(1,4),intArrayOf(3,6),intArrayOf(2,8))))
}