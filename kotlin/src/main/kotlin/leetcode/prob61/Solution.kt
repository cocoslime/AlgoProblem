package leetcode.prob61


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}


class Solution {
    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        if (head == null) return null

        var size : Int = 1
        var last : ListNode = head
        while (last.next != null) {
            last = last.next!!
            size++
        }

        val inverseK = size - (k % size)
        last.next = head

        var curr : ListNode = head
        repeat(inverseK-1){
            curr = curr.next!!
        }

        val result = curr.next
        curr.next = null
        return result
    }
}
