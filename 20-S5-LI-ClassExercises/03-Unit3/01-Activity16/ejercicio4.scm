;Definir el programa suma-monedas. Consume cuatro números:
;el número de monedas de $1, $2, $5, $10 en la bolsa y
;produce la cantidad de dinero en la bolsa

;Definición de la función
(define (suma-monedas m1 m2 m3 m4)
  (+ (* m1 1) (* m2 2) (* m3 5) (* m4 10)))

(suma-monedas 100 40 30 20)
(suma-monedas 23 40 200 10)