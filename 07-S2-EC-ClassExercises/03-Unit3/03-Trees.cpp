#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x;

struct nodo
{
	int num;
	struct nodo *der;
	struct nodo *izq;
};

typedef struct nodo *TipoLista;

TipoLista p=NULL;
TipoLista q;
TipoLista r;

void CrearArbol();
void PreOrden(TipoLista arbol);
void InOrden(TipoLista arbol);
void PostOrden(TipoLista arbol);

main()
{
	setlocale(LC_ALL,"");
	CrearArbol();
	
	do
	{
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n\n");
		printf("1.- Mostrar el árbol en preorden\n");
		printf("2.- Mostrar el árbol en inorden\n");
		printf("3.- Mostrar el árbol en postorden\n");
		printf("4.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //PreOrden
					
					PreOrden(p);
					getchar();
					getchar();
					
					break;
				}
			case 2:
				{
					system("CLS"); //InOrden
					
					InOrden(p);
					getchar();
					getchar();
					
					break;
				}
			case 3:
				{
					system("CLS"); //PostOrden
					
					PostOrden(p);
					getchar();
					getchar();
					
					break;
				}
			case 4:
				{
					system("CLS"); //Salir
					break;
				}
			default:
				{
					system("CLS"); //Dato no válido
					printf("Dato no válido");
					getchar();
					getchar();
					break;
				}
		}
	}
	while(menu!=4);
	
	getchar();
}

void CrearArbol()
{
	p=new(struct nodo);
	p->num=1;
	q=p;
	r=p;
	r=new(struct nodo);
	r->num=2;
	q->izq=r;
	r=new(struct nodo);
	r->num=3;
	q->der=r;
	q=q->izq;
	r=new(struct nodo);
	r->num=4;
	r->der=NULL;
	r->izq=NULL;
	q->izq=r;
	r=new(struct nodo);
	r->num=5;
	r->der=NULL;
	r->izq=NULL;
	q->der=r;
	q=p->der;
	q->izq=NULL;
	r=new(struct nodo);
	r->num=6;
	r->der=NULL;
	r->izq=NULL;
	q->der=r;
	/*Crea:
			6
		3
			NULL
	1
			5
		2
			4
	*/
}

void PreOrden(TipoLista arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		printf("%d - ",arbol->num);
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
	
}

void InOrden(TipoLista arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		InOrden(arbol->izq);
		printf("%d - ",arbol->num);
		InOrden(arbol->der);
	}
	
}

void PostOrden(TipoLista arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		printf("%d - ",arbol->num);
	}
	
}
