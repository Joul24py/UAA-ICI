#include <stdio.h>

main()
{
	int NUM=0,cuad=0,cub=0;
	
	printf("Escribe un numero entero\n");
	scanf("%d",&NUM);
	cuad=NUM*NUM;
	cub=cuad*NUM;
	printf("\n");
	printf("El cuadrado de %d es %d\n",NUM,cuad);
	printf("El cubo de %d es %d\n ",NUM,cub);
	getchar();
}
