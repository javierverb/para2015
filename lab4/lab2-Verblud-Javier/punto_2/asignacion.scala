object AsignacionUnica {

	def main(args: Array[String]) {
		
		val asignacionUnica = 0

		/* Esto dará un error en tiempo de compilación: 
		Scala es de asignación única */
		asignacionUnica = 1
		
	}
 
}