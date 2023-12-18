package acmicpc

const val X = 1000000007L

fun main() {
    var result = 0L

    // ALPS, AlKor, MatKor
    val (alps, alkor, matkor) = readLine()!!.split(" ").map { it.toInt() }

    val alpsList = mutableListOf<Pair<Long, Long>>()
    val alkorList = mutableListOf<Pair<Long, Long>>()
    val matkorList = mutableListOf<Pair<Long, Long>>()

    repeat(alps) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        alpsList.add(Pair(x, y))
    }
    repeat(alkor) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        alkorList.add(Pair(x, y))
    }
    repeat(matkor) {
        val (cx, cy) = readLine()!!.split(" ").map { it.toLong() }

        for (a in alpsList) {
            val (ax, ay) = a
            for (b in alkorList) {
                val (bx, by) = b
                val lengthA = (bx - ax) * (bx - ax) + (by - ay) * (by - ay)
                val vectorA = (bx - ax) * (-ay) - (by - ay) * (-ax)

                val lengthB = (cx - bx) * (cx - bx) + (cy - by) * (cy - by)
                val lengthC = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy)

                val length = lengthA + lengthB + lengthC
                val crossProduct = vectorA + (bx - ax) * cy - (by - ay) * cx // (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)
                val cost = length + crossProduct

                result += cost
                result %= X
            }
        }
    }

    print(result)
}