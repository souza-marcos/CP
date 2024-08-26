import Data.Bits
import Data.List (foldl')

type BitSet = Int
matrix :: [BitSet]
matrix = [0b110, 0b011, 0b101]

rhs :: BitSet
rhs = 0b110

gaussianElimination :: [BitSet] -> BitSet -> [BitSet]
gaussianElimination mat b = backSubstitute reducedMat reducedRhs
    where
        (reducedMat, reducedRhs) = foldl' eliminate (mat, b)[0..n-1]

        eliminate (m, r) k =
            let pivotRow = findPivot m k
            in if pivotRow == -1 then (m, r) else
                let m' = swapRows m k pivotRow
                    r' = swapBits r k pivotRow
                    m'' = map(\i -> if testBit (m' !! i) k then m' !! i `xor` (m' !! k) else m' !! i) [0..n-1]
                    r'' = foldl' (\acc i -> if testBit (m' !! i) k then acc `xor` bit i else acc) r' [k+1..n-1]
                in (m'', r'')

        backSubstitute m r = map (\i -> if testBit r i then 1 else 0) [0..n-1]

        findPivot m k = case filter (\i -> testBit (m !! i) k) [k..n-1] of
            [] -> -1
            (x:_) -> x

        swapRows m i j = map(\(k, row) -> if k == i then m !! j else if k == j then m !! i else row) (zip [0..] m)

        swapBits v i j = (v `xor` (bit i .|. bit j)) `xor` ((v `shiftR` (j -i)) .&. bit i) `xor` ((v `shiftL` (j - i)) .&. bit j)

        n = length mat

main :: IO ()
main = do
    print $ gaussianElimination matrix rhs