module Hw2 where

data HuffmanTree = Empty | Intermediate Integer HuffmanTree HuffmanTree | Leaf Char Integer deriving (Show,Eq)


frequencies :: [Char] -> [HuffmanTree]

buildTree :: [HuffmanTree] -> HuffmanTree

encode :: HuffmanTree -> [Char] -> [Char]

decode :: HuffmanTree -> [Char] -> [Char]

--DO NOT MODIFY ABOVE THIS LINE
--Start here


-------------------------------FREQUENCIES---------------------------------------

mainSorter [] = []  
mainSorter (x:xs) = mainSorter [a | a <- xs, a <= x] ++ [x] ++ mainSorter [b | b <- xs, b > x]

freqCounter [] = [Empty]
freqCounter (x:xs) = freqCounter2 1 x xs where
    freqCounter2 n x [] = [(Leaf x n)]
    freqCounter2 n x (y:ys)
        | x == y    = freqCounter2 (n + 1) x ys
        | otherwise = (Leaf x n) : freqCounter2 1 y ys

freqSorter [] = []
freqSorter [Empty] = [Empty]
freqSorter [Leaf char integer] = [Leaf char integer]
freqSorter ((Leaf char integer):xs) = freqSorter [(Leaf char2 integer2) | (Leaf char2 integer2) <- xs, integer2 <= integer] ++ [Leaf char integer] ++ freqSorter [(Leaf char2 integer2) | (Leaf char2 integer2) <- xs, integer2 > integer]

freqSorter2 [] list list2  n = (list2++(fixer list []))
freqSorter2 [Empty] list list2  n = [Empty]
freqSorter2 ((Leaf char integer):xs) list list2  n 
	| n == integer = freqSorter2 xs (list ++ [Leaf char integer]) list2 n
	| otherwise = freqSorter2 xs [(Leaf char integer)] (list2++(fixer list [])) integer

freqSorter3 [] = []
freqSorter3 [Empty] = [Empty]
freqSorter3 [Leaf char integer] = [Leaf char integer]
freqSorter3 ((Leaf char integer):xs) = freqSorter3 [(Leaf char2 integer2) | (Leaf char2 integer2) <- xs, char2 <= char] ++ [Leaf char integer] ++ freqSorter3 [(Leaf char2 integer2) | (Leaf char2 integer2) <- xs, char2 > char]

getInt ((Leaf char integer):xs) = integer

getInt2 (Leaf char integer) = integer
getInt2 (Intermediate integer (leaf) (leaf2)) = integer

fixer [] list = list
fixer [Empty] list = [Empty]
fixer ((Leaf char integer):xs) list = (list ++ freqSorter3((Leaf char integer):xs))

frequencies x = freqSorter2 (freqSorter(freqCounter(mainSorter((x))))) [] []  (getInt(freqSorter(freqCounter(mainSorter(((x)))))))

-----------------------------BUILDTREE-----------------------------------------

freqSorterComplex [] = []
freqSorterComplex [Empty] = [Empty]
freqSorterComplex ((Leaf char integer):xs) = freqSorterComplex [x | x <- xs, getInt2(x) <= integer] ++ [Leaf char integer] ++ freqSorterComplex [x | x <- xs, getInt2(x) > integer]
freqSorterComplex ((Intermediate integer (leaf) (leaf2)):xs) = freqSorterComplex [x | x <- xs, getInt2(x) <= integer] ++ [Intermediate integer (leaf) (leaf2)] ++ freqSorterComplex [x | x <- xs, getInt2(x) > integer]

buildTreeHelper [] = []
buildTreeHelper [Leaf char integer]  = [Leaf char integer]
buildTreeHelper [Intermediate integer (leaf) (leaf2)]  = [Intermediate integer (leaf) (leaf2)]

buildTreeHelper ((Leaf char integer):(Leaf char2 integer2):xs) =
	buildTreeHelper (freqSorterComplex(xs ++ [Intermediate (integer+integer2) (Leaf char integer) (Leaf char2 integer2)] ))

buildTreeHelper ((Leaf char integer):(Intermediate integer2 (leaf) (leaf2)):xs) =
	buildTreeHelper (freqSorterComplex(xs ++ [Intermediate (integer+integer2) (Leaf char integer) (Intermediate integer2 (leaf) (leaf2))]))

buildTreeHelper ((Intermediate integer (leaf) (leaf2)):(Leaf char2 integer2):xs) 
	| integer == integer2 = buildTreeHelper (freqSorterComplex(xs ++ [Intermediate (integer+integer2) (Leaf char2 integer2) (Intermediate integer (leaf) (leaf2))]))
	| otherwise = buildTreeHelper (freqSorterComplex(xs ++ [Intermediate (integer+integer2) (Intermediate integer (leaf) (leaf2)) (Leaf char2 integer2)]))

buildTreeHelper ((Intermediate integer (leaf) (leaf2)):(Intermediate integer2 (leaf3) (leaf4)):xs) = 
	buildTreeHelper (freqSorterComplex(xs ++ [Intermediate (integer+integer2) (Intermediate integer (leaf) (leaf2)) (Intermediate integer2 (leaf3) (leaf4))]))

buildTree huffmanTreeList
	| huffmanTreeList == [Empty] = Empty
	| buildTreeHelper(huffmanTreeList) == [] = Empty
	| otherwise = buildTreeHelper(huffmanTreeList)!!0

----------------------------ENCODE---------------------------------------------

encodeHelper Empty string list = []
encodeHelper huffmanTree [] list = []
encodeHelper huffmanTree [] Empty = []
encodeHelper Empty [] Empty = []


encodeHelper (Intermediate integer (Leaf char2 integer2) (Leaf char3 integer3)) (x:xs) list
	| x == char2 = ['0'] ++ encodeHelper list xs list
	| x == char3 = ['1'] ++ encodeHelper list xs list
	| otherwise = []

encodeHelper (Intermediate integer (Leaf char2 integer2) (Intermediate integer3 (leaf) (leaf2))) (x:xs) list
	| x == char2 = ['0'] ++ encodeHelper list xs list 
	| otherwise = ['1'] ++ encodeHelper (Intermediate integer3 (leaf) (leaf2)) (x:xs) list

encodeHelper (Intermediate integer (Intermediate integer2 (leaf) (leaf2)) (Leaf char3 integer3)) (x:xs) list	
	| x == char3 = ['1'] ++ encodeHelper list xs list
	| otherwise = ['0'] ++ encodeHelper (Intermediate integer2 (leaf) (leaf2)) (x:xs) list

encodeHelper (Intermediate integer (Intermediate integer2 (leaf) (leaf2)) (Intermediate integer3 (leaf3) (leaf4))) (x:xs) list
	| (encodeHelper (Intermediate integer2 (leaf) (leaf2)) (x:xs) list) == [] = ['1'] ++ encodeHelper (Intermediate integer3 (leaf3) (leaf4)) (x:xs) list
	| otherwise = ['0'] ++ encodeHelper (Intermediate integer2 (leaf) (leaf2)) (x:xs) list

encode huffmanTree [] = []
encode (Leaf char integer) (x:xs)
	| char == x = ['0'] ++ encode (Leaf char integer) (xs)
	| otherwise = []
	
encode huffmanTree string = encodeHelper huffmanTree string huffmanTree

------------------------------------DECODE------------------------------------

decodeHelper Empty string list = []
decodeHelper huffmanTree [] list = []
decodeHelper huffmanTree [] Empty = []
decodeHelper Empty [] Empty = []

decodeHelper (Intermediate integer (Leaf char2 integer2) (Leaf char3 integer3)) (x:xs) list
	| x == '0' = [char2] ++ decodeHelper list xs list
	| x == '1' = [char3] ++ decodeHelper list xs list

decodeHelper (Intermediate integer (Leaf char2 integer2) (Intermediate integer3 (leaf) (leaf2))) (x:xs) list
	| x == '0' = [char2] ++ decodeHelper list xs list
	| otherwise = decodeHelper (Intermediate integer3 (leaf) (leaf2)) xs list

decodeHelper (Intermediate integer (Intermediate integer2 (leaf) (leaf2)) (Leaf char3 integer3)) (x:xs) list
	| x == '1' = [char3] ++ decodeHelper list xs list
	| otherwise = decodeHelper (Intermediate integer2 (leaf) (leaf2)) xs list

decodeHelper (Intermediate integer (Intermediate integer2 (leaf) (leaf2)) (Intermediate integer3 (leaf3) (leaf4))) (x:xs)  list
	| x == '0' = decodeHelper (Intermediate integer2 (leaf) (leaf2)) xs list
	| x == '1' = decodeHelper(Intermediate integer3 (leaf3) (leaf4)) xs list

decode huffmanTree [] = []
decode (Leaf char integer) (x:xs) = [char] ++ decode (Leaf char integer) (xs)
decode huffmanTree string = decodeHelper huffmanTree string huffmanTree