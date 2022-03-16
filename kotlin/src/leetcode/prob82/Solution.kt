package leetcode.prob82

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun deleteDuplicates(head: ListNode?): ListNode? {
        val preHead = ListNode(1000)
        preHead.next = head

        var currPrevNode : ListNode = preHead
        var currNode : ListNode? = head
        while (currNode != null) {
            var nextNode = currNode

            while (nextNode?.`val` == currNode.`val`){
                nextNode = nextNode.next
            }

            if (nextNode == currNode.next){
                currPrevNode = currNode
            }
            else{
                currPrevNode.next = nextNode
            }
            currNode = nextNode
        }

        return preHead.next
    }
}