#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que pida un número arábigo entre 1 y 10 (dato entero) y que muestre por pantalla el número correspondiente en romano

int x;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Escribe un número entre 1 y 10\n");
	scanf("%d",&x);
	switch (x)
	{
		case 1:
			printf("I");
			break;
		case 2:
			printf("II");
			break;
		case 3:
			printf("III");
			break;
		case 4:
			printf("IV");
			break;
		case 5:
			printf("V");
			break;
		case 6:
			printf("VI");
			break;
		case 7:
			printf("VII");
			break;
		case 8:
			printf("VIII");
			break;
		case 9:
			printf("IX");
			break;
		case 10:
			printf("X");
			break;
		default:
			printf("ERROR: No ingresaste un número válido");
	}
		
	getchar();
}
