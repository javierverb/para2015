{-# LANGUAGE DoAndIfThenElse #-}
-- 
module SpellChecker (do_spellcheck) where
-- Importo mis módulos, 
-- se podría decir que este es el 'main'
import Dictionary
import Document
import CommandLine

data Params = Params 

-- La funcion 'do_spellcheck' es la funcion que se encarga de manejar
-- el proceso de chequeo ortografico. Esto incluye, cargar el diccionario,
-- abrir el archivo a procesar, procesar el archivo y luego guardar el
-- diccionario y el archivo de entrada ya procesado.
-- Toma como argumento los argumentos de linea de comando de tipo 'Params'.
do_spellcheck :: Params -> IO ()
do_spellcheck = 

        
-- La funcion 'process_document' ejecuta el proceso de chequeo ortografico.
-- Para ello, procesa el archivo palabra por palabra, copiandolas al archivo
-- de salida y consultando al usuario sobre que accion realizar ante una
-- palabra desconocida.
-- Cuando se termina de procesar el archivo, lo cual es señalizado mediante
-- una excepcion por 'doc_get_word', retorna el diccionario (el cual puede
-- haber sido modificado) para guardarlo.
process_document :: Document ->
                    Dictionary ->
                    Dictionary ->
                    IO Dictionary
process_document (Document f_in f_out) dic1 dic2 = 
	do
		doc_open path_in path_out
        word <- doc_get_word f_in
        if dict_contains word dic1 
            then doc_put_word word f_out -- IO ()






-- Verifica si una palabra es conocida, en cuyo caso, continua
-- con el procesamiento del archivo, sin realizar ninguna accion.
-- Si la palabra no es conocida, pregunta al usuario que accion
-- realizar con la misma. Las acciones pueden ser aceptar, ignorar
-- o reemplazar.
consult_user ::  Word ->
                Dictionary ->
                Dictionary ->
                IO (Word, Dictionary, Dictionary)
consult_user word dic1 dic2 = 
	do
        let ans = ""
        ans <- getChar
        
        case ans of
            'a' -> dict_add word dic1
            'i' -> dict_add word dic2
            'r' -> do
                       let new_word = ""

            otherwise -> consult_user word dic1 dic2

        return(word dic1 dic2)


-- void consult_user(char *word){
--    char ans[2];
--    char replace[MAX_WORD_SIZE];
--
--    do {
--        printf("Palabra no reconocida: %s\n Aceptar (a) - Ignorar (i) - Reemplazar (r): ", word);
--        scanf("%s", ans);
--    } while ((strcmp(ans,"r") != 0) && (strcmp(ans,"a") != 0) && (strcmp(ans,"i") != 0));
--    
--    if (strcmp(ans,"a") == 0) {
--        dict_add(word, main_dict);
--        printf("la palabra %s fue AGREGADA al diccionario\n",word);
--    }
--  
--    if (strcmp(ans, "i") == 0) {
--        ignored_add(word, ignored);
--        printf("la palabra %s fue IGNORADA\n",word);
--    }
--
--    if (strcmp(ans, "r") == 0) {
--        printf("Remplazar por:\n");
--        scanf("%s", replace);
--        strcpy(word, replace);
--   }

