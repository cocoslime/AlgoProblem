package leetcode.prob706

import java.util.*

class MyHashMap() {
    val map = Array<LinkedList<Pair<Int, Int>>>(10000){
        LinkedList()
    }

    fun put(key: Int, value: Int) {
        remove(key)
        map[key % 10000].add(key to value)
    }

    fun get(key: Int): Int {
        val index = key % 10000
        val list = map[index]

        list.find {
            it.first == key
        }?.let{
            return it.second
        }
        return -1
    }

    fun remove(key: Int) {
        val index = key % 10000
        val list = map[index]

        list.find {
            it.first == key
        }?.let{
            list.remove(it)
        }
    }

}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */