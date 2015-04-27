
{-# LANGUAGE DoAndIfThenElse #-}
-- 

module Document where

import System.IO

type Word = String
data Document = Doc Handle Handle

-- Abre los archivos especificados por los paths
-- pasados como argumentos. El primer path repre-
-- senta el archivo de entrada a procesar, y el
-- segundo path representa el archivo de salida
-- donde se guarda el documento ya procesado.
doc_open :: FilePath -> FilePath -> IO Document
doc_open fp1 fp2 = 
    do 
        file_in <- openFile fp1 ReadMode
        file_out <- openFile fp2 WriteMode
        return (Doc file_in file_out)

-- Cierra los archivos especificados
doc_close :: Document -> IO ()
doc_close (Doc f1 f2) = 
    do 
        hclose f1
        hclose f2
        return ()


-- Obtiene una palabra del documento especificado,
-- copiando todos los caracteres no alfabeticos
-- precedentes al archivo de salida.
-- Cuando alcanza el final del documento, lo señaliza
-- con una excepcion.
doc_get_word :: Document -> IO Word
doc_get_word (Doc file_in file_out) =
    let word = ""
    do
        char_readed <- hGetChar file_in
        if isAlphaNum char_readed then word ++ char_readed
        else


        



-- char *end_of_str = "\0";
--    int character_readed, i = 0;
--
--    while (!feof(document->doc_in)) {
--        character_readed = fgetc(document->doc_in);
--
--        if (isalpha(character_readed)) {
--            word[i] = character_readed;
--        } else {
--            word[i] = *end_of_str;
--            if (character_readed != EOF) {
--                if (i == 0) {
--                    fprintf(document->doc_out, "%c", character_readed);
--                }
--                else {
--                    fseek(document->doc_in, -1, SEEK_CUR);
--               }
--                return 1;
--            }
--        }
--        i++;
--    }
--    return 0;

-- usar hgetchar no hace falta trabajar con la excepcion porq de eso se ocupa hgetchar
-- cuando llega a eof solo levanta la excepcion

-- Escribe una palabra en el documento de salida.
doc_put_word :: Word -> Document -> IO ()
doc_put_word word (Doc file_in file_out) = 
    do
        hPutStr file_out word
        return()