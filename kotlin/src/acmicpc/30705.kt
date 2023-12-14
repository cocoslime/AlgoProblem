package acmicpc

fun main() {
    val (buildingCount, days) = readLine()!!.split(" ").map { it.toInt() }
    var needCount = 0
    var remain = 0
    val roads = Array(buildingCount) { false }
    repeat(days) {
        val (start, end) = readLine()!!.split(" ").map { it.toInt() - 1 }

        remain += 1
        var currentNeed = 0
        for (i in start until end) {
            if (!roads[i]) {
                currentNeed++
                roads[i] = true
            }
        }

        if (remain <= currentNeed) {
            currentNeed -= remain
            remain = 0
        } else {
            remain -= currentNeed
            currentNeed = 0
        }

        if (currentNeed == 0) {
            remain += 1
        } else {
            needCount += currentNeed
        }
    }
    print(needCount)
}