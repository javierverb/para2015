import System.IO

y = 1
function_a :: Integer -> IO Integer
function_a z = 
    do
        print("el valor de 'z' en function_a es: ")
        print(z)
        print("el valor de 'y' en function_a es: ")
        print(y)
        return z


function_b :: Integer -> IO Integer
function_b z =
    do
        let y = 3
        res <- function_a(y+z)
        return res


main =
    do
        let y = 2
        function_b y