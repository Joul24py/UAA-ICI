#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que convierta de pulgadas a centímetros

float in,conv=2.54,cm;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Otorga una medida en pulgadas\n");
	scanf("%f",&in);
	cm=conv*in;
	printf("Esa cantidad es equivalente a %1.3f cm\n",cm);
		
	getchar();
}
