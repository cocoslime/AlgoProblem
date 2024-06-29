package acmicpc

fun main() {
    val n = readLine()!!.toInt()
    val bitmapArray = Array(1 shl 10) { 0L }

    for (i in 0 until n) {
        val number = readLine()!!
        val bitmap = getBitmap(number)
        bitmapArray[bitmap]++
    }

    var count = 0L
    for (i in bitmapArray.indices) {
        if (bitmapArray[i] > 0) {
            count += bitmapArray[i] * (bitmapArray[i] - 1) / 2
            for (j in i + 1 until bitmapArray.size) {
                if (i and j > 0) {
                    count += bitmapArray[i] * bitmapArray[j]
                }
            }
        }
    }
    print(count)
}

fun getBitmap(number: String): Int {
    var bitmap = 0
    for (i in number.indices) {
        bitmap = bitmap or (1 shl (number[i] - '0'))
    }
    return bitmap
}