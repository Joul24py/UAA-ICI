#include <stdio.h>
#include <math.h> //Esta libreria funciona para incluir funciones matemáticas como pow(num,potencia) que es potencia

main()
{
	float a=0,b=0,sum=0,res=0,prod=0;
	
	printf("Dame dos numeros reales\n");
	scanf("%f",&a);
	scanf("%f",&b);
	sum=a+b;
	res=a-b;
	prod=a*b;
	printf("\n");
	printf("La suma es %1.2f\n ",sum);
	printf("La diferencia es %1.2f\n ",res);
	printf("El producto es %1.2f\n ",prod);
	getchar();
}
