//Ejercicio 1_01: Implementar un Bubble Sort ascendentemente
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vector[10],a=0,cont=0;

main()
{
	setlocale(LC_ALL, "");
	
	vector[0]=20;
	vector[1]=10;
	vector[2]=30;
	vector[3]=50;
	vector[4]=40;
	vector[5]=80;
	vector[6]=10;
	vector[7]=90;
	vector[8]=70;
	vector[9]=100;
	
	printf("Vector Inicial\n");
	cont=0;
	do
	{
		printf("[%d]   ",vector[cont]);
		cont=cont+1;
	}
	while(cont<10);
	
	//Procedimiento para ordenar
	cont=0;
	do
	{
		if(vector[cont]>vector[cont+1])
		{
			a=vector[cont+1];
			vector[cont+1]=vector[cont];
			vector[cont]=a;
			cont=0;
		}
		else
		{
			cont=cont+1;
		}
	}
	while(cont<10);
	
	
	printf("\nVector Final\n");
	cont=0;
	do
	{
		printf("[%d]   ",vector[cont]);
		cont=cont+1;
	}
	while(cont<10);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
