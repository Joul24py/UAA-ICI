#include <stdio.h>
#include <math.h> //Esta libreria funciona para incluir funciones matem�ticas como pow(num,potencia) que es potencia

main()
{
	char nombre[10],apellido[10];
	float a=0,b=0,c=0,d=0,e=0,prom=0;
	
	printf("Nombre: ");
	scanf("%s",&nombre);
	printf("\n");
	printf("Apellido: ");
	scanf("%s",&apellido);
	printf("\n");
	printf("%s ",nombre);
	printf("%s, ",apellido);
	printf("escribe 5 calificaciones:\n");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	scanf("%f",&d);
	scanf("%f",&e);
	prom=(a+b+c+d+e)/5;
	printf("\n");
	printf("%s ",nombre);
	printf("%s, ",apellido);
	printf("tu promedio es: %1.3f",prom);
	getchar();
}
