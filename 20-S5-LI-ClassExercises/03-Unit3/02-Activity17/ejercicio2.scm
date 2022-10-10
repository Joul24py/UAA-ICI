;Desarrollar el programa para hallar el volumen de un cilindro
;Entradas: Radio de la base y altura
;Salida: El volumen del cilindro

;Definimos las funciones
(define (volcilindro r h)
  (* PI r r h))

(define PI 3.14)

;Ejemplos
(volcilindro 3 2)
(volcilindro 4 6)
(volcilindro 6 3)