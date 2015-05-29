bbsort :: (Ord a) => [a] -> [a]
bbsort [] = []
bbsort (x:[]) = [x]
bbsort (x:y:xs) = if x <= y
             then check_again (x:(bbsort (y:xs)))
             else check_again (y:(bbsort (x:xs)))

check_again :: (Ord a) => [a] -> [a]
check_again (x:xs) = if x <= (head xs) then (x:xs)
                  else (bbsort (x:xs))
