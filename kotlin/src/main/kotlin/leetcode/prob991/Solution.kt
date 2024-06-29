package leetcode.prob991

class Solution {
    fun brokenCalc(startValue: Int, target: Int): Int {
        if (startValue >= target) return startValue - target

        var result = 0
        var currentTarget = target
        while (currentTarget != startValue) {
            if (currentTarget > startValue) {
                result += currentTarget % 2
                currentTarget += currentTarget % 2
                result++
                currentTarget /= 2
            }
            else {
                result += startValue - currentTarget
                return result
            }
        }
        return result
    }
}

fun main(){
    println(Solution().brokenCalc(2, 3))
}