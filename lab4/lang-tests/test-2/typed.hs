-- HASKELL es un lenguaje de tipado FUERTE
import System.IO

main = strong_type 3 "hola"

strong_type :: Integer -> String -> IO ()
strong_type num word =
    do
        let result = word + num
        print("el result es:")
        print(result)
        return ()
-- haskell es de tipado FUERTE