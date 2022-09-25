//Ejercicio 1_04: Generar una matriz con una determinada salida
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int twoD[5][4],cont=0,cont1=0,cont2=0,res=0;

main()
{
	setlocale(LC_ALL, "");
	
	do
	{
		do
		{
			twoD[cont1][cont2]=res;
			printf("%d ",twoD[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<5);
		printf("\n");
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<4);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
