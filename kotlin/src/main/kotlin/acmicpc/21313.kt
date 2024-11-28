package acmicpc

fun main() {
    // 4 <= n <= 1000
    val n = readLine()!!.toInt()
    val pair = "1 2 "
    println(pair.repeat(n / 2).plus(
        if (n % 2 != 0) {
            "3"
        } else {
            ""
        }
    ))
}