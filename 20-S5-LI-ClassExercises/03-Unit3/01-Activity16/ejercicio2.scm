(define fact
  (lambda (n)
    (if (zero? n) 1
        (* n (fact (sub1 n))))))

(fact 20)
(fact 5)
(fact 0)
(fact 70)