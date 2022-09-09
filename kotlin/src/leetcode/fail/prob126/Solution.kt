package leetcode.fail.prob126

class Solution {
    val adjList = Array<MutableList<Int>>(501){
        mutableListOf()
    }

    fun findLadders(beginWord: String, endWord: String, wordList: List<String>): List<List<String>> {
        if (endWord !in wordList) return emptyList()

        val newWordList = if (beginWord in wordList){
            wordList
        } else {
            wordList + beginWord
        }

        val beginIdx = newWordList.indexOf(beginWord)
        val endIdx = newWordList.indexOf(endWord)

        for (i in 0 until newWordList.size - 1) {
            for (j in i + 1 until newWordList.size) {
                if (isNeighbor(newWordList[i], newWordList[j])) {
                    adjList[i].add(j)
                    adjList[j].add(i)
                }
            }
        }

        var set = setOf(beginIdx)
        var currentPaths = listOf(listOf(beginIdx))

        for (stage in 0 until newWordList.size) {
            if (currentPaths.isEmpty()) return emptyList()

            val result = mutableListOf<List<Int>>()
            val nextPaths = mutableListOf<List<Int>>()
            var nextSet = set
            for (path in currentPaths) {
                val last = path.last()

                for (neighbor in adjList[last]) {
                    if (neighbor !in set){
                        nextSet = nextSet + neighbor
                        nextPaths.add(path + neighbor)
                        if (neighbor == endIdx)
                            result.add(path + neighbor)
                    }
                }
            }

            if (result.isNotEmpty()) {
                return result.map {
                    it.map {idx ->
                        newWordList[idx]
                    }
                }
            }

            set = nextSet
            currentPaths = nextPaths
        }

        return emptyList()
    }

    private fun isNeighbor(str1 : String, str2 : String) : Boolean {
        var diff = 0
        for (i in str1.indices) {
            if (str1[i] != str2[i]) diff++
            if (diff > 1) return false
        }
        return diff == 1
    }
}