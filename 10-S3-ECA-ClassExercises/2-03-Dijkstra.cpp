/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Dijkstra

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 22 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

//Variables globales-------------------------------------------------------------------------------------------
struct label
{
   int nro;	// Número del nodo
   int prev; //Nodo anterior (-1 para el nodo inicial)
   int peso; //Coste total de la trayectoria total
   int marca; //Si el nodo ha sido marcado o no
};
typedef struct label label_t;
 
void dijkstra(int, int **, int, int);

//La función main----------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,""); 
	
	int numNodos;
	printf("Cantidad total de nodos: ");
	scanf("%d",&numNodos);
	
	//Definiendo la matriz de adyacencia-----------------------------------------------------------------------
	//Definición por consola
	int i, j, **A;
 
   	if((A = new int*[numNodos]) == NULL)
   	{
   		return 1;
   	}
   	for(i=0; i<numNodos; i++)
   	{
   		if((A[i] = new int[numNodos]) == NULL)
   		{
   			return 1;
		}
	}
	
	int pos=1;
	for(i=0; i<numNodos; i++)
	{
		for(j=pos; j<numNodos; j++)
		{
			printf("Valor de la matriz en [%d][%d]: ",i+1,j+1);
			scanf("%d",&A[i][j]);
			A[j][i]=A[i][j];
		}
		pos++;
		A[i][i]=0;
	}
	
	//Definici�n establecida en el c�digo
   	/* por simplicidad, completamos solo los pares de nodos conectados
	A[0][1] = 2;
	A[0][2] = 6;
	A[0][3] = 10;
	A[0][4] = 9;
	A[0][5] = 5;
	A[0][6] = 8;
	
	A[1][0] = 2;
	A[1][2] = 5;
	A[1][3] = 9;
	A[1][4] = 8;
	A[1][5] = 4;
	A[1][6] = 0;
	
	A[2][0] = 6;
	A[2][1] = 5;
	A[2][3] = 4;
	A[2][4] = 5;
	A[2][5] = 3;
	A[2][6] = 6;
	
	A[3][0] = 10;
	A[3][1] = 9;
	A[3][2] = 4;
	A[3][4] = 3;
	A[3][5] = 2;
	A[3][6] = 4;
	
	A[4][0] = 9;
	A[4][1] = 8;
	A[4][2] = 5;
	A[4][3] = 3;
	A[4][5] = 5;
	A[4][6] = 0;
	
	A[5][0] = 5;
	A[5][1] = 4;
	A[5][2] = 3;
	A[5][3] = 2;
	A[5][4] = 5;
	A[5][6] = 5;
	
	A[6][0] = 8;
	A[6][1] = 0;
	A[6][2] = 6;
	A[6][3] = 4;
	A[6][4] = 0;
	A[6][5] = 5;*/
 
   //Imprimir la matriz de adyacencia
	printf("Matriz de Adyacencia\n\n");
	for(i=0; i<numNodos; i++)
	{
    	for ( j = 0; j < numNodos; j++ )
    	{
    		cout << setw(2) << A[i][j] << "  ";
		}
      	printf("\n");
   	}
	printf("\n");
 
	//Calcular Dijkstra a partir del nodo 0, a partir del nodo 2 */
	int partida,final;
	printf("Nodo de partida: ");
	scanf("%d",&partida);
	printf("Nodo final: ");
	scanf("%d",&final);
	dijkstra(numNodos, A, partida-1, final-1);
 
	//liberar memoria
	delete [] A;
	for(i=0; i<numNodos; i++)
	{
		delete A[i];
	}
 
	return 0;
}
 
//El algoritmo de Dijkstra-------------------------------------------------------------------------------------
void dijkstra(int N, int **A, int a, int b)
{
	label_t *Labels;
	int i, i0, j, peso;
	int *ruta; //Arreglo de nodos de la ruta minima
	//Crea dinámicamente el arreglo de etiquetas de nodo-------------------------------------------------------
	if((Labels = new label_t[N]) == NULL)
	{
		return;
	}
	
	//Nodo inicial 'a' entre 0 y N - 1
	if(a<0 || a>N-1)
	{
		return;
	}
	//Nodo final 'a' entre 0 y N - 1
	if ( b < 0 || b > N - 1 )
	{
		return;
	}
	//Inicializar las etiquetas de nodo------------------------------------------------------------------------
	for ( i = 0; i < N; i++ )
	{
		Labels[i].nro = i;
      	if (i!=a)
		{
         	Labels[i].prev = -1; //Aún no se ha definido predecesor
         	Labels[i].peso = -1; //Inifnito
         	Labels[i].marca = 0;
      	}	
      	else
		{
        	Labels[i].prev = -1; //Aún no se ha definido predecesor
         	Labels[i].peso = 0; //Coste del nodo inicial a s'i mismo es cero
         	Labels[i].marca = 0;
      	}
   	}
 
   	//Continuamos este ciclo mientras existan nodos no marcados
   	while (1)
	{
    	//Busca entre todos los nodos no marcados el de menor peso, descartando los de peso infinito (-1)
      	peso = -1;
      	i0 = -1;
      	for(i=0; i<N; i++)
		{
        	if(Labels[i].marca==0 && Labels[i].peso>=0)
        	{
        		if(peso==-1)
				{
	               	peso = Labels[i].peso;
	               	i0 = i;
	            }
	            else
	            {
	            	if(Labels[i].peso <= peso)
					{
	               		peso = Labels[i].peso;
	               		i0 = i;
	           		}
				}
	        }
		}
    
		if(i0==-1) 	//Termina si no encuentra
		{
	        printf("Ya no quedan nodos por analizar\n");
	        break;
	    }
	      
		printf("     Analizando Nodo %d...     \n\n",i0);
	 
	    //Actualiza el peso de los sucesores-------------------------------------------------------------------
	    for(i=0; i<N; i++)
		{
	        if(A[i0][i]>0)
			{
	            //Actualiza
	            if(Labels[i].peso==-1 || Labels[i0].peso + A[i0][i] < Labels[i].peso)
				{
	               	if(Labels[i0].peso + A[i0][i] < Labels[i].peso)
	               	{
	            		printf("	[Mejorando coste de nodo %d]\n",i);
				   	}
	               	Labels[i].peso = Labels[i0].peso + A[i0][i];
	               	Labels[i].prev = i0;
	               	printf("   Coste del nodo %d desde el nodo %d: %d\n",i,i0,Labels[i].peso);
	            }
	        }
	    }
	    Labels[i0].marca = 1;
	    printf("   [Nodo %d marcado]",i0);
	 
	    //Imprime los costes calculados hasta el momento-------------------------------------------------------
	    for(i=0; i<N; i++) 
		{
	        printf("%d:[",i);
	        if(Labels[i].peso==-1)
	        {
	        	printf("Inf");
			}
	        else
	        {
	        	
				printf("%d",Labels[i].peso);
			}
	        printf(", %d",Labels[i].prev);
	        if(Labels[i].marca==1)
	        {
	        	printf(", x]\n");
			}
	        else
	        {
	        	printf("]\n");
			}
	    }
	    printf("\n");
	 
	    //Pausa (opcional)
	    printf("Presione ENTER para continuar");
	    printf("\n\n");
	    cin.get();
	}
 
   	//Ruta desde el nodo 'a' hasta el nodo 'b'-----------------------------------------------------------------
   	int longitud = 2;
   	i = b;
   	while((i=Labels[i].prev)!=a)
   	{
   		longitud++;	//Primero estimamos la longitud de la ruta
	}
   	if((ruta=new int[longitud]) == NULL)
   	{
   		return;
	}
 
   	ruta[longitud - 1] = b;		//Rellenamos
   	i = b;
   	j = 0;
   	for(j=1; j<longitud; j++)
	{
      	i = Labels[i].prev;
      	ruta[longitud-j-1] = i;
   	}
   	
   	printf("================================================================\n\n");
   	printf("Ruta más económica entre nodo %d y nodo %d:\n\n",a,b);
   	
   	for(i=0; i<longitud; i++)
   	{
   		printf("%d",ruta[i]);
   		if(i<longitud-1)
   		{
   			printf(" - ");
		}
	}
	printf("\n\n");
	printf("Costo total: %d\n\n",Labels[b].peso);
	
	delete ruta;
	delete [] Labels;
}
