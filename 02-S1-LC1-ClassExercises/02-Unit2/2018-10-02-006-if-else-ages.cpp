#include <stdio.h>

int edad=0;

main()
{
	printf("Introduce tu edad\n");
	scanf("%d",&edad);
	printf("\n");
	
	if (edad<=10)
	{
		printf("Es un niño");
	}
	else
	{
		if (edad>65)
		{
			printf("Es jubilado");
		}
		else
		{
			printf("Es adulto");
		}
	}
	getchar();
}
