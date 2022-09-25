//Ejercicio 1_06: Hacer dos estructuras: Primero y segundo, que tengan enteros y apuntadores. El apuntador de segundo será nulo y el de primero apuntará a segundo
#include <stdio.h>

struct estructura
{
	int numero;
	int *apuntador;
} primero, segundo;

main()
{
	printf("Inserta un valor para primero:\n");
	scanf("%d",&primero.numero);
	printf("\nInserta un valor para segundo:\n");
	scanf("%d",&segundo.numero);
	primero.apuntador=&segundo.numero; //Para C normal no existe "->" y en toda estructura debe usarse el punto
	segundo.apuntador=NULL;
	printf("\nValor Entero de Primero: %d\n",primero.numero);
	printf("\nValor Entero de Segundo: %d\n",segundo.numero);
	printf("\nApuntador de Primero: %p\n",primero.apuntador);
	printf("\nApuntador de Segundo: %p\n",segundo.apuntador);
	
	getchar();
}
