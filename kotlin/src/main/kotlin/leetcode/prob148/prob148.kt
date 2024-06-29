package leetcode.prob148

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
    fun addNext(value : Int) : ListNode{
        next = ListNode(value)
        return next!!
    }
}

class Solution {
    // if end is null, sort until end
    fun mergeSort(head:ListNode, end:ListNode?) : ListNode? {
        if (head.next == end) return head

        var p1 : ListNode = head
        var p2 : ListNode? = head

        while (p2 != end) {
            p1 = p1.next!!
            p2 = p2?.next
            if (p2 == end || p2 == null)
                break
            p2 = p2.next
        }

        val newHead = ListNode(0) // temp
        var curr : ListNode? = newHead
        var s1 = mergeSort(head, p1)
        var s2 = mergeSort(p1, end)

        while (curr != null && s1 != null && s2 != null && s1 != p1 && s2 != end) {
            if (s1.`val` < s2.`val`)
            {
                curr.next = s1
                s1 = s1.next
            }
            else {
                curr.next = s2
                s2 = s2.next
            }
            curr = curr.next
        }

        while (curr != null && s1 != null && s1 != p1) {
            curr.next = s1
            s1 = s1.next
            curr = curr.next
        }

        while (curr != null && s2 != null && s2 != end){
            curr.next = s2
            s2 = s2.next
            curr = curr.next
        }

        curr?.next = end
        return newHead.next
    }

    fun sortList(head: ListNode?): ListNode? {
        if (head == null) return null

        return mergeSort(head, null)
    }
}


fun main(args: Array<String>) {
    val head = ListNode(4)
    head.addNext(2).addNext(1).addNext(3)
    val newHead = Solution().sortList(head)

    var curr = newHead
    while (curr != null)
    {
        print("${curr.`val`},")
        curr = curr.next
    }
}