#include <stdio.h>
//Punteros a funciones utilizando typedef, puntero a funciones y estructuras
using namespace std;


typedef int *entero;

entero funcionentero()
{
	int y; //Debe agregarse este para guardar el número
	int *x = new int;
	printf("Otorga el valor de x:\n");
	scanf("%d",&y);
	x=&y;
	return x;
}

main()
{
	int *w = funcionentero();
	printf("El valor del contenido de w es: %d\n",*w);
	printf("El valor de w es: %p\n",w);
}
