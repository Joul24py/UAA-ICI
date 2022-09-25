//Ejercicio 1_03: Generar una matriz con una determinada salida implementando una matriz llamada twoD[3][3]
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int twoD[4][4],cont=0,cont1=0,cont2=0,res=0;

main()
{
	setlocale(LC_ALL, "");
	
	do
	{
		do
		{
			res=cont1*cont2;
			twoD[cont1][cont2]=res;
			printf("%d.0  ",twoD[cont1][cont2]);
			cont1=cont1+1;
		}
		while(cont1<4);
		printf("\n");
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<4);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
