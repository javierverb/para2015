module Main where
import Debug.Trace


factorial :: Int -> Int -> Int
factorial n acc| n == 0    = 1
               | otherwise = factorial (n-1) (acc*n)

main = do
    putStrLn $ "factorial 20: " ++ show (factorial 10 1)
    let a = traceStack ("Last case") 0
    print a

-- con -O2