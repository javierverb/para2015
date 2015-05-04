object LazyFun {
	def main(args: Array[String]) {
		
		lazy val x = println ("Hola!")
		
		var y = x
		var z = x

		def fun(a: Int, b: Int) {

			lazy val i = println (a * b)
			
			var j =  i
			var k = i
		}
		
		fun(3, 5)
		fun(4, 9)
	}
}
