package acmicpc

fun main() {
    val n = readLine()!!.toInt()
    val array = mutableListOf<Pair<Int, Int>>()

    for (i in 0 until n) {
        val (x, height) = readLine()!!.split(" ").map { it.toInt() }
        array.add(Pair(x, height))
    }

    array.sortBy { it.first }

    var prev : Pair<Int, Int>? = null
    var minimum = Int.MAX_VALUE

    for (i in 0 until n) {
        val (x, height) = array[i]

        if (prev != null) {
            val prevLifeTime = (prev.second - 1) / 2
            val prevRight = prevLifeTime + prev.first
            val currentLifeTime = (height - 1) / 2
            val currentLeft = x - currentLifeTime

            if (prevRight >= currentLeft) {
                val interval = (x - prev.first - 1) / 2

                if (interval < prevLifeTime && interval < currentLifeTime) {
                    minimum = minOf(interval, minimum)
                } else {
                    minimum = minOf(
                        (x - prev.first - 1) - minOf(prevLifeTime, currentLifeTime),
                        minimum
                    )
                }
            }
        }

        prev = Pair(x, height)
    }

    if (minimum == Int.MAX_VALUE) {
        print("forever")
    } else {
        print(minimum)
    }
}