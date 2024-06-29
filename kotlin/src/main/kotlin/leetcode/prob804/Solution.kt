package leetcode.prob804

class Solution {
    fun uniqueMorseRepresentations(words: Array<String>): Int {
        val morse = arrayOf(".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..")

        val morseWords = words.map {word ->
            word.map {
                val idx = it - 'a'
                morse[idx]
            }.reduce { acc, s ->
                acc + s
            }
        }

        return morseWords.toSet().size
    }
}