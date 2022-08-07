Algoritmo sin_titulo
	Imprimir "Inserte una calificación"
	Leer x
	a=10-x
	b=6.5-x
	Si (x<0)
		Imprimir "Dato no válido"
	SiNo
		Si (x>10)
			Imprimir "Dato no válido"
		SiNo
			Si (x=10)
				Imprimir "Felicidades, su calificación es el máximo posible"
			SiNo
				Si (x>=6.5)
					Imprimir "Su calificación es " x ". Le falta " a " para llegar a la calificación máxima"
				SiNo
					Imprimir "Su calificación es " x ". Le falta " b " para pasar. A su vez, le falta " a " para llegar a la calificación máxima"
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
