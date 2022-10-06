/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   Práctica 3: Coloración de un Grafo

		  Doctora Aurora Torres Soto

   Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 5 de octubre del 2020

Descripción:
*/
//Cargamos las librerías
#include <stdio.h>
#include <locale.h>
#include <math.h>

main()
{
	setlocale(LC_ALL,"");
	
	//Declaramos las variables que usaremos
	/*
		f: Auxiliador detector de opciones cuando se pregunta al usuario
		i: Iterador principal
		j: Iterador secundario
		orden: Es la cantidad de vértices que tendrá el grafo
		u: Múltiples usos (Detecta la condición para repetir el proceso, auxiliar para ordenar los vértices)
	*/
	int f, i, j, orden, u = 0;
	
	printf("=========================== COLORACIÓN DE UN GRAFO ===========================\n");
	printf("\n");
	
	do
	{
		//Pedimos que inserten el grafo
		printf("--------------------------------\n");
		printf("Otorgue la cantidad de vértices del grafo: ");
		scanf("%d",&orden);
		
		//Sabiendo la cantidad de vértices del grafo, hacemos la matriz de adyacencia vac�a y un arreglo de vértices
		int matady[orden][orden + 1], vertices[orden], colores[orden], coloresaux[orden];
		
		//Procedemos a llenar la matriz de adyacencia
		for(i = 0; i < orden; i++)
		{
			j = i;
			do
			{
				printf("--------------------------------\n");
				printf("¿El vértice %d está conectado con el vértice %d?\n",i+1,j+1);
				printf("1. Sí\n");
				printf("2. No\n");
				scanf("%d",&f);
				if(f == 1)
				{
					matady[i][j] = 1;
					matady[j][i] = 1;
				}
				if(f == 2)
				{
					matady[i][j] = 0;
					matady[j][i] = 0;
				}
				j++;
			}
			while(j < orden);
			matady[i][orden] = 0;
			vertices[i] = i + 1;
		}
		
		//La matriz tiene un renglón de más hecho para guardar el total de conexiones. Esto se calculara a continuación
		for(i = 0; i < orden; i++)
		{
			for(j = 0; j < orden; j++)
			{
				if(matady[i][j] == 1)
				{
					matady[i][orden] = matady[i][orden] + 1;
				}
			}
		}
		
		//Mostramos la matriz de adyacencia
		printf("--------------------------------\n\n");
		printf("Matriz de adyacencia:\n");
		for(i = 0; i < orden; i++)
		{
			for(j = 0; j <= orden; j++)
			{
				printf("[%d] ",matady[i][j]);
			}
			printf("\n");
		}
		
		//Ordenaremos los vértices de mayor número de conexiones a menor
		for(i = 0; i + 1 < orden; i++)
		{
			if(matady[i][orden] < matady[i + 1][orden])
			{
				u = matady[i + 1][orden];
				matady[i + 1][orden] = matady[i][orden];
				matady[i][orden] = u;
				
				u = vertices[i + 1];
				vertices[i + 1] = vertices[i];
				vertices[i] = u;
				
				i = 0;
			}
		}
		
		printf("--------------------------------\n");
		printf("El orden de los vértices según el algoritmo de Welsh Powell es el siguiente:\n");
		printf("V = [%d", vertices[0]);
		for(i = 1; i < orden; i++)
		{
			printf(", %d", vertices[i]);
		}
		printf("]\n");
		
		//Comienza el coloreo de grafos
		colores[0] = 1; //El primer vértice es fácil pues no se ha revisado ninguno anteriormente
		
		//Se revisará de uno en uno los próximos vértices en orden como se guardaron por el arreglo vertices
		for(i = 1; i < orden; i++)
		{
//			printf("DEBUGGING: Estoy revisando al vértice %d (%d)\n", vertices[i], i + 1);
			u = 0;
			
			//En cada revisión tenemos que checar todos los vértices previos a éste
			for(j = 0; j < i; j++)
			{
//				printf("          DEBUGGING: con el vértice %d (%d)\n", vertices[j], j + 1);
				
				//Si el vértice j tiene conexión con el vértice i, entonces guardaremos en coloresaux ese color como color imposible
//				printf("          if: vertices[i] - 1 = %d      vertices[j] - 1 = %d      por tanto matady[vertices[i] - 1][vertices[j] - 1] = %d\n", vertices[i] - 1, vertices[j] - 1, matady[vertices[i] - 1][vertices[j] - 1]);
				if(matady[vertices[i] - 1][vertices[j] - 1] == 1)
				{
//					printf("                     DEBUGGING: y Sí tienen conexión, aSí que no podemos asignar el color %d\n", colores[j]);
					coloresaux[u] = colores[j];
					u++;
				}
			}
			
			colores[i] = 1;
			for(j = 0; j < i; j++)
			{
				if(coloresaux[j] == colores[i])
				{
					colores[i] = colores[i] + 1;
					j = 0;
				}
			}
			
//			DEBUGGING: Vamos a ver cómo se guardó coloresaux
/*			printf("                     DEBUGGING: coloresaux = ");
			for(j = 0; j < i; j++)
			{
				printf("%d ",coloresaux[j]);
			}
			printf("\n");
*/		}
		
		printf("--------------------------------\n");
		printf("El color de los vértices según el algoritmo de Welsh Powell es el siguiente:\n");
		printf("C = [%d", colores[0]);
		for(i = 1; i < orden; i++)
		{
			printf(", %d", colores[i]);
		}
		printf("]\n\n");
		printf("--------------------------------\n\n");
		
		//Opción para repetir el procedimiento
		printf("¿Desea repetir el procedimiento?\n");
		printf("1. Sí\n");
		printf("2. No\n");
		scanf("%d",&u);
	}
	while(u == 1);
	
	getchar();
}

//5 2 1 1 2 1 2 2 2 1 2 2 2 2 1 2
//7 2 1 1 2 2 1 1 2 1 2 1 2 2 2 1 2 2 2 2 1 1 2 2 1 2 2 1 2
