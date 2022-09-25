#include <stdio.h>

main()
{
	int numero;
	do
	{
		printf("Escribe un número:\n");
		scanf("%d",&numero);
	}
	while(numero<10);
	printf("Termina el programa");
	getchar();
}
