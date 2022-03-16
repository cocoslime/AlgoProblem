package leetcode.prob413

class Solution {
    fun calc(n : Int) : Int {
        val n2 = n - 2
        return n2 * (n2 + 1) / 2
    }

    fun numberOfArithmeticSlices(nums: IntArray): Int {
        if (nums.size < 3) return 0

        var result = 0
        var start = 0
        for (i in 2 until nums.size) {
            if (nums[i-1] - nums[i-2] == nums[i] - nums[i-1]){
                if (i == nums.size - 1) {
                    val n = i + 1 - start // 3 0
                    if (n >= 3) {
                        result += calc(n)
                    }
                }

                // keep going
            }
            else {
                val n = i - start //
                if (n >= 3) {
                    result += calc(n)
                }
                else {

                }

                start = i-1
            }
        }

        return result
    }
}

fun main() {
    println(Solution().numberOfArithmeticSlices(intArrayOf(1,2,3,4)))
}