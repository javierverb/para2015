module Main where
import Debug.Trace


factorial :: Int -> Int
factorial n | n == 0    = traceStack ("Last case") 1
            | otherwise = n * (factorial $ n - 1)

main = do
    putStrLn $ "factorial 20: " ++ show (factorial 20)

-- con -O2