/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Evolución de un Agente Inteligente para Aprender a Pasar un Laberinto Específico
Anexo 2.05: Agente Propio (1.0)

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
	Reyes González Andrés Eleazar
	Ortíz Nájera Alan Daniel

Aguascalientes, Ags. 30 de septiembre de 2019
*/

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;

//Las Variables------------------------------------------------------------------------------------------------
char tablero[4][3];
int random,x=0,y=0;
string camino=" ";
bool ganador=false,vivo=true;

//Las Funciones------------------------------------------------------------------------------------------------
void inicio();
void impr();
//-------------------------------------------------------------------------------------------------------------

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	inicio();
	impr();
	Sleep(2000);
	
	do
	{
		//Genera un número aleatorio para el movimiento del agente---------------------------------------------
		random=1+rand()%(5-1);
		system("CLS");
		
		/*
		La dirección a la cual se moverá según el número asignado
		1: Norte
		2: Este
		3: Sur
		4: Oeste
		*/
		
		//Restricciones de movimiento--------------------------------------------------------------------------
		if(random==1 && y==0)
		{
			continue; //Imposibilita movimiento hacia arriba
		}
		if(random==1 && (x==1 && y==2))
		{
			continue; //Imposibilita movimiento hacia arriba (cuadrito)
		}
		if(random==2 && x==2)
		{
			continue; //Imposibilita movimiento hacia la derecha
		}
		if(random==2 && (x==0 && y==1))
		{
			continue; //Imposibilita movimiento hacia la derecha (cuadrito)
		}
		if(random==3 && y==3)
		{
			continue; //Imposibilita movimiento hacia abajo
		}
		if(random==3 && (x==1 && y==0))
		{
			continue; //Imposibilita movimiento hacia abajo (cuadrito)
		}
		if(random==4 && x==0)
		{
			continue; //Imposibilita movimiento hacia la izquierda
		}
		if(random==4 && (x==2 && y==1))
		{
			continue; //Imposibilita movimiento hacia la izquierda (cuadrito)
		}
		
		//Validaciones de victoria o derrota-------------------------------------------------------------------
		if(x==1 && y==3)
		{
			impr();
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
			
			printf("\n\nMURIÓ\n");
			vivo=false;
			break;
		}
		if(x==2 && y==3)
		{
			impr();
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
			
			printf("\n\nGANÓ\n");
			ganador=true;
			break;
		}
		
		//Movimientos del agente-------------------------------------------------------------------------------
		if(random==1)
		{
			tablero[y][x]=' ';
			y--; //Avanza hacia arriba
			tablero[y][x]='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==2)
		{
			tablero[y][x]=' ';
			x++; //Avanza hacia la derecha
			tablero[y][x]='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==3)
		{
			tablero[y][x]=' ';
			y++; //Avanza hacia abajo
			tablero[y][x]='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==4)
		{
			tablero[y][x]=' ';
			x--; //Avanza hacia la izquierda
			tablero[y][x]='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		//-----------------------------------------------------------------------------------------------------
		
		impr();
		Sleep(500);
	}
	while(vivo==true && ganador==false);
	
	
	getchar();
}

//Inicialización del tablero-----------------------------------------------------------------------------------
void inicio()
{
	int i=0,j=0;
	do
	{
		do
		{
			tablero[i][j]=' ';
			j++;
		}
		while(j<3);
		j=0;
		i++;
	}
	while(i<4);
	tablero[0][0]='O';
	tablero[1][1]='X';
	tablero[3][1]=' ';
	tablero[3][2]=' ';
	
	camino.push_back(x+48);
	camino.push_back(',');
	camino.push_back(y+48);
	camino.push_back(' ');
}

//Impresión del tablero----------------------------------------------------------------------------------------
void impr() //NO HACER CASO IMPRESION COMPLEJA
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("    0.000            0.000            0.000     \n");
	printf("0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[0][0]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000    0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[0][1]); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000    0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[0][2]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000 \n");
	printf("    0.000            0.000            0.000     \n");
	printf("\n");
	
	printf("    0.000                             0.000     \n");
	printf("0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[1][0]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000          ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	printf("%c",tablero[1][1]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("          0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[1][2]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000 \n");
	printf("    0.000                             0.000     \n");
	printf("\n");
	
	printf("    0.000            0.000            0.000     \n");
	printf("0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[2][0]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000    0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[2][1]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000    0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[2][2]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000 \n");
	printf("    0.000            0.000            0.000     \n");
	printf("\n");
	
	printf("    0.000           -1.000            1.000     \n");
	printf("0.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[3][0]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 0.000   -1.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[3][1]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("-1.000    1.000 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c",tablero[3][2]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf(" 1.000 \n");
	printf("    0.000           -1.000            1.000     \n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<"\n\n"<<camino;
}
