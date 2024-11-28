package acmicpc

import java.util.PriorityQueue

fun main() {
    val input = readLine()!!.split(" ")
    val roomCount = input[0].toInt()
    var power = input[1].toLong()

    val monsters = PriorityQueue<Long>()
    val weapons = PriorityQueue<Long>()

    for (i in 0 until roomCount) {
        val lines = readLine()!!.split(" ")
        if (lines[0] == "1") {
            monsters.add(lines[1].toLong())
        } else {
            weapons.add(lines[1].toLong())
        }
    }

    var count = 0
    while (monsters.isNotEmpty() || weapons.isNotEmpty()) {
        if (monsters.isNotEmpty() && power > monsters.peek()) {
            power += monsters.poll()
            count++
        } else if (weapons.isNotEmpty()){
            power *= weapons.poll()
            count++
        } else {
            break
        }
    }

    print(count)
}