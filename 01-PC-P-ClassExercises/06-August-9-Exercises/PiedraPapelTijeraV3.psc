Algoritmo sin_titulo
	Imprimir "Bienvenido al juego de Piedra Papel o Tijera"
	Imprimir "Jugar al que llegue primero a ___ puntos"
	Leer Total
	Player=0
	PC=0
	Repetir
		Imprimir " "
		Imprimir "------------------------------"
		Imprimir "Selecciona tu tiro"
		Imprimir "1: Piedra"
		Imprimir "2: Papel"
		Imprimir "3: Tijera"
		Imprimir "------------------------------"
		Imprimir " "
		Leer TiroPlayer
		TiroPC=Azar(3)+1
		Si (TiroPlayer=1) y (TiroPC=3)
			Imprimir "Jugador: Piedra"
			Imprimir "PC: Tijera"
			Imprimir "Ganó el Jugador"
			Player=Player+1
			Imprimir " "
			Imprimir "Al primero a llegar a ", Total, " puntos"
			Imprimir "Jugador ", Player, " - ", PC " PC"
		Sino
			Si (TiroPlayer=1) y (TiroPC=2)
				Imprimir "Jugador: Piedra"
				Imprimir "PC: Papel"
				Imprimir "Ganó la PC"
				PC=PC+1
				Imprimir " "
				Imprimir "Al primero a llegar a ", Total, " puntos"
				Imprimir "Jugador ", Player, " - ", PC " PC"
			Sino
				Si (TiroPlayer=1) y (TiroPC=1)
					Imprimir "Jugador: Piedra"
					Imprimir "PC: Piedra"
					Imprimir "Empate"
					Imprimir " "
					Imprimir "Al primero a llegar a ", Total, " puntos"
					Imprimir "Jugador ", Player, " - ", PC " PC"
				Sino
					Si (TiroPlayer=2) y (TiroPC=3)
						Imprimir "Jugador: Papel"
						Imprimir "PC: Tijera"
						Imprimir "Ganó la PC"
						PC=PC+1
						Imprimir " "
						Imprimir "Al primero a llegar a ", Total, " puntos"
						Imprimir "Jugador ", Player, " - ", PC " PC"
					Sino
						Si (TiroPlayer=2) y (TiroPC=2)
							Imprimir "Jugador: Papel"
							Imprimir "PC: Papel"
							Imprimir "Empate"
							Imprimir " "
							Imprimir "Al primero a llegar a ", Total, " puntos"
							Imprimir "Jugador ", Player, " - ", PC " PC"
						Sino
							Si (TiroPlayer=2) y (TiroPC=1)
								Imprimir "Jugador: Papel"
								Imprimir "PC: Piedra"
								Imprimir "Ganó el Jugador"
								Player=Player+1
								Imprimir " "
								Imprimir "Al primero a llegar a ", Total, " puntos"
								Imprimir "Jugador ", Player, " - ", PC " PC"
							Sino
								Si (TiroPlayer=3) y (TiroPC=3)
									Imprimir "Jugador: Tijera"
									Imprimir "PC: Tijera"
									Imprimir "Empate"
									Imprimir " "
									Imprimir "Al primero a llegar a ", Total, " puntos"
									Imprimir "Jugador ", Player, " - ", PC " PC"
								Sino
									Si (TiroPlayer=3) y (TiroPC=2)
										Imprimir "Jugador: Tijera"
										Imprimir "PC: Papel"
										Imprimir "Ganó el Jugador"
										Player=Player+1
										Imprimir " "
										Imprimir "Al primero a llegar a ", Total, " puntos"
										Imprimir "Jugador ", Player, " - ", PC " PC"
									Sino
										Si (TiroPlayer=3) y (TiroPC=1)
											Imprimir "Jugador: Tijera"
											Imprimir "PC: Piedra"
											Imprimir "Ganó la PC"
											PC=PC+1
											Imprimir " "
											Imprimir "Al primero a llegar a ", Total, " puntos"
											Imprimir "Jugador ", Player, " - ", PC " PC"
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
	Hasta Que (Total=Player) o (Total=PC)
FinAlgoritmo
