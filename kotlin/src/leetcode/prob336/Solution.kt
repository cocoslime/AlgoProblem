package leetcode.prob336

fun isPalindrome(s : String, start : Int = 0, end : Int = s.length - 1) : Boolean {
    var i = start
    var j = end

    if (i > j) return false
    while (i < j) {
        if (s[i] != s[j]) return false
        i++
        j--
    }
    return true
}

class TrieNode<T> {
    var index : T? = null
    val children : Array<TrieNode<T>?> = Array(30){ null }
    val palindromeChildren = mutableListOf<Int>()
}

class Solution {
    val root = TrieNode<Int>()
    val answer = mutableSetOf<Pair<Int, Int>>()

    // save word from backward
    fun add(s: String, indexCandidate: Int) {
        if (isPalindrome(s)) root.palindromeChildren.add(indexCandidate)

        var current = root
        for (i in s.length - 1 downTo 0) {
            val charIdx = s[i] - 'a'

            if (current.children[charIdx] == null) current.children[charIdx] = TrieNode()
            if (isPalindrome(s, 0, i - 1)) {
                current.children[charIdx]!!.palindromeChildren.add(indexCandidate)
            }
            current = current.children[charIdx]!!
        }
        current.index = indexCandidate
    }

    fun addToAnswer(first: Int, second: Int) {
        if (first != second) answer.add(first to second)
    }

    fun palindromePairs(words: Array<String>): List<List<Int>> {
        for ((index, word) in words.withIndex()) {
            add(word, index)
        }

        for ((index, word) in words.withIndex()) {
            root.index?.let { if (isPalindrome(word)) addToAnswer(index, it) }

            var current: TrieNode<Int> = root
            var i = 0
            while (i < word.length) {
                val c = word[i]

                current.children[c - 'a']?.let {
                    it.index?.let { currentIndex ->
                        if (i + 1 == word.length || isPalindrome(word, start = i + 1)) addToAnswer(index, currentIndex)
                    }
                    current = it
                } ?: break

                i++
            }

            if (i == word.length) {
                current.palindromeChildren.forEach{
                    addToAnswer(index, it)
                }
            }
        }

        return answer.map { listOf(it.first, it.second) }.toList()
    }
}

fun main(){
    Solution().palindromePairs(emptyArray())
}