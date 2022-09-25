Algoritmo sin_titulo
	Imprimir "Bienvenido al juego de Piedra Papel o Tijera"
	
	Imprimir "Selecciona tu tiro"
	Imprimir "1: Piedra"
	Imprimir "2: Papel"
	Imprimir "3: Tijera"
	Leer TiroPlayer
	TiroPC=Azar(3)+1
	Si (TiroPlayer=1) y (TiroPC=3)
		Imprimir "Jugador: Piedra"
		Imprimir "PC: Tijera"
		Imprimir "Ganó el Jugador"
	Sino
		Si (TiroPlayer=1) y (TiroPC=2)
			Imprimir "Jugador: Piedra"
			Imprimir "PC: Papel"
			Imprimir "Ganó la PC"
		Sino
			Si (TiroPlayer=1) y (TiroPC=1)
				Imprimir "Jugador: Piedra"
				Imprimir "PC: Piedra"
				Imprimir "Empate"
			Sino
				Si (TiroPlayer=2) y (TiroPC=3)
					Imprimir "Jugador: Papel"
					Imprimir "PC: Tijera"
					Imprimir "Ganó la PC"
				Sino
					Si (TiroPlayer=2) y (TiroPC=2)
						Imprimir "Jugador: Papel"
						Imprimir "PC: Papel"
						Imprimir "Empate"
					Sino
						Si (TiroPlayer=2) y (TiroPC=1)
							Imprimir "Jugador: Papel"
							Imprimir "PC: Piedra"
							Imprimir "Ganó el Jugador"
						Sino
							Si (TiroPlayer=3) y (TiroPC=3)
								Imprimir "Jugador: Tijera"
								Imprimir "PC: Tijera"
								Imprimir "Empate"
							Sino
								Si (TiroPlayer=3) y (TiroPC=2)
									Imprimir "Jugador: Tijera"
									Imprimir "PC: Papel"
									Imprimir "Ganó el Jugador"
								Sino
									Si (TiroPlayer=3) y (TiroPC=1)
										Imprimir "Jugador: Tijera"
										Imprimir "PC: Piedra"
										Imprimir "Ganó la PC"
									Sino
										Imprimir "Opción inválida"
									FinSi
								FinSi
							FinSi
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
