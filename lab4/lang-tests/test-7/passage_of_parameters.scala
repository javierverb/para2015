object Passage_of_parameters {
    
    def fun_byValue(x: Int) = {
        println("by value vale: " + x)
    }

    def fun_byName(x: => Int) = {
        println("by name vale: " + x)
    }

    def main(args: Array[String]){

        lazy val x = {println("esto es x"); 10}
        var y = {println("esto es y"); 20}

        fun_byValue(x)
        fun_byName(y)

        fun_byValue(x)
        fun_byName(y)
    }
}
