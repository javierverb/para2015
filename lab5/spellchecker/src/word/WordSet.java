package word;

import java.util.HashSet;
import java.util.Iterator;

/**
 * La clase WordSet representa un conjunto de palabras,
 * el cual se implementa internamente con una colección
 * que implemente la interfaz Set. 
 */
public class WordSet {	
	
	private HashSet<Word> set = null;
	
	/** Constructor */
	public WordSet() {
		this.set = new HashSet<Word>();
	}
	
	/** Methods */
	
	/**
	 * Agrega la palabra 'w' al conjunto.
	 * */
	public void add(Word w){
		this.set.add(w);
	}
	
	/**
	 * Verifica si la palabra 'w' se encuetra en el conjunto
	 * de palabras.
	 * */
	public boolean contains(Word w) {
		boolean is_known= false;
		Iterator <Word> word_iterator = this.set.iterator();
		while (word_iterator.hasNext() && !is_known) {
			is_known = word_iterator.next().equals(w);
		}
		return is_known;
	}
	
	/**
	 * Remueve todos los elementos de la
	 * lista de palabras.
	 * */
	public void clear(){
		this.set.clear();
	}
	
	/**
	 * El método iterator devuelve una referencia a un iterator
	 * correspondiente a la implementación interna del conjunto.
	 * */
	public Iterator<Word> iterator(){
		return this.set.iterator();
	}
	
	/**
	 * Devuelve la cantidad de palabras en el conjunto
	 * de palabras.
	 * */
	public int size() {
		return this.set.size();
	}

}