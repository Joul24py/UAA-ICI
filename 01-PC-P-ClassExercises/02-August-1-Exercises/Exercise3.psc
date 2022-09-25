Segundos a Minutos y Segundos

Algoritmo TAREA3DEFINITIVO
	Imprimir "Inserte un valor de tiempo (en segundos)"
	Leer x
	Si (x<60) Entonces
		Imprimir "Su valor es equivalente a " x " segundos"
	SiNo
		Si (x MOD 60 = 0) Entonces
			b=x/60
			Imprimir "Su valor es equivalente a " b " minutos"
		SiNo
			a=x
			Hacer
				x=x-60
			Hasta Que (x<60)
			z=(a-x)/60
			Imprimir "Su valor es equivalente a " z " minutos y " x " segundos"
		Fin Si
	Fin Si
FinAlgoritmo