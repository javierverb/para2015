import System.IO
import Data.Char
import Control.Monad


static :: Int -> IO Int
static a = return (a + 222)

checkTyped = 
    do 
        ok <- static 0
        print ok
        fail <- static "0"
        print fail