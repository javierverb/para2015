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
	public static void main(String[] args) throws Exception {
		
		String dict_path;
		
		if(args.length < 1){
			String msgError = ("spellchecker.c: nro de argumentos erroneo.\n"+
								"Deben ser <documento> [<diccionario>].\n");
			throw new Exception("\n\nInvalid args:\n"+msgError);
		}
		
		// si se especifico un diccionario lo usamos,
		// caso contrario usamos el diccionario por defecto
		dict_path = (args.length >= 2) ? args[1] : "dict.txt";
		System.out.println(args[0]);
		
		// create dictionaries and load
		FileDictionary dict_main = new FileDictionary(dict_path);
		MemDictionary dict_ignored = new MemDictionary();
		dict_main.load(dict_path);
		
		// TODO: remove this line when finish debug
		System.out.print("Printeando:");
		dict_main.dumpDict();
		
		// procces document
		processDocument(args[0], "doc_out.txt", dict_main, dict_ignored);
		// save dict_main
		dict_main.save();
		// destroy dictionaries
		dict_main.clear();
		dict_ignored.clear();
	}
	
	public static Word consultUser(Word w, Dictionary dic_added_word, Dictionary dic_ignored_word) {
		char s;
		String rep;
		Scanner reader = new Scanner(System.in);
		do {
			System.out.println("Palabra no reconocida: " + w.getWord());
			System.out.println("Aceptar (a) - Ignorar (i) - Reemplazar (r): ");
			s = reader.next().charAt(0);
			reader.reset();
			
			if (s == 'a') {
				dic_added_word.add(w);
				System.out.print("la palabra: " + w.getWord());
				System.out.println(" fue AGREGADA al diccionario");
			}
	
			if (s == 'i') {
				dic_ignored_word.add(w);
				System.out.print("la palabra: " + w.getWord());
				System.out.println(" fue IGNORADA al diccionario");
			}
			
			if (s == 'r') {
				// remplazar
				System.out.println("Remplazar por: ");
				@SuppressWarnings("resource")
				Scanner replace = new Scanner(System.in);
				rep = replace.next();
				//replace.close();
				w.setWord(rep);
			}
			return w;
		} while ((s != 'r') && (s != 'a') && (s != 'i'));
	}
	
	public static void processDocument(String doc_in, String doc_out, Dictionary dic_added_word, Dictionary dic_ignored_word) throws IOException {
		// TODO: complete this!!
		Word current_word;
		Document doc = new Document(doc_in, doc_out);
	
		while((current_word = doc.getWord()) != null) {
			if(!(dic_added_word.contains(current_word) || dic_ignored_word.contains(current_word))) {
				current_word = consultUser(current_word, dic_added_word, dic_ignored_word);
			}
			doc.putWord(current_word);
		}
		doc.close();
	}
}
