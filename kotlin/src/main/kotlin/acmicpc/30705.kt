package acmicpc

fun main() {
    val (buildingCount, days) = readLine()!!.split(" ").map { it.toInt() }
    var needCount = 0L
    var remain = 0L

    val roads = mutableListOf<Pair<Int, Int>>()

    repeat(days) {
        val (start, end) = readLine()!!.split(" ").map { it.toInt() - 1 }

        remain += 1L
        var currentNeed = 0L

        val startIndex = roads.binarySearch { pair ->
            if (pair.second < start) {
                -1
            } else if (pair.first > start) {
                1
            } else {
                0
            }
        }

        val endIndex = roads.binarySearch { pair ->
            if (pair.second < end) {
                -1
            } else if (pair.first > end) {
                1
            } else {
                0
            }
        }

        // calculate currentNeed
        val minimumStart: Int
        val maximumEnd: Int
        val startInsertion = if (startIndex < 0) -(startIndex + 1) else startIndex
        val endInsertion = if (endIndex < 0) -(endIndex + 1) else endIndex + 1

        if (startIndex >= 0 && endIndex >= 0) {
            minimumStart = minOf(start, roads[startIndex].first)
            maximumEnd = maxOf(end, roads[endIndex].second)

            for (i in startIndex + 1 .. endIndex) {
                currentNeed += roads[i].first - roads[i - 1].second
            }
        } else if (startIndex < 0 && endIndex >= 0) {
            minimumStart = start
            maximumEnd = roads[endIndex].second

            var lastEnd = start
            for (i in startInsertion .. endIndex) {
                currentNeed += roads[i].first - lastEnd
                lastEnd = roads[i].second
            }
        } else if (startIndex >= 0 && endIndex < 0) {
            minimumStart = roads[startIndex].first
            maximumEnd = end

            var lastEnd = roads[startIndex].second
            for (i in startIndex + 1 until endInsertion) {
                currentNeed += roads[i].first - lastEnd
                lastEnd = roads[i].second
            }
            currentNeed += end - lastEnd
        } else { // startIndex < 0 && endIndex < 0
            minimumStart = start
            maximumEnd = end

            var lastEnd = start
            for (i in startInsertion until endInsertion) {
                currentNeed += roads[i].first - lastEnd
                lastEnd = roads[i].second
            }
            currentNeed += end - lastEnd
        }

        // replace roads[startIndex, endIndex)
        roads.subList(startInsertion, endInsertion).clear()
        roads.addAll(startInsertion, listOf(minimumStart to maximumEnd))

        val result: Long

        if (remain <= currentNeed) {
            result = currentNeed - remain
            remain = 0L
        } else {
            remain -= currentNeed
            result = 0L
        }

        needCount += result

//        println("startIndex: $startIndex, endIndex: $endIndex")
//        println("currentNeed: $currentNeed, result: $result")
//        println("($start, $end) remain: $remain, needCount: $needCount")
    }
    print(needCount)
}


/*
6 3
2 4
3 4
2 5
1


 */