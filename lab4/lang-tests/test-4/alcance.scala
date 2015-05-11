object Alcance {
	def main(args: Array[String]) {
		fun_b(3)
	}

	def fun_a( z:Int ) : Int = {
		return z + global_var
	}

	def fun_b( y:Int ) : Int = {
		global_var = y + 1
		return fun_a(y * global_var) 
	}
	
}