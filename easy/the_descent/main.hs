import System.IO
import Control.Monad
import Data.List
import Data.Maybe

higherIndex :: [Int] -> Int
higherIndex lst = fromJust $ findIndex (==(maximum lst)) lst

main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- DO NOT REMOVE

    -- game loop
    forever $ do
        
        mountains <- replicateM 8 $ do
            input_line <- getLine
            let mountainh = read input_line :: Int -- represents the height of one mountain.
            return mountainh
        
        -- The index of the mountain to fire on.
        putStrLn (show $ higherIndex mountains)
