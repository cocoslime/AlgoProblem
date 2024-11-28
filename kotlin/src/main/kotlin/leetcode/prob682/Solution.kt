package leetcode.prob682

class Solution {
    fun calPoints(ops: Array<String>): Int {
        val record = mutableListOf<Int>()
        ops.forEach {
            when(it){
                "+"->{
                    val newScore = record[record.size - 1] + record[record.size - 2]
                    record.add(newScore)
                }
                "D"->{
                    val newScore = record.last() * 2
                    record.add(newScore)
                }
                "C"->{
                    record.removeAt(record.size - 1)
                }
                else ->{
                    record.add(it.toInt())
                }
            }
        }

        return record.sum()
    }
}