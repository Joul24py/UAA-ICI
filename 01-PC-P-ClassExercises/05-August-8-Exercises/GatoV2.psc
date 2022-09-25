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
	Para x=1 Hasta 9 Con Paso 1 Hacer
		Imprimir p1, " | ", p2 " | ", p3
		Imprimir "---------"
		Imprimir p4, " | ", p5 " | ", p6
		Imprimir "---------"
		Imprimir p7, " | ", p8 " | ", p9
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
	Fin Para
FinAlgoritmo