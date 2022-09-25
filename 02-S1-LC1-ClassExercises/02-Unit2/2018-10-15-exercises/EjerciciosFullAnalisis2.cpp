#include <stdio.h>
#include <math.h> //Esta libreria funciona para incluir funciones matem�ticas como pow(num,potencia) que es potencia

main()
{
	int A=0,B=0,sum=0;
	float res=0,cuad=0;
	
	printf("Otorga 2 numeros enteros\n");
	scanf("%d",&A);
	scanf("%d",&B);
	sum=A+B;
	cuad=pow(sum,2);
	res=cuad/3;
	printf("\n");
	printf("El resultado es: %1.3f",res);
	getchar();
}
