package acmicpc

import kotlin.math.abs

fun main() {
    val n = readLine()!!.toInt()
    val initial = readLine()!!.split(" ").map { it.toInt() }
    val target = readLine()!!.split(" ").map { it.toInt() }
    val step = readLine()!!.split(" ").map { it.toInt() }

    var isOdd: Boolean? = null
    var maximum = 0
    for (i in 0 until n) {
        val diff = abs(target[i] - initial[i])
        if (diff % step[i] != 0) {
            print(-1)
            return
        }

        val diffStep = diff / step[i]
        if (diffStep % 2 == 1) {
            if (isOdd == null) {
                isOdd = true
            } else if (!isOdd) {
                print(-1)
                return
            }
        } else {
            if (isOdd == null) {
                isOdd = false
            } else if (isOdd) {
                print(-1)
                return
            }
        }

        maximum = maxOf(maximum, diffStep)
    }

    print(maximum)
}