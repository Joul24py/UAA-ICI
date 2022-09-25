#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int V=0,a,b,suma;
int suma(a,b,suma);
int resta(a,b,c);
int mult(a,b,c);
int div(a,b,c);
int poten(a,b,c);
int fact(a,b,cont);

main()
{
	setlocale(LC_ALL, "");
	
	printf("\nEjercicio: Calculadora\n");
	printf("Por Joel Alejandro Espinoza Sánchez\n");
	printf("\n\nPresione \"Enter\" para continuar");
	getchar();
	
	system("CLS");
	printf("Seleccione la operación que desea realizar:\n");
	printf("1) Suma\n");
	printf("2) Resta\n");
	printf("3) Multiplicación\n");
	printf("4) División\n");
	printf("5) Potencia\n");
	printf("6) Factorial\n\n");
	printf("Otro Número) Salir del Programa\n\n");
	scanf("%d",&V);
	
	switch (V)
	{
		case 1:
			{
				int a,b,suma=0;
				printf("Otorga dos números\n");
				scanf("%d",&a);
				scanf("%d",&b);
				suma(a,b,suma);
				printf("La suma es: %d\n",%suma);
				
				break;
			}
		case 2:
			{
				int a,b,c=0;
				printf("Otorga dos números\n");
				break;
			}
		case 3:
			{
				int a,b,c=0;
				printf("Otorga dos números\n");
				break;
			}
		case 4:
			{
				int a,b,c=0;
				printf("Otorga dos números\n");
				break;
			}
		case 5:
			{
				int a,b,c=0;
				printf("Otorga un número\n");
				break;
			}
		case 6:
			{
				int a,b=0,cont=0;
				printf("Otorga un número\n");
				break;
			}
		default:
			{
				break;
			}
	}
}

int suma(a,b,suma)
{
	int a,b,suma=0;
	suma=a+b;
	return(suma);
}
