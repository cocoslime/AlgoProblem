package acmicpc

fun main() {
    val string = readLine()!!
    var total = 0f
    var subjectNum = 0
    for (i in string.indices) {
        val score = when (string[i]) {
            'A' -> 4.0f
            'B' -> 3.0f
            'C' -> 2.0f
            'D' -> 1.0f
            else -> 0.0f
        }

        if (string[i] == '+') continue

        total += if (i + 1 < string.length && string[i + 1] == '+') {
            score + 0.5f
        } else {
            score
        }

        subjectNum++
    }

    print(total / subjectNum)
}