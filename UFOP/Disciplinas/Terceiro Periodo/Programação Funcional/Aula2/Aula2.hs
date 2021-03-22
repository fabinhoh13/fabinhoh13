perfectNum :: Int -> [Int]
perfectNum n = [x | x <- [1..n], x == sum(init(factor(x)))]
    where
        factor n = [x | x <- [1..n], n `mod` x == 0]


primo :: Int -> [Int]
primo n = [x | x <- [1..n], length(factors(x)) == 2]
    where 
        factors :: Int -> [Int]
        factors n = [x | x <- [1..n], n `mod` x == 0]


max3 :: Int -> Int -> Int -> Int
max3 a b c =
  if (a > c) && (a > b)
    then a
  else if (b > a) && (b > c)
    then b
    else c

vetor :: (Double , Double) -> (Double, Double)
vetor (x,y) = (x / (sqrt(x^2 + y^2)), y / (sqrt(x^2 + y^2)))


listaMenorDois :: [a] -> Bool
listaMenorDois [] = True
listaMenorDois [_] = True
listaMenorDois [_, _] = True
listaMenorDois _ = False

listaMenorDois' :: [a] -> Bool
listaMenorDois' [ ] = True
listaMenorDois' (x:xs)
   length((x:xs)) <= 2 = True
   otherwise = False