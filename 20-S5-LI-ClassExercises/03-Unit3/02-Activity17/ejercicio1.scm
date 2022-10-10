;Desarrollar el programa para hallar el área de un cilindro
;Entradas: Radio de la base y altura
;Salida: El área del cilíndro

;Definimos las funciones
(define (areacilindro r h)
  (+ (* 2 PI r h) (* 2 PI (* r r))))

(define PI 3.14)

;Ejemplos
(areacilindro 3 2)
(areacilindro 4 6)
(areacilindro 6 3)