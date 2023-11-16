package acmicpc

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val stolenPassports = generateSequence { readLine() }.take(n).toList().sorted()
    val m = readLine()!!.toInt()

    var count = 0
    for (i in 0 until m) {
        val passport = readLine()

        val index = stolenPassports.binarySearch(passport)
        if (index >= 0) {
            count++
        }
    }

    println(count)
}
