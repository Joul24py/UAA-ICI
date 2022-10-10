;Teniendo en cuenta algunos intervalos,
;observamos si un número puede encontrarse dentro de estos

;1) El intervalo (3,7]
(define (int3a7c n)
  (and (> n 3) (<= n 7)))

;2) El intervalo [3,7]
(define (int3c7c n)
  (and (>= n 3) (<= n 7)))

;3) El intervalo [3,9)
(define (int3c9a n)
  (and (>= n 3) (< n 9)))

;4) El intervalo (1,3) U (9,11)
(define (int1a3a-9a11a n)
  (or (and (> n 1) (< n 3)) (and (> n 9) (< n 11))))

;5) El rango de números fuera del intervalo [1,3]
(define (notint1c3c n)
  (not (and (>= n 1) (<= n 3))))