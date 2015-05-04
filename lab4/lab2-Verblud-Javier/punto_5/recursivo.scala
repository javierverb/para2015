object Recursivo {
	def main(args: Array[String]) {
		// Devuelve true si es par
		def EsPar (x:Int) : Boolean =
			if (x==0) true
			else EsImpar(x-1)

		// Devuelve true si es impar
		def EsImpar (x:Int) : Boolean =
			if (x==0) false
			else EsPar(x-1)

		// Llamamos a las funciones
		def arg1 = 1
			def result1 = EsImpar(arg1)
				println("EsImpar(" + arg1 + ")= " + result1) //aca se fija si es impar el arg

		def arg2 = 1
			def result2 = EsPar(arg2)
				println("EsPar(" + arg2 + ")= " + result2 + "\n") //aca se fija si es par el arg

		def arg3 = 100
			def result3 = EsImpar(arg3)
				println("EsImpar(" + arg3 + ")= " + result3)

		def arg4 = 100
			def result4 = EsPar(arg4)
				println("EsPar(" + arg4 + ")= " + result4)
	}
}
