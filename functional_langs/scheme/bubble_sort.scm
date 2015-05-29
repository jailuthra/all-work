(define sort
  (lambda (x)
    (cond ((null? x) x)
          ((= (length x) 1) x)
          ((<= (car x) (cadr x))
           (check-again (cons (car x) (sort (cdr x)))))
          (#t (check-again (cons (cadr x) (sort (cons (car x) (cddr x))))))
    )
  )
)

(define check-again
  (lambda (x)
    (if (<= (car x) (cadr x)) x
        (sort x)
    )
  )
)
