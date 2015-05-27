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
	 * 
	 * */
	@Override
	public int hashCode(){
		int count = 0;
		count = this.word.length();
		return count;
	}
	
	/**
	 * 
	 * */
	@Override
	public boolean equals(Object o) {
		if((o instanceof Word) && (((Word)o).getWord() == this.getWord())){
			return true;
		}
		else {
			System.out.println("["+((Word) o).getWord() + "]");
			System.out.println(this.getWord());
			return false;
		}
	}
}
