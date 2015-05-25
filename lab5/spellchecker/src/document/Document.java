package document;
import word.Word;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Document {

	/**
	 * representa al documento que se va a procesar.
	 */
	
	// ATRIBUTES
	private BufferedReader input_file = null;
	private BufferedWriter output_file = null;
	
	
	// CONSTRUCTOR
	public Document(String input_file, String output_file) {
		try {
		     this.input_file = new BufferedReader(new FileReader("file_in.txt"));
		     this.output_file = new BufferedWriter(new FileWriter("file_out.txt"));
		} 
		catch (IOException e) {
		    e.printStackTrace();
		} 
	}
	
	
	// METHODS
	public void close() throws IOException{
		this.output_file.close();
		this.input_file.close();
	}
	
	// TODO: complete me
	public Word getWord(){
		Word w = null;
		return w;
	}
	
	public void putWord(Word w) throws IOException {
		output_file.write(w.getWord());
	}
}
