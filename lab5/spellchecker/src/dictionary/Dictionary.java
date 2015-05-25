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
	
	protected WordSet set = null;
	
	
	// CONSTRUCTOR
	public Dictionary() {
		this.set = new WordSet();
	}
	
	public void add(Word w) {
		this.set.add(w);
	}
	
	public boolean contains(Word w) {
		return this.set.contains(w);
	}
	
	public void clear() {
		this.set.clear();
	}
	
	// TODO: document me
	public void fromStringList(List<String> dictionary) {
		Iterator <String> iterator = dictionary.iterator();
		while (iterator.hasNext()) {  
			String current_word = iterator.next();
			Word word_obj = new Word(current_word);
			this.set.add(word_obj);
		 }
	}
	
	// TODO: document me
	public List<String> toStringList() {
		ArrayList<String> list_to_save_word = new ArrayList<String>();
		Iterator <Word> word_iterator = this.set.iterator();
		while (word_iterator.hasNext()) {
			Word word_obj_to_save = word_iterator.next();
			list_to_save_word.add(word_obj_to_save.getWord());
		}
		return list_to_save_word;
	}
	
	public int size() {
		return this.set.size();
	}

}
