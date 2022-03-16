import kotlinx.serialization.Serializable

class Snippet() {
    fun swap() {
        var a = 1
        var b = 2

        a = b.also { b = a }
    }

    fun readLinesToList() {
        val input = generateSequence (::readLine)
        val lines = input.toList()

    }


    // Aggregate example

    @Serializable
    data class User(
        val login: String,
        val contributions: Int
    )

    fun List<User>.aggregate(): List<User> =
        groupBy { it.login }
            .map { (login, group) -> User(login, group.sumOf { it.contributions }) }
            .sortedByDescending { it.contributions }


}