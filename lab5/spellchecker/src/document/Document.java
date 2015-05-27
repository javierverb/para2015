package document;
import word.Word;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


/**
 * representa al documento que se va a procesar.
 */
public class Document {

	/** Atributes */
	private BufferedReader input_file = null;
	private BufferedWriter output_file = null;
	
	
	/** Constructor */
	public Document(String input_file, String output_file) throws IOException {
		this.input_file = new BufferedReader(new FileReader(input_file));
		this.output_file = new BufferedWriter(new FileWriter(output_file));
	}
	
	
	/** Methods */
	
	/**
	 * Cierra el documento.
	 */
	public void close() throws IOException {
		this.output_file.close();
		this.input_file.close();
	}
	
	/**
	 * El metodo getWord, lee el documento de entrada,
	 * palabra por palabra, copiando al documento de salida
	 * todos los caracteres no alfabeticos precedentes que encuentre.
	 * Al llegar al final del archivo, lo senaliza mediante una
	 * excepcion EOFException
	 */
	public Word getWord() throws IOException {
		String string_to_word= "";
		int c = 0;
		int i = 0;
		while((c = this.input_file.read()) != -1) {
			char character = (char) c;
			if (Character.isAlphabetic(character)) {
				string_to_word += character;
			}
			else {
				if (c != -1) {
					if (i == 0) {
						Word invalid_character = new Word(character+"");
						this.putWord(invalid_character);
					}
					else {
						System.out.println(character);
						this.input_file.mark(i-1);
						this.input_file.reset();
					}
					Word word_to_return = new Word(string_to_word);
					return word_to_return;
				}
			}
			i++;
		}
		// exit while
		return null;
	}
	
	/**
	 * Escribe la palabra w al archivo de salida.
	 */
	public void putWord(Word w) throws IOException {
		output_file.write(w.getWord());
	}
}
