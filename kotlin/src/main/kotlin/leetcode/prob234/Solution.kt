package leetcode.prob234

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
    var current = true

    fun isPalindrome(head: ListNode?): Boolean {
        val mid = findMid(head!!)
        helper(head, mid!!)
        return current
    }

    fun helper(front : ListNode, back : ListNode) : ListNode? {
        if (!current) return null

        val nextBack = back.next

        if (nextBack == null) {
            current = front.`val` == back.`val`
            return front.next
        }
        else {
            val nextFront = helper(front, nextBack) ?: return null
            if (!current) return null

            current = nextFront.`val` == back.`val`
            return nextFront.next
        }
    }

    private fun findMid(head: ListNode) : ListNode? {
        var slow : ListNode? = head
        var fast : ListNode? = head

        while (slow?.next != null && fast?.next != null) {
            slow = slow.next
            fast = fast.next?.next
        }

        return slow
    }
}