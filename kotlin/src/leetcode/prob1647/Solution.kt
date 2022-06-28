package leetcode.prob1647

class Solution {
    fun minDeletions(s: String): Int {
        val charMap = Array<Int>(30){ _ -> 0 }
        s.forEach {
            val idx = (it - 'a')
            charMap[idx]++
        }

        var sortedCharMap = charMap.sortedDescending().toMutableList()
        var minimum = 0

        var i = 0
        while (i < sortedCharMap.size - 1) {
            if (sortedCharMap[i] == 0) return minimum
            else if (sortedCharMap[i] == sortedCharMap[i+1]){
                var beforeI = i + 1
                var isFound = false
                for (newValue in sortedCharMap[i] - 1 downTo 1) {
                    beforeI = sortedCharMap.binarySearch(newValue, compareByDescending { it }, beforeI)

                    if (beforeI > 0){}
                    else {
                        minimum += sortedCharMap[i] - newValue
                        sortedCharMap[i] = newValue
                        sortedCharMap.sortDescending()

                        isFound = true
                        break
                    }
                }

                if (!isFound){
                    minimum += sortedCharMap[i]
                    sortedCharMap[i] = 0
                    sortedCharMap.sortDescending()
                }

            }
            else {
                i++
            }
        }

        return minimum
    }
}