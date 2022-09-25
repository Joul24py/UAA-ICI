#include <stdio.h>
//Ejemplos de Tipos Definidos (typedef)

typedef int entero; //typedef define que ahora llamaremos "entero" a las variables "int" y poderlas definir como "entero"
typedef double punto_decimal;
typedef float flotantexd;

main()
{
	entero x=4;
	punto_decimal pi=3.1416;
	flotantexd e=2.8127;
	
	printf("Entero x: %d",x);
	printf("\nPunto Decimal pi: %f",pi);
	printf("\nFlotante e: %f",e);
}
