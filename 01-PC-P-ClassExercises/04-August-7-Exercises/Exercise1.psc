Algoritmo sin_titulo
	Imprimir "Dame un número de cuatro dígitos"
	Leer x
	Si (x>999) y (x<10000) Entonces
		a=trunc(x/1000)
		b=(trunc(x/100)-(a*10))
		c=(trunc(x/10)-(a*100)-(b*10))
		d=(x-(a*1000)-(b*100)-(c*10))
		Imprimir "El número invertido es ", d c b a
	Sino
		Imprimir "El número dado no es válido"
		Imprimir "Por favor reinice el programa"
	FinSi
FinAlgoritmo