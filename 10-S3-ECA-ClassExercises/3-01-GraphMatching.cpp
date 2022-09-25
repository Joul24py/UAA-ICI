/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Pareo de Grafos

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 27 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <locale.h>
using namespace std;

//Definiciones-------------------------------------------------------------------------------------------------
#define M 6 //M = Conjunto 1
#define N 6 //N = Conjunto 2

//Variables globales-------------------------------------------------------------------------------------------
int alt;

//Funciones----------------------------------------------------------------------------------------------------
int maxBPM(int bpGraph[M][N]);
bool bpm(int bpGraph[M][N], int u, bool seen[], int matchR[]);

//La función main----------------------------------------------------------------------------------------------
main()
{
	setlocale(LC_ALL,"");
	
	//Definición de la matriz que representa al grafo----------------------------------------------------------
	//Definición por consola
	/*int bpGraph[M][N];
	
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			printf("Escribe el peso con el que se relaciona el elemento\n");
			printf("%d del conjunto 1 y el elemento %d del conjunto 2: \n",i+1,j+1);
			scanf("%d",&bpGraph[i][j]);
			printf("\n");
		}
		printf("=============================================================\n\n");
	}
	printf("_____________________________________________________________\n\n");*/
	
	//Definición de código
	int bpGraph[M][N] =
	{
		{1, 0, 0, 1, 1, 0},
		{0, 1, 0, 1, 0, 1},
		{0, 0, 1, 0, 1, 0},
		{1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 1}
		
	};
	
	printf("Nodos que se pueden parear:\n\n");
	printf("\n%d",maxBPM(bpGraph));
	
	getchar();
}

//Busca el máximo del pareo------------------------------------------------------------------------------------
int maxBPM(int bpGraph[M][N])
{
	//Se declara un arreglo que guarda el pareo
	//matchR[i] es el número del conjunto 1 asignado al elemento i del conjunto 2 (-1 = No asignado)
	int matchR[N];
	
	//Inicialmente todos los nodos están disponibles
	memset(matchR, -1, sizeof(matchR));
	
	//Recuento de elementos del conjunto 2 asignados a los del conjunto 1
	int result = 0;
	for (int u = 0; u < M; u++)
	{
		//Marca todo elemento del conjunto 2 como no asignado para el siguiente elemento del conjunto 1
		bool seen[N];
		memset(seen, 0, sizeof(seen));
		
		//Encuentra si el elemento 'u' puede ser pareado
		if (bpm(bpGraph, u, seen, matchR))
		{
			result=result+alt;
			printf("%d con %d\n",u+1,alt+1);
		}
	}
	return 0;
}

//Búsqueda en profundidad que regresa true si u puede ser pareado----------------------------------------------
bool bpm(int bpGraph[M][N], int u, bool seen[], int matchR[])
{
	//Intenta con cada elemento del conjunto 2 uno por uno
	for (int v = 0; v < N; v++)
	{
		//Con base en la existencia de u y si v no ha sido pareado
		if (bpGraph[u][v] && !seen[v])
		{
			//Se señala a v como visitado
			seen[v] = true;
			
			//Si v no ha sido asignado a otro elemento del conjunto 1 o u tiene un v alternativo
			//Como v se marca como visitado previamente, en la próxima llamada recursiva ignorará a este v
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) 
			{ 
				matchR[v] = u;
				alt=bpGraph[u][v];
				alt=v;
				return true; 
			} 
		} 
	} 
	return false; 
}
