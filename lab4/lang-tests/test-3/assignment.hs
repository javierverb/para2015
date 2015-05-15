module Main where


setValue :: Int -> IO Int
setValue a = return a

main = do
    a <- setValue 10
    print a
    a <- setValue 15
    print a
--Notar que también se puede hacer algo como redefinir la variable, lo cual
--a mi entender representa crear una variable completamente nueva con el valor
--asignado. Sería algo como:
--let a = 10
--let a = 15