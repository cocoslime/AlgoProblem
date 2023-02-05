package leetcode.prob438

class Solution {
    fun findAnagrams(s: String, p: String): List<Int> {
        val pMap = Array<Int>(30) { 0 }
        for (c in p) {
            pMap[c - 'a']++
        }

        val result = mutableListOf<Int>()
        val window = Array<Int>(30) { 0 }
        for ((index, ch) in s.withIndex()) {
            window[ch - 'a']++
            val popIndex = index - p.length

            if (index < p.length - 1) {
                continue
            } else if (popIndex >= 0){
                val popCh = s[popIndex]
                window[popCh - 'a']--
            }

            if (compareWindow(window, pMap)) {
                result.add(popIndex + 1)
            }
        }

        return result
    }

    private fun compareWindow(a: Array<Int>, b: Array<Int>) : Boolean {
        for (index in a.indices) {
            if (a[index] != b[index]) return false
        }
        return true
    }
}