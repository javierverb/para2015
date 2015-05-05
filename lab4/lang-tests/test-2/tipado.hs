-- HASKELL es un lenguaje de tipado FUERTE
import System.IO

main = tipado_fuerte 2 3.14

tipado_fuerte:: Integer -> Double -> IO ()
tipado_fuerte a b =
    do
        let result = a + b
        print ("el resultado es:")
        print (result)
        return ()