package leetcode.prob630

import java.util.PriorityQueue

class Solution {
    fun scheduleCourse(courses: Array<IntArray>): Int {
//        val sortedCourses = courses.sortedWith(compareBy({it[0]}, {it[1]}))
        val sortedCourses = courses.sortedBy { it[1] }
        val priorityQueue = PriorityQueue<Int>()
        var sum = 0
        sortedCourses.forEach {
            sum += it[0]
            priorityQueue.add(-it[0])
            if (sum > it[1]){
                val popped = -priorityQueue.poll()
                sum -= popped
            }
        }

        return priorityQueue.size
    }

}