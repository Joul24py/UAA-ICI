/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Examen: Resolver problemas mediante búsquedas: Búsqueda con algoritmos A* y MiniMax
Anexo 2.02: Algoritmo MiniMax

Profesor: Miguel Ángel Meza de Luna

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 25 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <locale.h>

//Funciones----------------------------------------------------------------------------------------------------
char gridChar(int i);
void draw(int b[9]);
int win(const int board[9]);
int minimax(int board[9], int player);
void computerMove(int board[9]);
void playerMove(int board[9]);

//El programa--------------------------------------------------------------------------------------------------
main()
{
	setlocale(LC_ALL,"");
	
	//Las casillas comienzan en 0. 1 = Computadora. -1 = Jugador 
	int board[9] = {0,0,0,0,0,0,0,0,0};
	
	//Asignaciones iniciales-----------------------------------------------------------------------------------
	printf("Computadora: O, Tú: X\nJugar\n(1) Primero\n(2) Segundo\n");
	int player=0;
	scanf("%d",&player);
	printf("\n");
	unsigned turn;
	
	//Comienza el juego----------------------------------------------------------------------------------------
	for(turn = 0; turn < 9 && win(board) == 0; ++turn)
	{
		if((turn+player) % 2 == 0)
		{
			computerMove(board);
		}
		else
		{
			draw(board);
			playerMove(board);
		}
	}
	
	//Despliegue de victoria por pantalla----------------------------------------------------------------------
	switch(win(board))
	{
		case 0:
			{
				draw(board);
				printf("\nOcurrió un empate\n");
				break;
			}
		case 1:
			{
				draw(board);
				printf("\nPerdiste\n");
				break;
			}
		case -1:
			{
				printf("\nGanaste\n");
				break;
			}
	}
}

//Convierte los valores numéricos que otras funciones otorgan a las letras que despliega el tablero------------
char gridChar(int i)
{
	switch(i)
	{
		case -1:
			{
				return 'X';
			}
		case 0:
			{
				return ' ';
			}
		case 1:
			{
				return 'O';
			}
	}
}

//Imprime el tablero por pantalla------------------------------------------------------------------------------
void draw(int b[9])
{
	printf(" %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));
}

//Evaluación de victoria del jugador---------------------------------------------------------------------------
int win(const int board[9])
{
	//Regresa un valor con el que se determina si el jugador ganó. Regresa 0 si el jugador no ha ganado
	unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	int i;
	for(i=0; i<8; ++i)
	{
		if(board[wins[i][0]] != 0 && board[wins[i][0]] == 
		board[wins[i][1]] && board[wins[i][0]] == board[wins[i][2]])
		{
			return board[wins[i][2]];
		}
	}
	return 0;
}

//El algoritmo MiniMax-----------------------------------------------------------------------------------------
int minimax(int board[9], int player)
{
	//Revisa si el jugador ya ha ganado
	int winner = win(board);
	if(winner != 0) return winner*player;
	
	int move = -1;
	int score = -2; //Los movimientos desfavorables son preferibles para la máquina de no hacerlos
	int i;
	for(i=0; i<9; ++i) //Revisa todas las casillas del tablero
	{
		if(board[i] == 0) //Revisa que no haya aún algún movimiento en esa casilla
		{
			board[i] = player; //Intenta un movimiento
			int thisScore = -minimax(board, player*-1);
			if(thisScore > score)
			{
				score = thisScore;
				move = i;
			}
			//Selecciona la que es la peor para el oponente
			board[i] = 0;//Reinicia el tablero
		}
	}
	
	//Retorna valor la función cuando encuentra el coste mínimo (que es -1)
	if(move == -1)
	{
		return 0;
	}
	//De lo contrario, retorna el coste que tiene en ese momento
	return score;
}

//La computadora juega-----------------------------------------------------------------------------------------
void computerMove(int board[9])
{
	int move = -1;
	int score = -2; //Los movimientos desfavorables son preferibles para la máquina de no hacerlos
	int i;
	for(i=0; i<9; ++i) //Revisa todas las casillas del tablero
	{
		if(board[i] == 0) //Revisa que no haya aún algún movimiento en esa casilla
		{
			board[i] = 1;
			int tempScore = -minimax(board, -1); //Entra a MiniMax después de haber visualizado su ambiente
			board[i] = 0;
			if(tempScore > score) //Al disminuir costes, trata de aumentar ganancias
			{
				score = tempScore; //Se asigna el puntaje más alto hallado y el movimiento que la originó
				move = i;
			}
		}
	}
	//Retorna un puntaje obtenido del MiniMax y del movimiento que le produzco este puntaje
	board[move] = 1;
}

//El jugador juega---------------------------------------------------------------------------------------------
void playerMove(int board[9])
{
	int move = 0;
	do
	{
		printf("\nTu movimiento ([0..8]): ");
		scanf("%d", &move);
		printf("\n");
	}
	while (move>=9 || move<0 && board[move]==0);
	board[move] = -1;
}
