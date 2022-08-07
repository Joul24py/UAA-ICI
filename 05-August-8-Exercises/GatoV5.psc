Algoritmo sin_titulo
	Imprimir "Gato Rudimentario Para Novatos"
	p1=" "
	p2=" "
	p3=" "
	p4=" "
	p5=" "
	p6=" "
	p7=" "
	p8=" "
	p9=" "
	Mientras flag=0
		Imprimir " "
		Imprimir "**************************************"
		Imprimir " "
		Imprimir p1, " | ", p2 " | ", p3
		Imprimir "---------"
		Imprimir p4, " | ", p5 " | ", p6
		Imprimir "---------"
		Imprimir p7, " | ", p8 " | ", p9
		Imprimir " "
		Imprimir "**************************************"
		Imprimir " "
		Imprimir "¿Qué tiro quieres hacer?"
		Leer tiro
		Imprimir "¿Qué tipo?"
		Leer tipo
		Segun tiro Hacer
			Caso 1:
				p1=tipo
			Caso 2:
				p2=tipo
			Caso 3:
				p3=tipo
			Caso 4:
				p4=tipo
			Caso 5:
				p5=tipo
			Caso 6:
				p6=tipo
			Caso 7:
				p7=tipo
			Caso 8:
				p8=tipo
			Caso 9:
				p9=tipo
		Fin Segun
		Si p1="o" y p2="o" y p3="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p4="o" y p5="o" y p6="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p7="o" y p8="o" y p9="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p1="o" y p4="o" y p7="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p2="o" y p5="o" y p8="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p3="o" y p6="o" y p9="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p1="o" y p5="o" y p9="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p7="o" y p5="o" y p3="o"
			Imprimir "Ganó Jugador o"
			flag=flag+1
		FinSi
		Si p1="x" y p2="x" y p3="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p4="x" y p5="x" y p6="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p7="x" y p8="x" y p9="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p1="x" y p4="x" y p7="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p2="x" y p5="x" y p8="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p3="x" y p6="x" y p9="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p1="x" y p5="x" y p9="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
		Si p7="x" y p5="x" y p3="x"
			Imprimir "Ganó Jugador x"
			flag=flag+1
		FinSi
	Fin Mientras
	Imprimir "<<<<<<¡FELICIDADES!>>>>>> "
	Imprimir " "
	Imprimir "**************************************"
	Imprimir " "
	Imprimir p1, " | ", p2 " | ", p3
	Imprimir "---------"
	Imprimir p4, " | ", p5 " | ", p6
	Imprimir "---------"
	Imprimir p7, " | ", p8 " | ", p9
	Imprimir " "
	Imprimir "**************************************"
	Imprimir " "
FinAlgoritmo
