object High_order {

    def func() : Int = {
            println("hola a todos"); 2 
        }
    
    def main(args: Array[String]) {

        lazy val x = func()
        println("'x' es lazy val")
        println(x)
        println(x)
        println(x)
        println(x)

        val y = () => {
            println("hola a todos"); 2 
        }

        println("ahora 'y' es una funcion --> y()")
        println(y())
        println(y())
        println(y())
        println(y())

    }
}