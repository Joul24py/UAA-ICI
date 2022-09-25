#include <stdio.h>

main()
{
	float b=0,p=0,h=0,a=0;
	
	printf("Dame la base de un rectangulo\n");
	scanf("%f",&b);
	printf("Dame la altura del mismo\n");
	scanf("%f",&h);
	p=b+b+h+h;
	a=b*h;
	printf("\n");
	printf("El perimetro del rectangulo es %1.2f cm\n",p);
	printf("El area del rectnagulo es %1.2f cm\n ",a);
	getchar();
}
