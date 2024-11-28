package acmicpc

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val flagA = mutableListOf<String>()
    for (i in 0 until n) {
        flagA.add(readLine()!!)
    }

    val flagB = mutableListOf<String>()
    val checked = Array(n) {
        Array(m) {
            false
        }
    }

    for (i in 0 until n) {
        flagB.add(readLine()!!)
    }

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (!checked[i][j]) {
                val colorA = flagA[i][j]
                val colorB = flagB[i][j]
                val stack = mutableListOf<Pair<Int, Int>>()
                stack.add(Pair(i, j))

                while (stack.isNotEmpty()) {
                    val (x, y) = stack.removeAt(stack.size - 1)
                    if (checked[x][y]) {
                        continue
                    }
                    if (flagB[x][y] != colorB) {
                        print("NO")
                        return@main
                    }

                    checked[x][y] = true
                    val direction = listOf(
                        Pair(-1, 0),
                        Pair(1, 0),
                        Pair(0, -1),
                        Pair(0, 1)
                    )
                    for (d in direction) {
                        val (dx, dy) = d
                        if (x + dx in 0 until n && y + dy in 0 until m) {
                            if (!checked[x+dx][y+dy] && flagA[x + dx][y + dy] == colorA) {
                                stack.add(Pair(x + dx, y + dy))
                            }
                        }
                    }
                }
            }
        }
    }

    print("YES")
}
