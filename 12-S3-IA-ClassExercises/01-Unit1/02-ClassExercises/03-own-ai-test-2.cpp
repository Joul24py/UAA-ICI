#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int random,x=0,y=0;
char tablero[4][3];
string camino=" ";
bool vivo=true;
bool ganador=false;

void inicio();
void impr();

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	inicio();
	impr();
	Sleep(1000);
	
	do
	{
		random=1+rand()%(5-1);
		system("CLS");
		
		/*
		1: Norte
		2: Este
		3: Sur
		4: Oeste
		*/
		
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
		
		impr();
		Sleep(500);
	}
	while(vivo==true && ganador==false);
	
	
	getchar();
}

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

void impr()
{
	printf("    0.000            0.000            0.000     \n");
	printf("0.000 %c 0.000    0.000 %c 0.000    0.000 %c 0.000 \n",tablero[0][0],tablero[0][1],tablero[0][2]);
	printf("    0.000            0.000            0.000     \n");
	printf("\n");
	printf("    0.000                             0.000     \n");
	printf("0.000 %c 0.000          %c          0.000 %c 0.000 \n",tablero[1][0],tablero[1][1],tablero[1][2]);
	printf("    0.000                             0.000     \n");
	printf("\n");
	printf("    0.000            0.000            0.000     \n");
	printf("0.000 %c 0.000    0.000 %c 0.000    0.000 %c 0.000 \n",tablero[2][0],tablero[2][1],tablero[2][2]);
	printf("    0.000            0.000            0.000     \n");
	printf("\n");
	printf("    0.000           -1.000            1.000     \n");
	printf("0.000 %c 0.000   -1.000 %c-1.000    1.000 %c 1.000 \n",tablero[3][0],tablero[3][1],tablero[3][2]);
	printf("    0.000           -1.000            1.000     \n");
	
	cout<<"\n\n"<<camino;
}
