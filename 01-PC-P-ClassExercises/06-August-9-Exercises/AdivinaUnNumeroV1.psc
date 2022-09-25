Algoritmo sin_titulo
	Imprimir "Nivel de dificultad:" 
	Imprimir "1: Fácil"
	Imprimir "2: Intermedio"
	Imprimir "3: Difícil"
	Leer dif
	cont=0
	Segun dif Hacer
		1:
			Imprimir "Adivina un número del 1 al 10"
			a=Azar(9)+1
			Mientras (x<>a) Hacer
				Leer x
				Si (x=a) Entonces
					Imprimir "Adivinaste"
				Sino
					Imprimir "No adivinaste"
					cont=cont+1
					Imprimir "Intentos: ", cont
				Fin Si
			Fin Mientras
		2:
			Imprimir "Adivina un número del 1 al 100"
			a=Azar(99)+1
			Mientras (x<>a) Hacer
				Leer x
				Si (x=a) Entonces
					Imprimir "Adivinaste"
				Sino
					Imprimir "No adivinaste"
					cont=cont+1
					Imprimir "Intentos: ", cont
				Fin Si
			Fin Mientras
		3:
			Imprimir "Adivina un número del 1 al 1000"
			a=Azar(999)+1
			Mientras (x<>a) Hacer
				Leer x
				Si (x=a) Entonces
					Imprimir "Adivinaste"
				Sino
					Imprimir "No adivinaste"
					cont=cont+1
					Imprimir "Intentos: ", cont
				Fin Si
			Fin Mientras
		De Otro Modo:
			Imprimir "Opción inválida"
	Fin Segun
	
FinAlgoritmo
