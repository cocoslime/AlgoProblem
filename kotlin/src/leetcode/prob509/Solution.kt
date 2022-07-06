package leetcode.prob509

class Solution {
    fun fib(n: Int): Int {
        if (n <= 1) return n
        var first : Int = 1
        var second : Int = 0
        var current = 1

        while (current < n) {
            first = second.also { second = first }
            first += second
            current++
        }
        return first
    }
}