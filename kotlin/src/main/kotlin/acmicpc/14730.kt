package acmicpc

fun main() {
    val n = readLine()!!.toInt()

    var answer = 0
    for (i in 0 until n) {
        val (c, k) = readLine()!!.split(" ").map { it.toInt() }
        answer += c * k
    }
    print(answer)
}