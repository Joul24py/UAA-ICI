Algoritmo sin_titulo
	Imprimir "Bienvenido:"
	Imprimir "Elija la opción para invertir un número según la cantidad de dígitos que éste tenga:"
	Imprimir " "
	Imprimir "1: 3 dígitos"
	Imprimir "2: 4 dígitos"
	Imprimir "3: 5 dígitos"
	Imprimir " "
	Leer x
	Si (x=1) Entonces
		Imprimir "Dame un número de tres dígitos"
		Leer z
		a=trunc(z/100)
		b=(trunc(z/10)-(a*10))
		c=(z-(a*100)-(b*10))
		Imprimir "El número invertido es ", c b a
	Sino
		Si (x=2) Entonces
			Imprimir "Dame un número de cuatro dígitos"
			Leer z
			a=trunc(z/1000)
			b=(trunc(z/100)-(a*10))
			c=(trunc(z/10)-(a*100)-(b*10))
			d=(z-(a*1000)-(b*100)-(c*10))
			Imprimir "El número invertido es ", d c b a
		Sino
			Si (x=3) Entonces
				Imprimir "Dame un número de cinco dígitos"
				Leer z
				a=trunc(z/10000)
				b=(trunc(z/1000)-(a*10))
				c=(trunc(z/100)-(a*100)-(b*10))
				d=(trunc((z/10)-(a*1000)-(b*100)-(c*10)))
				e=(z-(a*10000)-(b*1000)-(c*100)-(d*10))
				Imprimir "El número invertido es ", e d c b a
			FinSi
		FinSi
	FinSi
FinAlgoritmo