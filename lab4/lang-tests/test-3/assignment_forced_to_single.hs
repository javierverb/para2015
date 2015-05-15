module Main where

constant :: Int
constant = 222

main = do
    let c = constant
    print c
    -- luego al intentar reasignarla, 
    -- ocurre que, al menos en la forma en la que lo escribo,
    -- no es parte de un parseo válido. 