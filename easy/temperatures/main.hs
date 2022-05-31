import System.IO
import Control.Monad

closestToZero :: [Int] -> Int
closestToZero [] = 0
closestToZero (x:[]) = x
closestToZero (x:xs)
  | (abs x) < (abs s) = x
  | (abs x) > (abs s) = s
  | otherwise = if x == s then x else (abs x)
  where
    s = closestToZero xs

main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- DO NOT REMOVE
    
    input_line <- getLine
    let n = read input_line :: Int -- the number of temperatures to analyse
    input_line <- getLine
    let input = words input_line
    
    temps <- forM [0..(n-1)] $ \i -> do
        let t = read (input!!(i)) :: Int -- a temperature expressed as an integer ranging from -273 to 5526
        return t
    
    putStrLn $ show (closestToZero temps)
    return ()
