package word;

import java.util.HashSet;
import java.util.Iterator;

/**
 * La clase Word represenata una palabra y es
 * un wrapper sobre el tipo de datos String. 
 */
public class WordSet {	
	
	private HashSet<Word> set = null;
	
	// CONSTRUCTOR
	public WordSet() {
		this.set = new HashSet<Word>();
	}
	
	// METHODS
	public void add(Word w){
		this.set.add(w);
	}
	
	public boolean contains(Word w) {
		boolean is_known= false;
		Iterator <Word> word_iterator = this.set.iterator();
		while (word_iterator.hasNext() && !is_known) {
			Word word_to_compare = word_iterator.next();
			is_known = word_to_compare.equals(w);
		}
		return is_known;
	}
	
	public void clear(){
		this.set.clear();
	}
	
	public Iterator<Word> iterator(){
		return this.set.iterator();
	}
	
	public int size() {
		return this.set.size();
	}

}
