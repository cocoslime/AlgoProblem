package leetcode.prob726

class Solution {
    fun countOfAtoms(formula: String): String {
        val (formulaMap, _) = parseFormula(formula)
        return formulaMap.toSortedMap().toList().fold("") { current, pair ->
            current + pair.first + if (pair.second > 1) pair.second else ""
        }
    }

    private fun parseFormula(formula: String): Pair<Map<String, Int>, Int> {
        var index = 0
        val formulaMap = mutableMapOf<String, Int>()
        var elementName = ""
        var countString = ""
        while(index < formula.length) {
            val c = formula[index]
            when {
                c == '(' -> {
                    if (elementName.isNotEmpty()) {
                        val count = if (countString.isEmpty()) 1 else countString.toInt()

                        formulaMap.compute(elementName) { k, v ->
                            if (v == null) count
                            else v + count
                        }
                        elementName = ""
                        countString = ""
                    }

                    parseFormula(formula.drop(index + 1)).let { (partMap, partSize) ->
                        index += partSize

                        var partCountString = ""
                        while (index + 1 < formula.length && formula[index + 1].isDigit()) {
                            partCountString += formula[index + 1]
                            index++
                        }
                        val partCount = if (partCountString.isEmpty()) 1 else partCountString.toInt()

                        partMap.forEach { key, value ->
                            val originValue = formulaMap[key]
                            formulaMap[key] = if (originValue != null) {
                                originValue + value * partCount
                            } else {
                                value * partCount
                            }
                        }
                    }
                }
                c == ')' -> {
                    if (elementName.isNotEmpty()) {
                        val count = if (countString.isEmpty()) 1 else countString.toInt()
                        formulaMap.compute(elementName) { k, v ->
                            if (v == null) count
                            else v + count
                        }
                        elementName = ""
                        countString = ""
                    }
                    return formulaMap to index + 1
                }
                c.isDigit() -> {
                    countString += c
                }
                c.isUpperCase() -> {
                    if (elementName.isNotEmpty()) {
                        val count = if (countString.isEmpty()) 1 else countString.toInt()
                        formulaMap.compute(elementName) { k, v ->
                            if (v == null) count
                            else v + count
                        }
                        elementName = ""
                        countString = ""
                    }
                    countString = ""
                    elementName = "$c"
                }
                c.isLowerCase() -> {
                    elementName += c
                }
            }
            index++
        }
        if (elementName.isNotEmpty()) {
            val count = if (countString.isEmpty()) 1 else countString.toInt()

            formulaMap.compute(elementName) { k, v ->
                if (v == null) count
                else v + count
            }
            elementName = ""
            countString = ""
        }
        return formulaMap to index + 1
    }
}

fun main(){
    println(Solution().countOfAtoms("H2O"))
    println(Solution().countOfAtoms("Mg(OH)2"))
    println(Solution().countOfAtoms("K4(ON(SO3)2)2"))
}
