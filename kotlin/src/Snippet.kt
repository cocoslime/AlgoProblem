fun swap() {
    var a = 1
    var b = 2

    a = b.also { b = a }
}

fun readLinesToList() {
    val input = generateSequence (::readLine)
    val lines = input.toList()

}


// Aggregate example

data class User(
    val login: String,
    val contributions: Int
)

fun List<User>.aggregate(): List<User> =
    groupBy { it.login }
        .map { (login, group) -> User(login, group.sumOf { it.contributions }) }
        .sortedByDescending { it.contributions }

fun <T : Comparable<T>> nextPermutation(array: Array<T>): Boolean {
    // 1. 뒤쪽부터 탐색하며, 교환 위치(i - 1) 찾기: 처음으로 a[i - 1] < a[i]를 만족하는 위치
    val i = (array.size - 1 downTo 1).find { array[it - 1] < array[it] } ?: return false

    // 2. 뒤쪽부터 탐색하며, 교환 위치(i - 1)와 교환할 큰 수 찾기: 처음으로 a[i - 1] < a[j]를 만족하는 위치
    val j = (array.size - 1 downTo i).find { array[it] > array[i - 1] }!!

    // 3. i - 1 위치값과 j 위치값 교환
    array.swap(i - 1, j)

    // 4. i부터 맨 끝까지 순서 뒤집기(오름차순 정렬)
    array.reverse(i, array.size)

    return true
}

// Swap function for two elements of an array
fun <T> Array<T>.swap(i: Int, j: Int) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}

// Reverse function for a portion of an array
fun <T> Array<T>.reverse(fromIndex: Int, toIndex: Int) {
    val subList = this.sliceArray(fromIndex until toIndex)
    for (i in fromIndex until toIndex) {
        this[i] = subList[toIndex - i - 1 + fromIndex]
    }
}
