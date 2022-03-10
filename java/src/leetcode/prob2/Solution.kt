package leetcode.prob2

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var node1 = l1
        var node2 = l2
        var curr : ListNode = ListNode(0)
        val head = curr

        while (node1 != null && node2 != null) {
            if (curr.next == null)
                curr.next = ListNode(0)

            val next : ListNode = curr.next!!
            next.`val` += node1.`val` + node2.`val`
            if (next.`val` >= 10){
                next.next = ListNode(1)
                next.`val` -= 10
            }

            node1 = node1.next
            node2 = node2.next
            curr = next
        }

        while (node1 != null) {
            if (curr.next == null)
                curr.next = ListNode(0)
            val next : ListNode = curr.next!!
            next.`val` += node1.`val`
            if (next.`val` >= 10){
                next.next = ListNode(1)
                next.`val` -= 10
            }
            node1 = node1.next
            curr = next
        }

        while (node2 != null) {
            if (curr.next == null)
                curr.next = ListNode(0)
            val next : ListNode = curr.next!!
            next.`val` += node2.`val`
            if (next.`val` >= 10){
                next.next = ListNode(1)
                next.`val` -= 10
            }
            node2 = node2.next
            curr = next
        }

        return head.next
    }
}