package leetcode.ing.prob97

class Solution {
    val cache = Array<Array<Array<Int>>>(200){
        Array<Array<Int>>(200){
            Array<Int>(200){
                -1
            }
        }
    }

    lateinit var s1 : String
    lateinit var s2 : String
    lateinit var s3 : String

    fun isInterleave(s1: String, s2: String, s3: String): Boolean {
        this.s1 = s1
        this.s2 = s2
        this.s3 = s3

        return getSubsNum(0, 0, 0)
    }

    fun getSubsNum(i : Int, j : Int, k: Int) : Boolean {
        if (cache[i][j][k] != -1) return cache[i][j][k] == 1

        if (s1.length == i && s2.length == j && s3.length == k)
            return true
        else if (s3.length == k)
            return false

        var result = false

        if (s1.length > i && s1[i] == s3[k])
            result = result || getSubsNum(i + 1, j, k+ 1)

        if (s2.length > j && s2[j] == s3[k])
            result = result || getSubsNum(i , j + 1, k+ 1)

        cache[i][j][k] = if (result) 1 else 0

        return result
    }
}