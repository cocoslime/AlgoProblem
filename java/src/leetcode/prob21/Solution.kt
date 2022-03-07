package leetcode.prob21

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
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        val head : ListNode = ListNode(0) // Temp Node

        var currentResultNode : ListNode = head
        var currentFirstListNode = list1
        var currentSecondListNode = list2

        while (currentFirstListNode != null && currentSecondListNode != null) {
            if (currentFirstListNode.`val` < currentSecondListNode.`val`) {
                currentResultNode.next = currentFirstListNode
                currentResultNode = currentResultNode.next!!
                currentFirstListNode = currentFirstListNode.next
            }
            else {
                currentResultNode.next = currentSecondListNode
                currentResultNode = currentResultNode.next!!
                currentSecondListNode = currentSecondListNode.next
            }
        }

        while (currentFirstListNode != null) {
            currentResultNode.next = currentFirstListNode
            currentResultNode = currentResultNode.next!!
            currentFirstListNode = currentFirstListNode.next
        }

        while (currentSecondListNode != null) {
            currentResultNode.next = currentSecondListNode
            currentResultNode = currentResultNode.next!!
            currentSecondListNode = currentSecondListNode.next
        }

        return head.next
    }
}