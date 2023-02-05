package leetcode


class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null

    override fun toString() : String {
        return "value:$`val`"
    }
}

fun makeTreeNode(list: List<Int?>): TreeNode? {
    val treeNodeList = mutableListOf<TreeNode?>()
    for (i in 0 until list.size) {
        if (list[i] == null){
            treeNodeList.add(null)
        }
        else
            treeNodeList.add(TreeNode(list[i] as Int))
    }
    for (i in 0 until list.size) {
        if (treeNodeList[i] != null){
            if ((i + 1) * 2 - 1 < list.size) {
                treeNodeList[i]!!.left = treeNodeList[(i + 1) * 2 - 1]
            }
            if ((i + 1) * 2 < list.size){
                treeNodeList[i]!!.right = treeNodeList[(i + 1) * 2]
            }
        }
    }
    return treeNodeList[0]
}


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

fun ListNode.addNext(`val`: Int) : ListNode {
    next = ListNode(`val`)
    return next as ListNode
}

fun ListNode.print() {
    println(`val`)
    next?.print()
}

fun swapNextListNode(first : ListNode, second : ListNode) {
    var nextTemp : ListNode? = first.next!!
    first.next = second.next
    second.next = nextTemp

    val firstNext = first.next!!
    val secondNext = second.next!!

    nextTemp = firstNext.next
    firstNext.next = secondNext.next
    secondNext.next = nextTemp
}


fun Array<IntArray>.print() {
    print("[")
    this.forEach {
        print("${it.asList()},")
    }
    println("]")
}


fun <T> lowerBound(elements: Array<Comparable<T>>, low: Int, high: Int, target: T) : Int {
    var currentLow = low
    var currentHigh = high
    var currentMid: Int

    while(currentLow < currentHigh) {
        currentMid = (currentLow + currentHigh) shr 1
        if (currentMid == high) return high

        if (elements[currentMid] < target) currentLow = currentMid + 1
        else currentHigh = currentMid
    }
    return currentLow
}