#include <stdio.h>

main()
{
	int edad=0;
	char bandera;
	float sueldo;
	char nombre[20];
	
	printf("Escribe tu edad\n");
	scanf("%d", &edad);
	printf("Tu edad es de %d\n", edad);
	printf("\n");
	bandera='b';
	printf("Bandera vale %c\n", bandera);
	printf("\n");
	printf("Dame el sueldo\n");
	scanf("%f", &sueldo);
	printf("Tu sueldo es de %1.0f pesos\n", sueldo);
	printf("\n");
	printf("Escribe tu nombre:\n");
	scanf("%s", &nombre);
	printf("Tu nombre es %s\n", nombre);
}