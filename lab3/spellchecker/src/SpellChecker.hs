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
    do
        dict_ignored_w = dict_new
        dict_added_w <- dict_load "dictionary.txt"
        document <- doc_open "input.txt" "output.txt"
        dict_to_save <- process_document document dict_added_w dict_ignored_w
        dict_save "dictionary.txt" dict_to_save
        doc_close document
        return ()

        
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
process_document (Document f_in f_out) dict_added_w dict_ignored_w = 
	do
        try:
            word_to_process <- doc_get_word f_in
            if dict_contains word_to_process dict_added_w then
                doc_put_word word_to_process f_out -- IO ()
            else do 
                (w', d_add', d_ign') <- consult_user word_to_process dict_added_w dict_ignored_w
                doc_put_word w' f_out
                process_document (Document f_in f_out) d_add' d_ign'
        except:
            return dict_added_w

clearScreen :: IO [()]
clearScreen = sequence (replicate 80 (putChar '\n'))


printMenu :: IO ()
printMenu = 
    do
        clearScreen
        putStr "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
        putStr "* a: Agregar palabra al diccionario   *\n"
        putStr "* i: Ignorar palabra                  *\n"
        putStr "* r: Reemplazar palabra               *\n"
        putStr "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
        putStr "Ingrese una opcion y despues [Intro]   \n"

-- Verifica si una palabra es conocida, en cuyo caso, continua
-- con el procesamiento del archivo, sin realizar ninguna accion.
-- Si la palabra no es conocida, pregunta al usuario que accion
-- realizar con la misma. Las acciones pueden ser aceptar, ignorar
-- o reemplazar.
consult_user ::  Word -> Dictionary -> Dictionary -> IO (Word, Dictionary, Dictionary)
consult_user w dict_added_w dict_ignored_w = 
    do
        printMenu

        action <- getChar
        clearScreen
        
        case action of
            'a' -> do
                return (w, (dict_add w dict_added_w), dict_ignored_w)
            'i' -> do
                return (w, dict_added_w, (dict_add w dict_ignored_w))
            'r' -> do
                putStr "Ingrese el reemplazo de la palabra      \n"
                word_to_replace <- getLine
                return (word_to_replace, dict_added_w, dict_ignored_w)

            _ -> do
                (w, dict_add, dict_ignored_w) <- consult_user w  dict_added_w dict_ignored_w
                return (w, dict_add, dict_ignored_w)