package leetcode.prob1423

class Solution {
    fun maxScore(cardPoints: IntArray, k: Int): Int {
        val invK = cardPoints.size - k
        val totalSum = cardPoints.sum()

        if (k == cardPoints.size) return totalSum

        var windowSum = cardPoints.take(invK).sum()
        var minimum = windowSum
        println(minimum)

        for (i in invK until cardPoints.size) {
            windowSum = windowSum + cardPoints[i] - cardPoints[i - invK]
            println(windowSum)
            minimum = kotlin.math.min(minimum, windowSum)
        }

        return totalSum - minimum
    }
}