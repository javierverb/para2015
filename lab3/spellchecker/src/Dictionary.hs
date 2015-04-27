module Dictionary where

-- Las importaciones van después de declarar el paquete/modulo
-- Dictionary 
import System.IO
import Control.Monad


type Dictionary = [String]  --data Dictionary = [Word]
type Word = String

-- Crea un nuevo diccionario vacio
dict_new :: Dictionary
dict_new = [""]

-- Agrega una palabra al diccionario especificado
dict_add :: Word -> Dictionary -> Dictionary
dict_add word dictionary = dictionary ++ [word]
-- dict_add word dict = word:dict otra forma, no se si va a importar el orden 

-- Verifica la existencia de una palabra en el
-- diccionario especificado
dict_contains :: Word -> Dictionary -> Bool
dict_contains word_to_search [] = False
dict_contains word_to_search (word:dictionary) = 
    word_to_search == word || dict_contains word_to_search dictionary

-- Carga un diccionario desde un archivo especificado.
dict_load :: FilePath -> IO Dictionary
dict_load file_dictionary = 
    do
        definition_text <- readFile file_dictionary
        let new_dictionary = lines (definition_text)
        return new_dictionary
-- Guarda el diccionario en el archivo especificado.
dict_save :: FilePath -> Dictionary -> IO ()
dict_save filename_to_save list_dict_to_save = 
    do 
        let data_to_save = unlines (list_dict_to_save)
        writeFile filename_to_save data_to_save
        return ()
