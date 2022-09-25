//Ejercicio 1_02: Generar una matriz con una determinada salida implementando una matriz llamada twoD[3][3]
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int twoD[3][3],cont=0,cont1=0,cont2=0,a=0,b=0,c=0;

main()
{
	setlocale(LC_ALL, "");
	
	do
	{
		do
		{
			twoD[cont1][cont2]=cont;
			cont1=cont1+1;
			cont=cont+1;
		}
		while(cont1<3);
		cont1=0;
		cont2=cont2+1;
	}
	while(cont2<3);
	
	cont=0;
	cont1=0;
	cont2=0;
	do
	{
		do
		{
			printf("%d ",twoD[cont1][cont2]);
			cont1=cont1+1;
			c=c+1;
			a=a+1;
			if(cont1==3)
			{
				cont1=0;
				cont2=cont2+1;
			}
		}
		while(c<=b);
		printf("\n");
		
		b=b+1;
		c=0;
	}
	while(a<9);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
