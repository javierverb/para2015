package dictionary;
import java.util.List;

import word.Word;

/**
 * La clase Dictionary es una clase abstracta que representa
 * un diccionario de palabras.
 * Las palabras se almacenan como un conjunto de palabras.
 * <a href="http://picarcodigo.blogspot.com.ar/2012/10/clases-abstractas.html"> 
 * Ver referencia 
 * </a>
 */
public abstract class Dictionary {	
	
	// TODO: override in subclass
	public abstract void add(Word w);
	
	// TODO: override in subclass
	public abstract boolean contains(Word w);
	
	// TODO: ¿qué hace?
	public abstract void clear();
	
	// TODO
	public void fromStringList(List<String> dictionary){
		
	}
	
	// TODO
	public List<String> toStringList(){
		return null; //
	}
	
	public int size(){
		return 0;
	}

}
