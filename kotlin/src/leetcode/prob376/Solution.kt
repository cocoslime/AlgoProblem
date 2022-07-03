package leetcode.prob376

import java.util.*

class Solution {
    fun wiggleMaxLength(nums: IntArray): Int {
        val queue : Deque<Int> = LinkedList<Int>()
        var wasPositive : Boolean? = null

        nums.forEach {
            if (queue.isEmpty()) queue.add(it)
            else {
                if (queue.last() != it){
                    if (wasPositive == null){
                        wasPositive = queue.last() < it
                        queue.add(it)
                    }
                    else {
                        if (wasPositive!!){
                            if (queue.last() < it) {
                                queue.pollLast()
                            }
                            else{
                                wasPositive = false
                            }
                            queue.add(it)
                        }
                        else {
                            if (queue.last() > it) {
                                queue.pollLast()
                            }
                            else{
                                wasPositive = true
                            }
                            queue.add(it)
                        }
                    }
                }
            }
        }

        return queue.size
    }
}