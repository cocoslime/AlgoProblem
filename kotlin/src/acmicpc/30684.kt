package acmicpc

fun main() {
    val n = readLine()!!.toInt()

    val names = mutableListOf<String>()
    for (i in 0 until n) {
        val name = readLine()!!
        if (name.length == 3) {
            names.add(name)
        }
    }

    print(names.sorted().first())
}