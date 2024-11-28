package leetcode.prob141


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun hasCycle(head: ListNode?): Boolean {
        var node1 = head
        var node2 = head?.next?.next

        if (node2 == null) return false

        while (node2 != null && node1 != null)
        {
            if (node1 == node2)
                return true
            node2 = node2.next?.next
            node1 = node1.next
        }

        return false
    }
}