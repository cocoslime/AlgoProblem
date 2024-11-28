package leetcode.prob557

class Solution {
    fun reverseWords(s: String): String {
        val array = s.toCharArray()

        var start = 0
        for ((index, ch) in s.withIndex()) {
            if (ch == ' ') {
                swap(array, start, index - 1)
                start = index + 1
            }
        }

        swap(array, start, array.size - 1)

        val buffer = StringBuffer(array.size)
        array.forEach { buffer.append(it) }
        return buffer.toString()
    }

    fun swap(array: CharArray, start : Int, end : Int) {
        if (start > end) return

        for (i in start until end / 2) {
            val opposite = end - i

            val temp = array[i]
            array[i] = array[opposite]
            array[opposite] = temp
        }
    }
}