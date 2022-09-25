#include <stdio.h>

main()
{
	int opcion;
	printf("1   Altas\n");
	printf("2   Bajas\n");
	printf("3   Modifica\n");
	printf("4   Salir\n");
	printf("Elegir Opcion\n");
	scanf("%d",&opcion);
	
	switch(opcion)
	{
		case 1:
			printf("Opcion 1");
			break;
		case 2:
			printf("Opcion 2");
			break;
		case 3:
			printf("Opcion 3");
			break;
		case 4:
			printf("Opcion Salir");
			break;
		default:
			printf("Opcion Incorrecta");
	}
	getchar();
}
