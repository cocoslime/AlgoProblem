package acmicpc

fun main() {
    val n = readLine()!!.toInt()
    if (n == 1) {
        readLine()
        print(1)
        return
    }

    val array = readLine()!!.split(" ").map { it.toInt() }
    val dp = mutableListOf<Pair<Int, Int>>()

    var partCount = 1
    var current = array[0]
    for (i in 1 until n) {
        if (array[i] != current) {
            dp.add(Pair(current, partCount))
            partCount = 1
            current = array[i]
        } else {
            partCount++
        }
    }
    dp.add(Pair(current, partCount))

    if (dp.size == 1) {
        print(dp[0].second)
        return
    } else if (dp.size == 2) {
        print(dp[0].second + dp[1].second)
        return
    }

    var longestPair = listOf(dp[0].first, dp[1].first)
    var globalMax = dp[0].second + dp[1].second
    var localMax = globalMax

    for (i in 2 until dp.size) {
        if (longestPair.contains(dp[i].first)) {
            localMax += dp[i].second
        } else {
            longestPair = listOf(dp[i - 1].first, dp[i].first)
            localMax = dp[i - 1].second + dp[i].second
        }
        if (localMax > globalMax) {
            globalMax = localMax
        }
    }

    print(globalMax)
}