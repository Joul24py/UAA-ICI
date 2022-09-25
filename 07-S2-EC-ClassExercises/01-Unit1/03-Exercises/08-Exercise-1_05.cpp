//Ejercicio 1_05: Implemente un programa en  Java/C/C++, para sumar dos matrices de números enteros, y escribiremos una nueva tabla con la suma
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n=0,cont1=0,cont2=0;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Seleccione el tamaño de la matriz. Esta será cuadrada y respetará el tamaño para esta, su suma y el resultado:\n");
	scanf("%d",&n);
	int mat1[n][n],mat2[n][n],matres[n][n];
	
	do
	{
		do
		{
			printf("Inserta un número para la posición (%d, %d)",cont1,cont2);
			scanf("%d",&mat1[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<n);
		cont1=0;
		cont2=cont2+1;
		
	}
	while(cont2<n);
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			printf("Inserta un número para la posición (%d, %d)",cont1,cont2);
			scanf("%d",&mat2[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<n);
		cont1=0;
		cont2=cont2+1;
		
	}
	while(cont2<n);
	
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			matres[cont1][cont2]=mat1[cont1][cont2]+mat2[cont1][cont2];
			 cont1=cont1+1;
		}
		while(cont1<n);
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<n);
	
	printf("\n\n Su matriz 1 es:\n");
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			printf("[%d]   ",mat1[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<n);
		printf("\n");
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<n);
	
	printf("\n\n Su matriz 2 es:\n");
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			printf("[%d]   ",mat2[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<n);
		printf("\n");
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<n);
	
	printf("\n\n Su matriz resultante es:\n");
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			printf("[%d]   ",matres[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<n);
		printf("\n");
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<n);
	
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
