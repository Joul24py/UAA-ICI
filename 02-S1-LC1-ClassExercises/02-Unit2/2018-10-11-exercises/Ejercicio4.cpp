#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Una tienda vende libros a $100.00, cuadernos a $15.50 y plumas a $2.35. Calcule el monto a pagar por artículo y en total

float l,c,p,L=100,C=15.5,P=2.35,tl,tc,tp,tf;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Otorga la cantidad de libros a comprar\n");
	scanf("%f",&l);
	printf("Otorga la cantidad de cuadernos a comprar\n");
	scanf("%f",&c);
	printf("Otorga la cantidad de plumas a comprar\n");
	scanf("%f",&p);
	tl=l*L;
	tc=c*C;
	tp=p*P;
	tf=tl+tc+tp;
	printf("\nLa cantidad a pagar de libros es %1.0f\n",tl);
	printf("La cantidad a pagar de cuadernos es %1.2f\n",tc);
	printf("La cantidad a pagar de plumas es %1.3f\n",tp);
	printf("El total a pagar es %1.3f\n",tf);
		
	getchar();
}
