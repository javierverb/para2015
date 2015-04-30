
{-# LANGUAGE DoAndIfThenElse #-}
-- 

module Document where

import System.IO
import Control.Monad
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


constructWord :: Word -> Int -> Handle -> Handle -> IO Word  
constructWord word_to_return i file_in file_out =
    do 
        char_readed <- hGetChar file_in
        
        if isAlphaNum char_readed then
            constructWord (word_to_return++[char_readed]) i+1 file_in file_out
        else do
            if i == 0 then
                hPutChar file_out char_readed
            else
                hSeek file_in RelativeSeek -1
                constructWord word_to_return 0 file_in file_out

        return word_to_return

-- Obtiene una palabra del documento especificado,
-- copiando todos los caracteres no alfabeticos
-- precedentes al archivo de salida.
-- Cuando alcanza el final del documento, lo señaliza
-- con una excepcion.
doc_get_word :: Document -> IO Word
doc_get_word (Document file_in file_out) =

    catch (do
        valid_word <- constructWord "" file_in file_out
        return valid_word)
          (\err -> putStrLn(show err))


-- usar hgetchar no hace falta trabajar con la excepcion porq de eso se ocupa hgetchar
-- cuando llega a eof solo levanta la excepcion

-- Escribe una palabra en el documento de salida.
doc_put_word :: Word -> Document -> IO ()
doc_put_word word (Document file_in file_out) = 
    do
        hPutStr file_out word
        return()
