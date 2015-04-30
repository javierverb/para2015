
{-# LANGUAGE DoAndIfThenElse #-}
-- 

module Document where

import System.IO
import Data.Char

type Word = String
data Document = Document Handle Handle

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
        return (Document file_in file_out)

-- Cierra los archivos especificados
doc_close :: Document -> IO ()
doc_close (Document f1 f2) = 
    do 
        hClose f1
        hClose f2
        return ()

constructWord :: Word -> Handle -> Handle -> IO Word  
constructWord word_to_return file_in file_out =
    do 
        char_readed <- hGetChar file_in
        
        if isAlphaNum char_readed then
            constructWord (word_to_return++[char_readed]) file_in file_out
        else do
            hPutChar file_out char_readed
            return word_to_return

-- Obtiene una palabra del documento especificado,
-- copiando todos los caracteres no alfabeticos
-- precedentes al archivo de salida.
-- Cuando alcanza el final del documento, lo señaliza
-- con una excepcion.
doc_get_word :: Document -> IO Word
doc_get_word (Document file_in file_out) =
    do 
        word_to_process <- constructWord "" file_in file_out
        return word_to_process

-- usar hgetchar no hace falta trabajar con la excepcion porq de eso se ocupa hgetchar
-- cuando llega a eof solo levanta la excepcion

-- Escribe una palabra en el documento de salida.
doc_put_word :: Word -> Document -> IO ()
doc_put_word word (Document _ file_out) = 
    do
        hPutStr file_out word
        return()
