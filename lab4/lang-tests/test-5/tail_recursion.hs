module Main where
import Debug.Trace


factorial :: Int -> Int
factorial n | n == 0    = trace ("Last case") 1
            | otherwise = trace ("N:"++show (n)) $ n * (factorial $ n - 1)

main = do
    putStrLn $ "factorial 20: " ++ show (factorial 20)

-- con -O2