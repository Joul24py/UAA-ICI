Algoritmo sin_titulo
	Imprimir "Elija un número"
	Imprimir "1: Círculo"
	Imprimir "2: Triángulo"
	Imprimir "3: Cuadrado"
	Imprimir "4: Rectángulo"
	Leer x
	Segun (x) Hacer
		Caso 1:
			Imprimir "Escribe el valor del radio"
			Leer a
			circ=PI*(a^2)
			Imprimir "El valor del area es ", circ, "unidades cuadradas"
		Caso 2:
			Imprimir "Escribe el valor de la base del triángulo"
			Leer b
			Imprimir "Escribe el valor de la altura del triángulo"
			Leer c
			tria=(b*c)/2
			Imprimir "El valor del area es ", tria, "unidades cuadradas"
		Caso 3:
			Imprimir "Escribe el valor del lado del cuadrado"
			Leer d
			cuad=(d*d)
			Imprimir "El valor del area es ", cuad, "unidades cuadradas"
		Caso 4:
			Imprimir "Escribe el valor de la base del rectángulo"
			Leer e
			Imprimir "Escribe el valor de la altura del rectángulo"
			Leer f
			rect=(e*f)
			Imprimir "El valor del área es ", rect, "unidades cuadradas"
		De Otro Modo:
			Imprimir "Opción inválida"
	Fin Segun
FinAlgoritmo
