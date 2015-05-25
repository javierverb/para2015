package word;

/**
 * La clase Word represenata una palabra y es
 * un wrapper sobre el tipo de datos String. 
 */
public class Word {
	
	// ATRIBUTES
	private String word;
	
    
	// CONSTRUCTORS
	public Word(){}
	
	public Word(String word) {
		// TODO Auto-generated constructor stub
		this.word = word;
	}
	
	
	// METHODS
	public void setWord(String w){ 
    
        this.word = w;	
	
    }
	
	public String getWord(){		
	
    	return this.word;
	
    }
	
	@Override
	public int hashCode(){
	
    	int count = 0;
		count = this.word.length();
		return count;
	
    }
	
	@Override
	public boolean equals(Object o){

		if(( o instanceof Word) && (((Word)o).getWord() == this.getWord())){
			return true;
		}
		else{
			return false;
		}
	}

}
