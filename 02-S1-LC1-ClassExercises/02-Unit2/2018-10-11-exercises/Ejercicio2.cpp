#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que calcule el área de un círculo usando una constante pi definida con const

const float p=3.1416;
float r=0,a=0;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Otorga el valor del radio de un círculo\n");
	scanf("%f",&r);
	a=p*(r*r);
	printf("\nEl área del círculo es %1.3f cm2\n",a);
	
	getchar();
}
