//Ejercicio 2_01: Implemente First y Second (usando estructuras, funciones y apuntadores)
#include <stdio.h>
#include <locale.h>

int x;

struct nodo
{
	int num;
	struct nodo *ap;
};

typedef struct nodo *TipoLista;

TipoLista first=NULL;
TipoLista second;

void CreaFirst();
void CreaSecond();
void UneNodos();

main()
{
	setlocale(LC_ALL,"");
	
	printf("Otorgue un valor entero:\n");
	scanf("%d",&x);
	CreaFirst();
	printf("Otorgue otro valor entero:\n");
	scanf("%d",&x);
	CreaSecond();
	UneNodos();
	
	printf("\n");
	printf("Dirección de first: %p\n",first);
	printf("Número de first: %d\n",first->num);
	printf("Apuntador de first: %p\n",first->ap);
	printf("Dirección de second: %p\n",second);
	printf("Número de second: %d\n",second->num);
	printf("Apuntador de second: %p\n",second->ap);
	
	getchar();
}

void CreaFirst()
{
	first=new(struct nodo);
	first->num=x;
	first->ap=NULL;
}

void CreaSecond()
{
	second=new(struct nodo);
	second->num=x;
	second->ap=NULL;
}

void UneNodos()
{
	first->ap=second;
}
