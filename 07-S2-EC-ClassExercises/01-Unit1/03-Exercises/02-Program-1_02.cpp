//Programa 1_02: Ejemplo de arreglo unidimensional
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int arreglo[10],cont=0;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Ejemplo de Arreglo Unidimensional:\n");
	do
	{
		arreglo[cont]=cont+1;
		printf("[%d]  ",arreglo[cont]);
		cont=cont+1;
	}
	while(cont<10);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
