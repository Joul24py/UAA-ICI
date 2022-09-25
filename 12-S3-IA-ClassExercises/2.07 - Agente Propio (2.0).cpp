/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Evolución de un Agente Inteligente para Aprender a Pasar un Laberinto Específico
Anexo 2.07: Agente Propio (2.0)

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
int random,x=0,y=0,camino=0,cont=0;
bool ganador=false,vivo=true;

struct coord
{
	int x;
	int y;
	int dir;
} c1[50];

struct tablero
{
	float up;
	float down;
	float left;
	float right;
	char info;
} t[4][3];

//Las Funciones------------------------------------------------------------------------------------------------
void inicio();
void impr();
void actualizavalores();
float max(int a, int b);
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
			vivo=false;
			c1[cont].x=y;
			c1[cont].y=x;
			actualizavalores();
			impr();
			
			printf("\n\nMURIÓ\n");
			break;
		}
		if(x==2 && y==3)
		{
			ganador=true;
			c1[cont].x=y;
			c1[cont].y=x;
			actualizavalores();
			impr();
			
			printf("\n\nGANÓ\n");
			break;
		}
		
		//Movimientos del agente-------------------------------------------------------------------------------
		if(random==1)
		{
			t[y][x].info=' ';
			c1[cont].x=y;
			c1[cont].y=x;
			c1[cont].dir=random;
			cont++;
			y--; //Avanza hacia arriba
			camino++;
			t[y][x].info='O';
		}
		if(random==2)
		{
			t[y][x].info=' ';
			c1[cont].x=y;
			c1[cont].y=x;
			c1[cont].dir=random;
			cont++;
			x++; //Avanza hacia la derecha
			camino++;
			t[y][x].info='O';
		}
		if(random==3)
		{
			t[y][x].info=' ';
			c1[cont].x=y;
			c1[cont].y=x;
			c1[cont].dir=random;
			cont++;
			y++; //Avanza hacia abajo
			camino++;
			t[y][x].info='O';
		}
		if(random==4)
		{
			t[y][x].info=' ';
			c1[cont].x=y;
			c1[cont].y=x;
			c1[cont].dir=random;
			cont++;
			x--; //Avanza hacia la izquierda
			camino++;
			t[y][x].info='O';
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
	t[0][0].info='O';
	t[1][1].info='X';
	t[3][1].info=' ';
	t[3][1].up=0.1;
	t[3][1].down=0.1;
	t[3][1].left=0.1;
	t[3][1].right=0.1;
	t[3][2].info=' ';
	t[3][2].up=1;
	t[3][2].down=1;
	t[3][2].left=1;
	t[3][2].right=1;
}

//Impresión del tablero----------------------------------------------------------------------------------------
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

//Actualiza valores de la tabla--------------------------------------------------------------------------------
void actualizavalores()
{
	int i=1,j=0;
	float a,b;
	if(vivo==false)
	{
		a=0.1;
	}
	if(ganador==true)
	{
		a=0.9;
	}
	do
	{
		switch (c1[cont-i].dir)
		{
			case 1:
				{
					b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("%f\n",b);
					t[c1[cont-i].x][c1[cont-i].y].up=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("Norte\n");
					break;
				}
			case 2:
				{
					b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("%f\n",b);
					t[c1[cont-i].x][c1[cont-i].y].right=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("Este\n");
					break;
				}
			case 3:
				{
					b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("%f\n",b);
					t[c1[cont-i].x][c1[cont-i].y].down=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("Sur\n");
					break;
				}
			case 4:
				{
					b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("%f\n",b);
					t[c1[cont-i].x][c1[cont-i].y].left=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right))*a;
					printf("Oeste\n");
					break;
				}
		}
		i++;
		j++;
	}
	while(j<cont);
}

//Función utilizada para actualizavalores----------------------------------------------------------------------
float max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
