package leetcode.prob1721

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
    lateinit var frontPrev : ListNode
    lateinit var backPrev : ListNode

    fun swapNodes(head: ListNode?, k: Int): ListNode? {
        if (head == null) return null

        val stubHead = ListNode(0)
        stubHead.next = head

        frontPrev = stubHead

        findFirst(k)
        findBackPrev(stubHead, k)

        swapNextListNode(frontPrev, backPrev)

        return stubHead.next
    }

    private fun swapNextListNode(first : ListNode, second : ListNode) {
        var nextTemp : ListNode? = first.next!!
        first.next = second.next
        second.next = nextTemp

        val firstNext = first.next!!
        val secondNext = second.next!!

        nextTemp = firstNext.next
        firstNext.next = secondNext.next
        secondNext.next = nextTemp
    }

    fun findFirst(k : Int) {
        var temp = frontPrev
        repeat(k - 1) {
            temp = temp.next!!
            frontPrev = temp
        }
    }

    fun findBackPrev(node : ListNode, k : Int) : Int{
        if (node.next == null)
            return 1

        val currentIdx = 1 + findBackPrev(node.next!!, k)
        if (currentIdx == k + 1){
            backPrev = node
        }
        return currentIdx
    }
}


fun ListNode.addNext(`val`: Int) : ListNode {
    next = ListNode(`val`)
    return next as ListNode
}

fun ListNode.print() {
    println(`val`)
    next?.print()
}


fun main(){
    val head = ListNode(1)
    head.addNext(2)
    val newHead = Solution().swapNodes(head, 1)
    newHead?.print()
}