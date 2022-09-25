#include <stdio.h>

struct estructura
{
	int info;
	struct estructura *next;
};

typedef struct estructura *defestructura; //typedef sirve para nombrar nuevos nombres
/*
Por ejemplo si ponemos "typedef int tipoentero" y después declaramos "tipoentero soyUnEntero" entonces soyUnEntero será int
*/

estructura *uno, *dos;

defestructura funcionnodo()
{
	defestructura p;
	p = new estructura;
	printf("Pon el valor de p >:v\n");
	scanf("%d",p->info);
	p->next=NULL;
	return p;
}

int main()
{
	uno=funcionnodo();
	printf("\n\nEl valor del info de uno es: %d",uno->info);
	printf("\nEl contenido del apuntador de uno es: %d",uno->next);
	printf("\nLa dirección de uno es: %d",uno);
	getchar();
}
