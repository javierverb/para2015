object HelloWorld {
   def main(args: Array[String]) {
      println("prueba de tipado fuerte o debil")
      
      var num : Int = 10
      println(num)
      
      var word : String = "hola!!"
      println(word)
      
      var result = word * num
      println(result)
      println("concluimos que scala es de tipado DEBIL")
   }
}
