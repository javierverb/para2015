object Typed {
   def main(args: Array[String]) {
      println("prueba de tipado fuerte o debil")
      println()
      
      var num : Int = 10
      println("variable num: ")
      println(num)
      println()
      
      var word : String = "hola!!"
      println("variable word: ")
      println(word)
      println()
      
      var result = word * num
      println(result)
      println()
      println("concluimos que scala es de tipado DEBIL")
   }
}