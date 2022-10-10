;Encontrar el valor de pi dada una exactitud insertada
;Definimos la función que calculará la serie
(define calcpi26
  (lambda (n)
    (if (= n 1) 1
        (+ (/ 1 (* n n)) (calcpi26 (sub1 n))))))

;Definimos la función que usará el valor de la serie,
;la multiplicará por 6 y luego le sacará la raíz cuadrada
(define (calcpi x)
  (sqrt(* 6 (calcpi26 x))))

