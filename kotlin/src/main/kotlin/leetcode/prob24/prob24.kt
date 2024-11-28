package leetcode.prob24

class ListNode(var `val`: Int) {

    var next: ListNode? = null

    fun addNext(`val`: Int) : ListNode {
        next = ListNode(`val`)
        return next as ListNode
    }

    companion object {
        fun print(node: ListNode?) {
            if (node == null) return

            println(node.`val`)
            if (node.next != null)
                print(node.next)
        }
    }
}

class Solution {
    fun swapPair(node: ListNode) : ListNode {
        var second = node.next
        var third = second?.next

        if (second == null)
            return node

        node.next = third
        second.next = node

        return second
    }

    fun swapPairs(head: ListNode?): ListNode? {
        if (head == null)
            return null
        else if (head.next == null)
            return head

        val newHead = swapPair(head)
        var parent = head
        var curr = head.next

        while (parent!= null && curr != null) {
            parent.next = swapPair(curr)

            parent = parent.next?.next
            curr = parent?.next
        }

        return newHead
    }
}


fun main(args: Array<String>){
    val sol = Solution()
    //[2,5,3,4,6,2,2]
    val head = ListNode(2)
    head.addNext(5).addNext(3).addNext(4).addNext(6).addNext(2).addNext(2)
    val newHead = sol.swapPairs(head)
    ListNode.print(newHead)
}