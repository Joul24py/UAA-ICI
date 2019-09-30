/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Evolución de un Agente Inteligente para Aprender a Pasar un Laberinto Específico
Anexo 2.13: Agente Propio (Version Final)

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

//Las Variables de Menú----------------------------------------------------------------------------------------
int intel=1,menucant1,menucant2,menuvel,menuclean=0;
float menudesc;

//Las Variables de Uso Tradicional-----------------------------------------------------------------------------
int camino=0,cont=0,muertos=0,random,victoria=0,x=0,y=0;
bool ganador=false,vivo=true;

struct tablero
{
	float up;
	float down;
	float left;
	float right;
	char info;
} t[4][3];

struct coord
{
	int x;
	int y;
	int dir;
} c1[100];

//Las Funciones------------------------------------------------------------------------------------------------
void calibrar();
void paso1();
void inicio();
void imprimir();
void actualizavalores();
float max(float a, float b);
float absol(float a);
int aleatorio();
//-------------------------------------------------------------------------------------------------------------

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	int menucont1=0,menucont2=-1;
	calibrar();
	paso1();
	do
	{
		inicio();
		system("CLS");
		imprimir();
		x=0;
		y=0;
		do
		{
			//Genera un número aleatorio para el movimiento del agente-----------------------------------------
			random=aleatorio();
			
			/*
			La dirección a la cual se moverá según el número asignado
			1: Norte
			2: Este
			3: Sur
			4: Oeste
			*/
			
			//Restricciones de movimiento----------------------------------------------------------------------
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
			
			//Validaciones de victoria o derrota---------------------------------------------------------------
			if(x==1 && y==3)
			{
				vivo=false;
				muertos++;
				c1[cont].x=y;
				c1[cont].y=x;
				actualizavalores();
				if(menucont2+1==menucant2)
				{
					system("CLS");
					imprimir();
				}
				
				printf("\n\nMURIÓ\n");
				break;
			}
			if(x==2 && y==3)
			{
				ganador=true;
				victoria++;
				c1[cont].x=y;
				c1[cont].y=x;
				actualizavalores();
				if(menucont2+1==menucant2)
				{
					system("CLS");
					imprimir();
				}
				
				printf("\n\nGANÓ\n");
				break;
			}
			
			//Movimientos del agente---------------------------------------------------------------------------
			if(random==1)
			{
				t[y][x].info=' ';
				c1[cont].x=y;
				c1[cont].y=x;
				c1[cont].dir=random;
				cont++;
				y--; //Avanza hacia arriba
				t[y][x].info='O';
				camino++;
				if(menuvel!=0)
				{
					system("CLS");
					imprimir();
					menuclean=1;
				}
			}
			if(random==2)
			{
				t[y][x].info=' ';
				c1[cont].x=y;
				c1[cont].y=x;
				c1[cont].dir=random;
				cont++;
				x++; //Avanza hacia la derecha
				t[y][x].info='O';
				camino++;
				if(menuvel!=0)
				{
					system("CLS");
					imprimir();
					menuclean=1;
				}
			}
			if(random==3)
			{
				t[y][x].info=' ';
				c1[cont].x=y;
				c1[cont].y=x;
				c1[cont].dir=random;
				cont++;
				y++; //Avanza hacia abajo
				t[y][x].info='O';
				camino++;
				if(menuvel!=0)
				{
					system("CLS");
					imprimir();
					menuclean=1;
				}
			}
			if(random==4)
			{
				t[y][x].info=' ';
				c1[cont].x=y;
				c1[cont].y=x;
				c1[cont].dir=random;
				cont++;
				x--; //Avanza hacia la izquierda
				t[y][x].info='O';
				camino++;
				if(menuvel!=0)
				{
					system("CLS");
					imprimir();
					menuclean=1;
				}
			}
			//-------------------------------------------------------------------------------------------------
			
			Sleep(menuvel);
		}
		while(vivo==true && ganador==false);
		
		//Reinicia las variables para comenzar otra evaluación con otro agente más-----------------------------
		ganador=false;
		vivo=true;
		cont=0;
		camino=0;
		menucont1++;
	}
	while(menucont1<menucant2);
	
	getchar();
}

//Calibrar el programa: Cantidad de agentes, descuento, velocidad e incluso ver el proceso---------------------
void calibrar()
{
		printf("Cantidad de agentes inteligentes: ");
		scanf("%d",&menucant2);
		printf("Descuento: ");
		scanf("%f",&menudesc);
		printf("Velocidad del agente (milisegundos): ");
		scanf("%d",&menuvel);
		//Con menuvel = 0 deshabilita la tabla visible en los primeros n - 1 agentes
}

//Primer inicialización de datos-------------------------------------------------------------------------------
void paso1()
{
	int i=0,j=0;
	do
	{
		do
		{
			t[i][j].up=0.5;
			t[i][j].right=0.5;
			t[i][j].left=0.5;
			t[i][j].down=0.5;
			j++;
		}
		while(j<3);
		j=0;
		i++;
	}
	while(i<4);
}

//Inicialización del tablero-----------------------------------------------------------------------------------
void inicio()
{
	int i=0,j=0;
	do
	{
		do
		{
			t[i][j].info=' ';
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
	t[3][1].up=1;
	t[3][1].down=1;
	t[3][1].left=1;
	t[3][1].right=1;
	t[3][2].info=' ';
	t[3][2].up=1;
	t[3][2].down=1;
	t[3][2].left=1;
	t[3][2].right=1;
}

//Impresión del tablero----------------------------------------------------------------------------------------
void imprimir()
{
	int i=0,n;
	if(intel==0)
	{
		n=12;
	}
	else
	{
		n=10;
	}
	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("     %0.3f            %0.3f            %0.3f    \n",t[i][0].up,t[i][1].up,t[i][2].up);
		printf("%0.3f ",t[i][0].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
		printf("%c",t[i][0].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f    %0.3f ",t[i][0].right,t[i][1].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
		printf("%c",t[i][1].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f    %0.3f ",t[i][1].right,t[i][2].left);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
		printf("%c",t[i][2].info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf(" %0.3f \n",t[i][2].right);
		printf("     %0.3f            %0.3f            %0.3f     \n",t[i][0].down,t[i][1].down,t[i][2].down);
		printf("\n");
		i++;
	}
	while(i<4);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n");
	printf("Agentes muertos: %d",muertos);
	printf("\n");
	printf("Agentes victoriosos: %d",victoria);
}

//Actualiza valores de la tabla--------------------------------------------------------------------------------
void actualizavalores()
{
	int i=1,j=0;
	float a,b;
	if(vivo==false)
	{
		a=menudesc;
	}
	if(ganador==true)
	{
		a=menudesc;
	}
	do
	{
		switch (c1[cont-i].dir)
		{
			case 1:
				{
					if(vivo==false)
					{
						b=min(min(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),min(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].up=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].up)+t[c1[cont-i].x][c1[cont-i].y].up);
						if(i==1)
						{
							t[c1[cont-i].x][c1[cont-i].y].up=1-t[c1[cont-i].x][c1[cont-i].y].up;
						}
					}
					if(ganador==true)
					{
						b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].up=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].up)+t[c1[cont-i].x][c1[cont-i].y].up);
					}
					break;
				}
			case 2:
				{
					if(vivo==false)
					{
						b=min(min(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),min(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].right=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].right)+t[c1[cont-i].x][c1[cont-i].y].right);
						if(i==1)
						{
							t[c1[cont-i].x][c1[cont-i].y].right=1-t[c1[cont-i].x][c1[cont-i].y].right;
						}
					}
					if(ganador==true)
					{
						b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].right=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].right)+t[c1[cont-i].x][c1[cont-i].y].right);
					}
					break;
				}
			case 3:
				{
					if(vivo==false)
					{
						b=min(min(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),min(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].down=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].down)+t[c1[cont-i].x][c1[cont-i].y].down);
						if(i==1)
						{
							t[c1[cont-i].x][c1[cont-i].y].down=1-t[c1[cont-i].x][c1[cont-i].y].down;
						}
					}
					if(ganador==true)
					{
						b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].down=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].down)+t[c1[cont-i].x][c1[cont-i].y].down);
					}
					break;
				}
			case 4:
				{
					if(vivo==false)
					{
						b=min(min(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),min(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].left=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].left)+t[c1[cont-i].x][c1[cont-i].y].left);
						if(i==1)
						{
							t[c1[cont-i].x][c1[cont-i].y].left=1-t[c1[cont-i].x][c1[cont-i].y].left;
						}
					}  
			  		if(ganador==true)
					{
						b=max(max(t[c1[cont-i+1].x][c1[cont-i+1].y].up,t[c1[cont-i+1].x][c1[cont-i+1].y].down),max(t[c1[cont-i+1].x][c1[cont-i+1].y].left,t[c1[cont-i+1].x][c1[cont-i+1].y].right));
						t[c1[cont-i].x][c1[cont-i].y].left=((menudesc)*(b-t[c1[cont-i].x][c1[cont-i].y].left)+t[c1[cont-i].x][c1[cont-i].y].left);
					}
					break;
				}
		}
		i++;
		j++;
	}
	while(j<cont);
}

//Función utilizada para actualizavalores----------------------------------------------------------------------
float max(float a, float b)
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

//Función utilizada para actualizavalores----------------------------------------------------------------------
float min(float a, float b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//Función utilizada para actualizavalores----------------------------------------------------------------------
float absol(float a)
{
	if(a<0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}

//Función que finalmente interpreta los valores para tomar una decisión----------------------------------------
int aleatorio()
{
	srand(time(NULL));
	
	int pup,pright,pdown,pleft,alea;
	float total,variable;
	total=t[y][x].up+t[y][x].right+t[y][x].down+t[y][x].left;
	pup=(t[y][x].up*10)/total;
	pright=(t[y][x].right*10)/total;
	pdown=(t[y][x].down*10)/total;
	pleft=(t[y][x].left*10)/total;
	variable=0+rand()%(11);
	
	if((t[y][x].up==0 && t[y][x].right==0) && (t[y][x].down==0 && t[y][x].left==0))
	{
		alea=1+rand()%(5-1);
		return alea;
	}
	
	if(0==variable)
	{
		alea=1+rand()%(5-1);
		return alea;
	}
	if(0<variable && variable<=pup)
	{
		alea=1;
		return alea;
	}
	if(pup<variable && variable<=(pup+pright))
	{
		alea=2;
		return alea;
	}
	if((pup+pright)<variable && variable<=(pup+pright+pdown))
	{
		alea=3;
		return alea;
	}
	if((pup+pright+pdown)<variable && variable<=(pup+pright+pdown+pleft))
	{
		alea=4;
		return alea;
	}
}
