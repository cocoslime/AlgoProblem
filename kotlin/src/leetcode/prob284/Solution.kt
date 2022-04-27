package leetcode.prob284

// Kotlin Iterator reference:
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-iterator/

class PeekingIterator(iterator:Iterator<Int>):Iterator<Int> {
    var next : Boolean
    var current : Int
    val iterator : Iterator<Int>

    init {
        this.iterator = iterator
        current = iterator.next()
        next = true
    }

    fun peek(): Int {
        return current
    }

    override fun next(): Int {
        val result = current
        if (iterator.hasNext())
            current = iterator.next()
        else
            next = false
        return result
    }

    override fun hasNext(): Boolean {
        return next
    }
}

/**
 * Your PeekingIterator object will be instantiated and called as such:
 * var obj = PeekingIterator(arr)
 * var param_1 = obj.next()
 * var param_2 = obj.peek()
 * var param_3 = obj.hasNext()
 */