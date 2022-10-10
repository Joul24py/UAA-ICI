;Traslade las siguientes tres funciones de LISP a Scheme de intervalos 
;sobre la recta real, tambi?n formule el contrato y el prop?sito 
;para cada una:

;1. 
(define (in-interval-1? x)
       (and (< -3 x) (< x 0)))

;Ejemplo 1, Resultado esperado: VERDADERO
(in-interval-1? -2.9)

;Ejemplo 2, Resultado esperado: VERDADERO
(in-interval-1? -0.1)

;Ejemplo 3, Resultado esperado: FALSO
(in-interval-1? 3)

;Ejemplo 4, Resultado esperado: FALSO
(in-interval-1? 0)

;El intervalo en la recta real es: (-3,0).

;CONTRATO
;in-interval-1? :  n?mero -> boolean

;PROP?SITO
;Determinar el intervalo soluci?n para la funci?n expresada.

;2. 
(define (in-interval-2? x)
       (or (< x 1) (> x 2)))

;Ejemplo 1, Resultado esperado: FALSO
(in-interval-2? 1)

;Ejemplo 2, Resultado esperado: FALSO
(in-interval-2? 2)

;Ejemplo 3, Resultado esperado: VERDADERO
(in-interval-2? 0.9)

;Ejemplo 4, Resultado esperado: VERDADERO
(in-interval-2? 2.1)

;La soluci?n en la recta real es el rango externo del intervalo 
;[1,2].

;CONTRATO
;in-interval-2? :  n?mero -> boolean

;PROP?SITO
;Determinar el intervalo soluci?n para la funci?n expresada.

;3. 
(define (in-interval-3? x)
       (not (and (<= 1 x) (<= x 5))))

;Ejemplo 1, Resultado esperado: FALSO
(in-interval-3? 1)

;Ejemplo 2, Resultado esperado: FALSO
(in-interval-3? 5)

;Ejemplo 3, Resultado esperado: VERDADERO
(in-interval-3? 0.9)

;Ejemplo 4, Resultado esperado: VERDADERO
(in-interval-3? 5.1)

;La soluci?n en la recta real es el rango externo del intervalo 
;[1,5].

;CONTRATO
;in-interval-3? :  n?mero -> boolean

;PROP?SITO
;Determinar el intervalo soluci?n para la funci?n expresada.

