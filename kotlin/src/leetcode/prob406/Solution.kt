package leetcode.prob406

class Solution {
    fun reconstructQueue(people: Array<IntArray>): Array<IntArray> {
        val comparator = compareByDescending<IntArray> { it[0] }.thenBy{ it[1] }
        val sorted = people.sortedWith(comparator)
        val list = mutableListOf<IntArray>()

        sorted.forEach {
            if (it[1] > list.size){
                list.add(it)
            }
            else{
                list.add(it[1], it)
            }
        }

        println(list)
        return list.toTypedArray()
    }
}