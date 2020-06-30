russianMul a b 
  | a == 1 = b
  | (mod a 2 /= 0) = b + russianMul (div a 2) (b * 2)
  | otherwise = russianMul (div a 2) (b * 2)

countEvens numbers = length [i | i <- numbers, mod i 2 == 0]

getSmallerThan numbers n = [i | i <- numbers, i <= n]