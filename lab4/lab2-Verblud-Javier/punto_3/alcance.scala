object Alcance {
	
	def q(y: Int) {
		println("Estático pues el valor de y es: " + y);
	}

	def rewrite(y: Int){
		val y = 3;
		q(y);
	}

	def main(args: Array[String]) {

		// val a = new Alcance()
		val y = 2
		rewrite(y)
		println("Realmente este: " + y)
 	}
}
