package acmicpc

import java.util.PriorityQueue

data class Edge(val id: Int, val from: Int, val to: Int, val cost: Long)
data class RangedEdge(val from: Int, val to: Int, val range: LongRange)

fun mst(n: Int, edges: List<Edge>): Long {
    val isVisited = Array(n) { false }

    val queue = PriorityQueue<Edge>(compareBy { it.cost })
    edges.forEach { queue.add(it) }

    var totalCost = 0L

    while (queue.isNotEmpty()) {
        val edge = queue.poll()
        if (isVisited[edge.from] && isVisited[edge.to]) {
            continue
        }
        isVisited[edge.from] = true
        isVisited[edge.to] = true
        totalCost += edge.cost
    }

    return totalCost
}

fun List<Edge>.distanceTo(target: List<Edge>) : Long {
    return this.mapIndexed { index, edge -> target[index].cost - edge.cost }.sum()
}

fun mid(start: List<Edge>, end: List<Edge>): List<Edge> {
    // 1. start 에서 end 까지의 distance 를 구한다.
    // 2. end 에서 가장 높은 cost 를 찾는다.
    // 3. 하나를 줄인다.
    // 4. distance / 2 만큼 2번과 3번을 반복한다.
    var distance = start.distanceTo(end)
    if (distance == 1L) {
        return start
    }
    distance /= 2

    val result = mutableListOf<Edge>()
    val pq = PriorityQueue<Edge>(compareByDescending { it.cost })
    end.forEachIndexed { index, edge ->
        if (start[index].cost < edge.cost) {
            pq.add(edge)
        } else if (start[index].cost > edge.cost) {
            throw IllegalStateException("start cost is bigger than end cost")
        } else {
            result.add(edge)
        }
    }

    val minimum = start.associateBy { it.id }

    while (distance > 0) {
        val edge = pq.poll()
        val newEdge = edge.copy(
            cost = edge.cost - 1
        )
        distance--
        if (newEdge.cost != minimum[edge.id]!!.cost) {
            pq.add(newEdge)
        } else {
            result.add(newEdge)
        }
    }

    while (pq.isNotEmpty()) {
        val edge = pq.poll()
        result.add(edge)
    }

    return result.sortedBy { it.id }
}

fun main() {
    val firstLine = readLine()!!.split(" ")
    val n = firstLine[0].toInt()
    val m = firstLine[1].toInt()
    val k = firstLine[2].toLong()

    val rangedEdges = mutableListOf<RangedEdge>()

    for (i in 0 until m) {
        val (a, b, c, d) = readLine()!!.split(" ").map { it.toInt() }

        rangedEdges.add(RangedEdge(a - 1, b - 1, c.toLong()..d.toLong()))
    }

    var start = rangedEdges.mapIndexed { index, range -> Edge(index, range.from, range.to, range.range.first) }
    var end = rangedEdges.mapIndexed { index, range -> Edge(index, range.from, range.to, range.range.last) }
    val minimum = mst(n, start)
    val maximum = mst(n, end)
    if (k in minimum..maximum) {
        println("YES")
    } else {
        print("NO")
        return
    }

    var current = mid(start, end)
    var currentCost = mst(n, current)
    while (currentCost != k) {
        if (currentCost > k) {
            end = current
        } else {
            start = current
        }
        current = mid(start, end)
        currentCost = mst(n, current)
    }

    current.forEach {
        println("${it.from + 1} ${it.to + 1} ${it.cost}")
    }
}
