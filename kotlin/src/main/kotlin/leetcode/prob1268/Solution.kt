package leetcode.prob1268

class Solution {
    fun suggestedProducts(products: Array<String>, searchWord: String): List<List<String>> {
        val sorted = products.sorted()
        val result = mutableListOf<List<String>>()
        var candidate = sorted
        searchWord.forEachIndexed { index, c ->
            val current = searchWord.substring(0, index + 1)
            val filtered = candidate.filter { it.startsWith(current) }
            result.add(filtered.take(3))
            candidate = filtered
        }
        return result
    }
}