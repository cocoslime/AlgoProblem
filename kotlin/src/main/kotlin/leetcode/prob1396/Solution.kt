package leetcode.prob1396

class StationGraph {
    val adjListMap = mutableMapOf<String, MutableList<Int>>()

    fun add(key : String, time : Int) {
        if (adjListMap[key] == null){
            adjListMap[key] = mutableListOf()
        }

        adjListMap[key]?.add(time)
    }

    fun getAverageTime(key : String) : Double {
        val sum = adjListMap[key]?.sum()
        sum?.let{
            return it.toDouble() / adjListMap[key]!!.size.toDouble()
        }
        return 0.0
    }
}

class UndergroundSystem() {
    val graph = StationGraph()
    val checkInMap = mutableMapOf<Int, Pair<String, Int>>()

    fun checkIn(id: Int, stationName: String, t: Int) {
        checkInMap[id] = stationName to t
    }

    fun checkOut(id: Int, stationName: String, t: Int) {
        val checkInInfo = checkInMap[id]!!
        val srcName = checkInInfo.first

        graph.add(srcName + "_" + stationName, t - checkInInfo.second)
        checkInMap.remove(id)
    }

    fun getAverageTime(startStation: String, endStation: String): Double {
        val key = startStation + "_" + endStation
        return graph.getAverageTime(key)
    }

}
