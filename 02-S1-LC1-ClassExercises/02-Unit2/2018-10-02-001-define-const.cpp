#include <stdio.h>
#define const float dolar=18.95;
const float euro=21.96;

main()
{
	printf("El valor del Euro es %1.2f pesos.\n", euro);
	printf("El valor del Dolar es %1.2f pesos.", dolar);
	getchar();
	//getchar hace que el equipo espere un "teclazo" para alguna opción y proseguir (No todos los compiladores necesitan esta acción)
}