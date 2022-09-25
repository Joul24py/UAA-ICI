#include <stdio.h>

main()
{
	float p=0,u=0,c=0;
	
	printf("Dame el precio de un articulo\n");
	scanf("%f",&p);
	printf("Dame la cantidad de dinero que el usuario ha dado\n");
	scanf("%f",&u);
	c=p-u;
	printf("\n");
	printf("El cambio a dar es de %1.2f pesos\n",c);
	getchar();
}
