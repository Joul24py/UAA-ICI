#include <stdio.h>

int numest=0;
struct estructura
{
	int numero;
	int *ap;
};

//typedef struct estructura punteroest;
struct estructura primerest();


// funcion crear estructuras
// funcion crear primer estructura
// funcion crear estructura final
// funcion imprimir estructuras

main()
{
	printf("Otorgue la cantidad de estructuras que desea:\n");
	scanf("%d",&numest);
	struct estructura primero;
	primero=primerest();
	printf("\nNumero: %d",primero.numero);
	printf("\nApuntador: %d",primero.ap);
	
}

struct estructura primerest()
{
	struct estructura a;
	printf("Defina el valor para el numero:\n");
	scanf("%d",&a.numero);
	a.ap=0;
	return a;
	
}
