object Tipado {

	def main(args: Array[String]) {
		
		val estatico = 0

		/* Esto dará un error en tiempo de compilación: 
		Se esperaba un int. Ademas de que no permite reescribir el valor */
		estatico = "Nunca sere este valor"
		
	}
 
}