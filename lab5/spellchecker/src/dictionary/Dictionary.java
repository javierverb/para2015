package dictionary;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import word.Word;
import word.WordSet;

/**
 * La clase Dictionary es una clase abstracta que representa
 * un diccionario de palabras.
 * Las palabras se almacenan como un conjunto de palabras.
 * <a href="http://picarcodigo.blogspot.com.ar/2012/10/clases-abstractas.html"> 
 * Ver referencia 
 * </a>
 */
public abstract class Dictionary {	
	
	/** Atribute */
	protected WordSet set = null;
	
	
	/** Constructor */
	public Dictionary() {
		this.set = new WordSet();
	}
	
	/** Methods */
	
	/**
	 * Método que se encarga de agregar palabras
	 * @param <b>w:</b> palabra tipo Word a agregar.
	 * */
	public void add(Word w) {
		this.set.add(w);
	}
	
	/**
	 * Método que determina si la palabra está contenida en mi Diccionario
	 * @param <b>w:</b> palabra tipo Word a verificar.
	 * @return true si la palabrá está contenida, caso contrario false
	 * */
	public boolean contains(Word w) {
		return this.set.contains(w);
	}
	
	/**
	 * Reinicializa el Diccionario
	 * */
	public void clear() {
		this.set.clear();
	}
	
	
	
	/**
	 * Inserta en el diccionario todos los elementos pertenecientes a la lista 
	 * pasada como argumento.
	 * @param <b> dictionary: </b>diccionario tipo List<String>
	 * */
	public void fromStringList(List<String> dictionary) {
		Iterator <String> iterator = dictionary.iterator();
		while (iterator.hasNext()) {  
			String current_word = iterator.next();
			Word word_obj = new Word(current_word);
			this.set.add(word_obj);
		 }
	}
	
	/**
	 * @return Lista de string con todas las <b> Words </b> contenidas
	 * en el diccionario.
	 * */
	public List<String> toStringList() {
		ArrayList<String> list_to_save_word = new ArrayList<String>();
		Iterator <Word> word_iterator = this.set.iterator();
		while (word_iterator.hasNext()) {
			Word word_obj_to_save = word_iterator.next();
			list_to_save_word.add(word_obj_to_save.getWord());
		}
		return list_to_save_word;
	}
	
	/**
	 * Determina el tamaño del diccionario
	 * @return Int
	 * */
	public int size() {
		return this.set.size();
	}

}
