/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

Práctica 6: Captura de los datos de un archivo TSPLIB

		  Doctora Aurora Torres Soto

   Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 6 de noviembre del 2020

Descripción:
*/
//Cargamos las librerías
#include <stdio.h>
#include <locale.h>
#include <string.h>

main()
{
	setlocale(LC_ALL,"");
	
	//1. Declaramos las variables que usaremos
	/*
		car: Variable que lee caracter por caracter en una línea
		line: Vector que extrae una línea del archivo
		filetxt: Variable FILE de tipo apuntador a un archivo
		qv: Cantidad de vértices del grafo del archivo
		reachedgraph: Detecta la línea en la que la matriz comienza
	*/
	int h = 0,i,j,k = 0,qv, reachedgraph = 0;
	FILE *filetxt;
	char line[200],car;
	
	printf("============================== LECTURA DE ARCHIVOS ==============================\n");
	
	//2. Abrimos el archivo
	filetxt = fopen("bays29.tsp.txt","r");
	
	int graph[29][29];
	int n;
	
	//3. Procesamos el archivo
	if(filetxt == NULL)
	{
		printf("Problemas para abrir el archivo");
		return 1;
	}
	
	//4. Leemos el archivo hasta llegar al EOF (End Of File)
	while(feof(filetxt) == 0)
	{
		if(reachedgraph == 0)
		{
			fscanf(filetxt,"%s",line);
			
			if(strcmp(line, "EDGE_WEIGHT_SECTION")==0)
			{
				reachedgraph = 1;
			}
		}
		else
		{
			if(h != 29)
			{
				fscanf(filetxt,"%d",&n);
				graph[h][j] = n;
				j++;
				
				if(j == 29)
				{
					j = 0;
					h++;
				}
			}
			else
			{
				fscanf(filetxt,"%s",line);
			}
		}
	}
	
	for(i = 0; i < 29; i++)
	{
		for(j = 0; j < 29; j++)
		{
			printf("[%d] ",graph[i][j]);
		}
		printf("\n");
	}
	
	fclose(filetxt);
	getchar();
}
