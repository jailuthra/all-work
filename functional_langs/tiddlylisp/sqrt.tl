(define abs
    (lambda (x) (if (> x 0) x (- 0 x))))

(define avg (lambda (x y) (* 0.5 (+ x y))))

(define square (lambda (x) (* x x)))

(define good-enough?
    (lambda (guess x) (< (abs (- x (square guess))) 0.00001)))

(define improve (lambda (guess x) (avg guess (/ x guess))))

(define sqrt-iter
    (lambda (guess x)
        (if (good-enough? guess x) guess (sqrt-iter (improve guess x) x))))

(define sqrt (lambda (x) (sqrt-iter 1.0 x)))


