#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que pida el número (dato entero) de un mes del año y que muestre por pantalla el nombre correspondiente de dicho mes

int x;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Escribe un número entre 1 y 12\n");
	scanf("%d",&x);	
	switch (x)
	{
		case 1:
			printf("Enero");
			break;
		case 2:
			printf("Febrero");
			break;
		case 3:
			printf("Marzo");
			break;
		case 4:
			printf("Abril");
			break;
		case 5:
			printf("Mayo");
			break;
		case 6:
			printf("Junio");
			break;
		case 7:
			printf("Julio");
			break;
		case 8:
			printf("Agosto");
			break;
		case 9:
			printf("Septiembre");
			break;
		case 10:
			printf("Octubre");
			break;
		case 11:
			printf("Noviembre");
			break;
		case 12:
			printf("Diciembre");
			break;
		default:
			printf("ERROR: No ingresaste un número válido");
	}
		
	getchar();
}
