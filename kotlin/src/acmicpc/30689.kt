package acmicpc

val MAX_N = 2002
val map = Array(MAX_N) {
    Array(MAX_N) {
        0
    }
}
val cost = Array(MAX_N) {
    Array(MAX_N) {
        0
    }
}

fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }

    for (i in 0 until n) {
        val line = readLine()!!
        for (j in 0 until m) {
            map[i + 1][j + 1] = when(line[j]) {
                'U' -> 1
                'D' -> 2
                'L' -> 3
                'R' -> 4
                else -> 0
            }
        }
    }
    for (i in 0 until n) {
        val line = readln().split(" ").map { it.toInt() }
        for (j in 0 until m) {
            cost[i + 1][j + 1] = line[j]
        }
    }

    var totalCost = 0
    for (i in 1..n) {
        for (j in 1..m) {
            if (cost[i][j] != 0) {
                val cost = checkMap(i, j, Array(n + 2) { BooleanArray(m + 2) {false} }).minimum
//                println("${i} ${j} ${cost}\n====================")
                totalCost += cost
            }
        }
    }

    println(totalCost)
}

fun checkMap(i: Int, j: Int, isChecked: Array<BooleanArray>): Result {
    if (isChecked[i][j]) {
        return Result(i, j, cost[i][j])
    } else if (cost[i][j] == 0) {
        return Result.ZERO
    }

    isChecked[i][j] = true

    val next = when(map[i][j]) {
        1 -> {
            checkMap(i - 1, j, isChecked)
        }
        2 -> {
            checkMap(i + 1, j, isChecked)
        }
        3 -> {
            checkMap(i, j - 1, isChecked)
        }
        4 -> {
            checkMap(i, j + 1, isChecked)
        }
        else -> {
            throw IllegalStateException("")
        }
    }

//    println("$i $j ${next}")

    val currentCost = cost[i][j]
    cost[i][j] = 0

    if (next.minimum == 0 || (next.startI == 0 && next.startJ == 0)) {
        return next
    } else if (next.startI == i && next.startJ == j) {
        return Result(0, 0, next.minimum)
    } else {
        next.minimum = minOf(next.minimum, currentCost)
        return next
    }
}

data class Result(val startI: Int, val startJ: Int, var minimum: Int) {
    companion object {
        val ZERO = Result(0, 0, 0)
    }
}
