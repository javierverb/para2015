package word;

/**
 * La clase Word represenata una palabra y es
 * un wrapper sobre el tipo de datos String. 
 */
public class Word {	
	
	/** Atributes */
	private String word;
	
	/** Constructors */
	public Word(){}
	
	public Word(String word) {

		this.word = word;
	}
	
	
	/** Methods */
	
	/**
	 * Asigna 'w' al atributo de la clase.
	 * */
	public void setWord(String w){ 
		this.word = w;
	}
	
	/**
	 * Devuelve el atributo.
	 * */
	public String getWord() {
		return this.word;
	}
	
	
	/**
	 * El hashcode es un numero entero, sin signo, que sirve en colecciones de tipo Hash*.
	 * Este método debe ser sobrescrito en todas las clases que sobrescriban el método equals,
	 * si no se quiere tener un comportamiento extraño al utilizar las colecciones de tipo Hash*
	 * y otras clases. Si dos objetos son iguales según el método equals sobrescrito,
	 * estos deberian regresar el mismo hashcode.
	 * @return 
	 * */
	@Override
	public int hashCode(){
		
		return this.word.hashCode();

	}
	
	/**
	 * Define una relación de equivalencia entre objetos,
	 * basandose en un subconjunto de atributos.
	 * */
	@Override
	public boolean equals(Object o) {
		if((o instanceof Word) && (this.getWord().equals(((Word)o).getWord()))) {
			return true;
		}
		else {
			return false;
		}
	}

}