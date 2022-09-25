//Programa 1_03: Calcular el promedio de un conjunto de valores
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int cant=0,cont=1;
float prom=0;

main()
{
	setlocale(LC_ALL, "");
	
	printf("¿Cuántos valores ingresará?\n");
	scanf("%d",&cant);
	float valores[cant];
	do
	{
		printf("Otorgue la cantidad %d\n",cont);
		scanf("%f",&valores[cont-1]);
		prom=prom+valores[cont-1];
		cont=cont+1;
	}
	while(cont<=cant);
	prom=prom/cant;
	printf("El promedio es %.2f",prom);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
