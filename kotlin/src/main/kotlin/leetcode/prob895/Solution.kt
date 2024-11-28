package leetcode.prob895

import java.lang.Integer.max

class FreqStack() {
    private val map = HashMap<Int, Int>()
    private val stack = mutableListOf<Int>()

    fun push(value: Int) {
        stack.add(value)
        var count = 1
        if (map.containsKey(value)) {
            count += map[value]!!
        }
        map[value] = count
    }

    fun pop(): Int {
        var maxValue = 0
        map.forEach { (key, value) -> maxValue = max(maxValue, value) }

        for (index in stack.size - 1 downTo  0) {
            val value = stack[index]
            if (map[value] == maxValue) {
                map[value] = map[value]!! - 1
                return stack.removeAt(index)
            }
        }

        throw IllegalStateException()
    }

}

/**
 * Your FreqStack object will be instantiated and called as such:
 * var obj = FreqStack()
 * obj.push(`val`)
 * var param_2 = obj.pop()
 */