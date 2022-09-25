#include <stdio.h>

main()
{
	char opcion;
	
	printf("Seleccione una materia\n");
	printf("\n");
	printf("A: Español\n");
	printf("B: Matemáticas\n");
	printf("C: Historia\n");
	printf("D: Biología\n");
	scanf("%c",&opcion);
	printf("\n");
	printf("Has escogido ");
	if(opcion=='A' || opcion=='a')
	{
		printf("español");
	}
	else
	{
		if(opcion=='B' || opcion=='b')
	{
		printf("matemáticas");
	}
	else
	{
		if(opcion=='C' || opcion=='c')
	{
		printf("historia");
	}
	else
	{
		if(opcion=='D' || opcion=='d')
	{
		printf("biología");
	}
	else
	{
		printf("una materia inexistente");
	}
	}
	}
	}
}

