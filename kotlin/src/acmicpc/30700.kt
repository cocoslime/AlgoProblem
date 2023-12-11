package acmicpc

fun main() {
    val korea = arrayOf('K', 'O', 'R', 'E', 'A')
    val strings = readLine()!!
    var nextIndexToFind = 0
    var count = 0
    strings.forEach {
        if (it == korea[nextIndexToFind]) {
            count++
            nextIndexToFind++
            if (nextIndexToFind >= korea.size) {
                nextIndexToFind = 0
            }
        }
    }

    print(count)
}