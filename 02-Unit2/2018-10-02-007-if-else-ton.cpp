#include <stdio.h>

main()
{
	int peso;
	
	printf("Introducir peso\n");
	scanf("%d",&peso);
	
	if (peso<500)
	{
		printf("No es ni media tonelada\n");
	}
	else
	{
		if (peso>500)
		{
			printf("Es más de media tonelada\n");
		}
		else
		{
			printf("Es justo media tonelada\n");
		}
	}
}
