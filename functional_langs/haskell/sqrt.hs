avg x y = (x + y)/2
square x = x * x
good_enough guess x = (abs ((square guess) - x)) < 0.00001
improve guess x = (avg guess (x / guess))
sqrt_iter guess x = if (good_enough guess x)
                    then guess
                    else (sqrt_iter (improve guess x) x)
sqroot x = (sqrt_iter 1.0 x)
