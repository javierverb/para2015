package document;
import java.io.BufferedReader;

import word.Word;

public class Document {

	/**
	 * representa al documento que se va a procesar.
	 */
	// ATRIBUTES
	BufferedReader input;
	BufferedReader output;
	
	
	// CONSTRUCTOR
	public Document(String input_path, String output_path) {
		// TODO Auto-generated constructor stub
		this.input = input_path; // TODO: fixme
		this.output = output_path; // TODO: fixme
	}
	
	
	// METHODS
	public void close(){
		
	}
	
	public Word getWord(){
		Word w = null;
		return w;
	}
	
	public void putWord(Word w){
		
	}
}
