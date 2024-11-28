package leetcode.prob622

class MyCircularQueue(k: Int) {
    val maxSize = k
    val data = Array<Int>(k) { 0 }
    var size = 0
    var front = 0
    var back = 0

    fun enQueue(value: Int): Boolean {
        if (isFull()) return false

        data[back++] = value
        if (back == maxSize) back = 0
        size++
        return true
    }

    fun deQueue(): Boolean {
        if (isEmpty()) return false

        front++
        if (front == maxSize) front = 0
        size--
        return true
    }

    fun Front(): Int {
        return if (isEmpty()) -1
        else data[front]
    }

    fun Rear(): Int {
        val index = if (back - 1 < 0) maxSize - 1 else back -1

        return if (isEmpty()) -1
        else data[index]
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    fun isFull(): Boolean {
        return size == maxSize
    }

}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */