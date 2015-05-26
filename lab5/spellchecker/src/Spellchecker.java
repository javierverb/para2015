import java.io.IOError;
import java.io.IOException;
import java.util.Scanner;

import dictionary.Dictionary;
import dictionary.FileDictionary;
import dictionary.MemDictionary;
import document.Document;
import word.Word;

/**
 * @author      Javier Verblud <javier2mil8@gmail.com>
 * @author      Franco Vasquez <frant089@gmail.com>
 * @version     0.0
 * @since       2014-05-21          
 */
public class Spellchecker {

	// CONSTRUCTOR
	public Spellchecker(){}
		
		
	// METHODS
	public static void main(String[] args) throws IOException {
		
		String dict;
		
		if(args.length < 2){
			System.out.println("spellchecker.c: nro de argumentos erroneo.");
			System.out.println("Deben ser <documento> [<diccionario>].");
			// return (1);
		}
		
		// si se especifico un diccionario lo usamos,
		// caso contrario usamos el diccionario por defecto
		dict = (args.length >=3) ? args[2] : "dict.txt";
		
		// create dictionaries
		FileDictionary dict_main = new FileDictionary();
		MemDictionary dict_ignored = new MemDictionary();
		// load dict_main
		dict_main.load(dict);
		// procces document
		processDocument("doc_in.txt", "doc_out.txt", dict_main, dict_ignored);
		// save dict_main
		dict_main.save();
		// destroy dictionaries
		dict_main.clear();
		dict_ignored.clear();
	}
	
	public static Word consultUser(Word w, Dictionary dic_in, Dictionary dic_out) {
		String s;
		String rep;
		do{
			System.out.println("Palabra no reconocida: " + w.getWord());
			System.out.println("Aceptar (a) - Ignorar (i) - Reemplazar (r): ");
			Scanner reader = new Scanner(System.in);
			s = reader.next();
			reader.close();
		}while ((s != "r") && (s != "a") && (s != "i"));
		
		if (s == "a") {
			// hacer
			System.out.println("la palabra: " + w);
			System.out.println("fue AGREGADA al diccionario");
		}

		if (s == "i") {
			// hacer
			System.out.println("la palabra: " + w);
			System.out.println("fue IGNORADA al diccionario");
		}
		
		if (s == "r") {
			// remlazar
			System.out.println("Remplazar por: ");
			Scanner replace = new Scanner(System.in);
			rep = replace.next();
			replace.close();
			w.setWord(rep);
		}
		
		return w;
			
	}
	
	public static void processDocument(String doc_in, String doc_out, Dictionary dic_added_word, Dictionary dic_ignored_word) throws IOException{
		// TODO: complete this!!
		Word current_word;
		Document doc = new Document(doc_in, doc_out);
		
		try{
			Word wd = null;
			while(true){
				current_word = doc.getWord();
				if(!(dic_added_word.contains(current_word) || dic_ignored_word.contains(current_word))){
					wd = consultUser(current_word, dic_added_word, dic_ignored_word);
				}
				doc.putWord(wd);	
			}
		}
		catch (IOError e){
			doc.close();
		}
	}

}
