
{-# LANGUAGE DoAndIfThenElse #-}
-- 

module Document where

type Word = String

data Document = Doc Handle Handle

-- Abre los archivos especificados por los paths
-- pasados como argumentos. El primer path repre-
-- senta el archivo de entrada a procesar, y el
-- segundo path representa el archivo de salida
-- donde se guarda el documento ya procesado.
doc_open :: FilePath -> FilePath -> IO Document
doc_open fp1 fp2 = 
    do file_in <- openFile fp1 ReadMode
       file_out <- openFile fp2 WriteMode
       return (Doc file_in file_out)

-- Cierra los archivos especificados
doc_close :: Document -> IO ()
doc_close (Doc f1 f2) = 
    do hclose f1
       hclose f2
       return ()


-- Obtiene una palabra del documento especificado,
-- copiando todos los caracteres no alfabeticos
-- precedentes al archivo de salida.
-- Cuando alcanza el final del documento, lo señaliza
-- con una excepcion.
doc_get_word :: Document -> IO Word
usar hgetchar no hace falta trabajar con la excepcion porq de eso se ocupa hgetchar
cuando llega a eof solo levanta la excepcion

-- Escribe una palabra en el documento de salida.
doc_put_word :: Word -> Document -> IO ()
doc_put_word word f = 
    do writeFile f word
    // hputs
    // hputstring busco
    
       return ()
