import dictionary.Dictionary;
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static Word consultUser(Word w, Dictionary dic_in, Dictionary dic_out){
		
		String s;
		String rep;
		
		do{
			System.out.println("Palabra no reconocida: " + w);
			System.out.println("Aceptar (a) - Ignorar (i) - Reemplazar (r): ");
			Scanner reader = new Scanner(System.in);
	        s = reader.next();
		}while ((s != "r") && (s != "a") && (s != "i"));
		
		if (s == "a"){
			// hacer
			System.out.println("la palabra: " + w);
			System.out.println("fue AGREGADA al diccionario");
		}

		if (s == "i"){
			// hacer
			System.out.println("la palabra: " + w);
			System.out.println("fue IGNORADA al diccionario");
		}
		
		if (s == "r"){
			// remlazar
			System.out.println("Remplazar por: ");
			Scanner replace = new Scanner(System.in);
	        rep = replace.next();
	        // auxilar que remplace w por rep
		}
		 
		return w;
	}
	
	public static void processDocument(String s1, String s2, Dictionary dic_in, Dictionary dic_out){
		// TODO: complete this!!
	}

}
