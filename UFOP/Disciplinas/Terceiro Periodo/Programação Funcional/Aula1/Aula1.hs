somaMaiores :: Int -> Int -> Int -> Int
somaMaiores a b c =
  if (a >= c) && (b >= c)
    then a*a + b*b
  else if (a >= b) && (c >= b)
    then a*a + c*c
    else b*b + c*c

fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)


fibonacciLinear :: Int-> Double
fibonacciLinear n = (((1 + sqrt 5)/2)^n - (1 - (sqrt 5)/2)^n)/(sqrt 5)