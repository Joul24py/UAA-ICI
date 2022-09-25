//Ejercicio 2_03: Implemente DoubleFirst y DoubleSecond (usando estructuras, funciones y apuntadores)
#include <stdio.h>
#include <locale.h>

int x;

struct nodo
{
	struct nodo *ant;
	int num;
	struct nodo *sig;
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
	printf("Apuntador anterior de first: %p\n",first->ant);
	printf("Número de first: %d\n",first->num);
	printf("Apuntador siguiente de first: %p\n",first->sig);
	printf("Dirección de second: %p\n",second);
	printf("Apuntador anterior de second: %p\n",second->ant);
	printf("Número de second: %d\n",second->num);
	printf("Apuntador siguiente de second: %p\n",second->sig);
	
	getchar();
}

void CreaFirst()
{
	first=new(struct nodo);
	first->ant=NULL;
	first->num=x;
	first->sig=NULL;
}

void CreaSecond()
{
	second=new(struct nodo);
	second->ant=NULL;
	second->num=x;
	second->sig=NULL;
}

void UneNodos()
{
	first->sig=second;
	second->ant=first;
}
