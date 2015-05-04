class Alcance {
	
	void q(int y) {
		System.out.format("Estático pues el valor de y es: %d\n", y);
	}

	void rewrite(int y){

		y = 3;
		q(y);
	}

	public static void main (String args[]) {
		
		int y = 2;
		Alcance a = new Alcance();
		a.rewrite(y);
		System.out.format("Realmente este: %d\n", y);
  }
}

