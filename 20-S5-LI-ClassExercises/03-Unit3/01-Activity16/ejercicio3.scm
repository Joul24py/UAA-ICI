;Definición de la función
(define (convert3 n1 n2 n3)
  (+ (* n3 100) (* n2 10) n1))

(convert3 1 1 1)
(convert3 5 3 4)

;Determine el valor en n = 2m n = 5 y n = 9 y expréselo en forma de programa

;a) Evaluar n^2 + 10
;Definimos la función
(define (g n)
  (+ (* n n) 10))

(g 2)
(g 5)
(g 9)

;b) Evaluar (1/2) * n^2 + 20
;Definimos la función
(define (h n)
  (+ (* (/ 1 2) (* n n)) 20))

(h 2)
(h 5)
(h 9)

;c) Evaluar 2 - (1/n)
;Definimos la función
(define (b n)
  (- 2 (/ 1 n)))

(b 2)
(b 5)
(b 9)