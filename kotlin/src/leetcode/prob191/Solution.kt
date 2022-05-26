package leetcode.prob191

class Solution {
    // you need treat n as an unsigned value
    fun hammingWeight(n:Int):Int {
        if (n < 0) {
            val newN = Int.MAX_VALUE + n + 1
            return 1 + hammingWeight(newN)
        }
        else if (n <= 1){
            return n
        }
        else {
            return n % 2 + hammingWeight(n / 2)
        }
    }

}