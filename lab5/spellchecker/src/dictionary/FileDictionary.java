package dictionary;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Iterator;

import word.Word;

/**
 * La clase FileDictionary representa un diccionario
 * que se carga desde un archivo de texto.
 */
public class FileDictionary extends Dictionary {
	
	/** Atributes */
	public String loadPath = "dict.txt";
	
	/** Constructors */
	public FileDictionary() {}
	
	public FileDictionary(String loadPath){
		this.loadPath = loadPath;
	}
	
	/** Methods */
	
	/** 
	 * Método que se encarga de cargar un diccionario mediante un path
	 * @param String path_to_load_dictionary
	 * @see 
	 * <a href="http://www.mkyong.com/java/how-to-read-file-from-java-bufferedreader-example/"
	 * this
	 * </a> */
	public void load(String path_to_load_dictionary) throws IOException {
		try {
			FileReader file_to_load = new FileReader(path_to_load_dictionary);
			try (BufferedReader br = new BufferedReader(file_to_load)) {
				String sCurrentLine;
				while ((sCurrentLine = br.readLine()) != null) {
					Word word_obj = new Word(sCurrentLine);
					this.set.add(word_obj);
				}
				System.out.println("Cargando diccionario...Ok");
			} 
			catch (IOException e) {
				System.out.println("¡Diccionario no cargado!");
				// skip :)
			}
		} catch (FileNotFoundException e1) {
			System.out.println("Diccionario "+ path_to_load_dictionary + " no encontrado. Cargando diccionario por defecto:" + this.loadPath);
			// if file not found, my dictionary is empty and not load nothing
		}
	}
	
	/**
	 * custom_save es un método privado que evita la repetición de código dependiendo del path provisto
	 * para 'guardar' el diccionario en un archivo.
	 * @param custom_path. Este String determina en donde guardar el archivo.
	 * */
	private void custom_save(String custom_path) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer;
		
		if (custom_path.length() == 0) {
			custom_path = this.loadPath;
		}
		System.out.println("Guardando diccionario...en:" + custom_path);
		writer = new PrintWriter(custom_path, "UTF-8");
		Iterator <Word> word_iterator = this.set.iterator();
		while (word_iterator.hasNext()) {
			Word word_obj_to_save = word_iterator.next();
			System.out.println(word_obj_to_save.getWord());
			writer.println(word_obj_to_save.getWord());
		}
		writer.close();
	}
	
	/**I use this info:
	 * http://stackoverflow.com/questions/2885173/java-how-to-create-a-file-and-write-to-a-file
	 * TODO: continue the document
	 * */
	
	/**
	 * guarda en el diccionario en el mismo archivo desde el cual se cargó.
	 * */
	public void save() throws FileNotFoundException, UnsupportedEncodingException {
		this.custom_save("");
	}
	
	/**
	 * guarda en el diccionario en el path especificado.
	 * */
	public void save(String path_to_save_dictionary) throws FileNotFoundException, UnsupportedEncodingException {
		this.custom_save(path_to_save_dictionary);
	}
}
