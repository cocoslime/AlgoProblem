
class Solution {
    fun maxArea(height: IntArray): Int {
        val n = height.size
        var maxArea = 0
        for (width in 1 until n) {
            for (start in 0 until n - width){
                val end = start + width
                val area = width * minOf(height[start], height[end])
                maxArea = maxOf(area, maxArea)
            }
        }
        return maxArea
    }
}

fun main(){
    Solution().maxArea(intArrayOf(1,8,6,2,5,4,8,3,7))
}