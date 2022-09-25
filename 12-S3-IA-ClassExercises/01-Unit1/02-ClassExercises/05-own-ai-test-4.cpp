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

struct tablero
{
	float up;
	float down;
	float left;
	float right;
	char info;
} t[4][3];

void inicio();
void impr();

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	inicio();
	impr();
	Sleep(2000);
	
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
			t[y][x].info=' ';
			y--; //Avanza hacia arriba
			t[y][x].info='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==2)
		{
			t[y][x].info=' ';
			x++; //Avanza hacia la derecha
			t[y][x].info='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==3)
		{
			t[y][x].info=' ';
			y++; //Avanza hacia abajo
			t[y][x].info='O';
			
			camino.push_back(x+48);
			camino.push_back(',');
			camino.push_back(y+48);
			camino.push_back(' ');
		}
		if(random==4)
		{
			t[y][x].info=' ';
			x--; //Avanza hacia la izquierda
			t[y][x].info='O';
			
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
	t[0][0].info='O';
	t[1][1].info='X';
	t[3][1].info=' ';
	t[3][1].up=0;
	t[3][1].down=0;
	t[3][1].left=0;
	t[3][1].right=0;
	t[3][2].info=' ';
	t[3][2].up=1;
	t[3][2].down=1;
	t[3][2].left=1;
	t[3][2].right=1;
	
	camino.push_back(x+48);
	camino.push_back(',');
	camino.push_back(y+48);
	camino.push_back(' ');
}

void impr()
{
	int i=0;
	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("     %0.3f            %0.3f            %0.3f    \n",t[i][0].up,t[i][1].up,t[i][2].up);
		printf("%0.3f ",t[i][0].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("%c",t[i][0].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f    %0.3f ",t[i][0].right,t[i][1].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("%c",t[i][1].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f    %0.3f ",t[i][1].right,t[i][2].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("%c",t[i][2].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f \n",t[i][2].right);
		printf("     %0.3f            %0.3f            %0.3f     \n",t[i][0].down,t[i][1].down,t[i][2].down);
		printf("\n");
		i++;
	}
	while(i<4);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<"\n\n"<<camino;
}
