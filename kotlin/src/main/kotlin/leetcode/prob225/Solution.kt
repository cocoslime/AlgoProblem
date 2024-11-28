package leetcode.prob225

import java.util.LinkedList
import java.util.Queue

class MyStack() {
    var queue : Queue<Int> = LinkedList<Int>()

    fun push(x: Int) {
        val newQueue : Queue<Int> = LinkedList<Int>()
        newQueue.add(x)

        queue.forEach { newQueue.add(it) }
        queue = newQueue
    }

    fun pop(): Int {
        return queue.poll()
    }

    fun top(): Int {
        return queue.peek()
    }

    fun empty(): Boolean {
        return queue.isEmpty()
    }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */