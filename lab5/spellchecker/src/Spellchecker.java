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
        
        String dict;
        
        if(args.length < 2){
            System.out.println("spellchecker.c: nro de argumentos erroneo.");
            System.out.println("Deben ser <documento> [<diccionario>].");
            // return (1);
        }
        
        // si se especifico un diccionario lo usamos,
        // caso contrario usamos el diccionario por defecto
        dict = (args.length >=3) ? args[2] : "dict.txt";

        // FALTA COMPLETAR

    }
    
    public static Word consultUser(Word w, Dictionary dic_in, Dictionary dic_out){
        
        public static Word consultUser(Word w, Dictionary dic_in, Dictionary dic_out){
        
        String s;
        String rep;
        
        do{
            System.out.println("Palabra no reconocida: " + w);
            System.out.println("Aceptar (a) - Ignorar (i) - Reemplazar (r): ");
            Scanner reader = new Scanner(System.in);
            s = reader.next();
            reader.close();
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
            replace.close();
            w.setWord(rep);
        }
        
        return w;
            
    }
    
    public static void processDocument(String s1, String s2, Dictionary dic_in, Dictionary dic_out){
        // TODO: complete this!!
    }

}
