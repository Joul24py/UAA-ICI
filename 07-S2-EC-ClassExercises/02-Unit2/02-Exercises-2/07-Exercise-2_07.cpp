//Ejercicio 2_07: Implemente un programa para ordenar una lista simple en forma ascendente
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,y;

struct nodo
{
	int num;
	struct nodo *ap;
};

typedef struct nodo *TipoLista;

TipoLista p=NULL;
TipoLista q;
TipoLista r;

void CrearLista();
void ImprimirLista();
void InsertarDerecha();
void InsertarIzquierda();
void InsertarEnMedio();
void Ordenar();

main()
{
	setlocale(LC_ALL,"");
	
	do
	{
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n\n");
		printf("1.- Crear una lista de N nodos\n");
		printf("2.- Mostrar la lista de N nodos\n");
		printf("3.- Insertar un nodo a la derecha\n");
		printf("4.- Insertar un nodo a la izquierda\n");
		printf("5.- Insertar un nodo en medio\n");
		printf("6.- Ordenar ascendentemente la lista\n");
		printf("7.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //Crear lista de n nodos
					
					do
					{
						system("CLS");
						printf("Escriba un número (0 para salir):\n");
						scanf("%d",&x);
						if(x!=0)
						{
							CrearLista();
						}
					}
					while(x!=0);
					
					
					break;
				}
			case 2:
				{
					system("CLS"); //Mostrar lista de n nodos
					ImprimirLista();
					
					getchar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); //Insertar a la derecha
					
					if(p==NULL)
					{
						printf("Lista vacía");
					}
					else
					{
						printf("Escriba un número:\n");
						scanf("%d",&x);
						InsertarDerecha();
					}
					
					getchar();
					getchar();
					break;
				}
			case 4:
				{
					system("CLS"); //Insertar a la izquierda
					
					if(p==NULL)
					{
						printf("Lista vacía");
					}
					else
					{
						printf("Escriba un número:\n");
						scanf("%d",&x);
						InsertarIzquierda();
					}
					
					getchar();
					getchar();
					break;
				}
			case 5:
				{
					system("CLS"); //Insertar en medio
					
					if(p==NULL)
					{
						printf("Lista vacía");
					}
					else
					{
						printf("Escriba un número:\n");
						scanf("%d",&x);
						printf("Escriba su antecesor:\n");
						scanf("%d",&y);
						InsertarEnMedio();
					}
					
					getchar();
					getchar();
					break;
				}
			case 6:
				{
					system("CLS"); //Ordenar ascendentemente la lista
					if(p==NULL)
					{
						printf("Lista vacía");
					}
					else
					{
						Ordenar();
					}
					
					getchar();
					getchar();
					break;
				}
			case 7:
				{
					system("CLS"); //Salir
					break;
				}
			default:
				{
					system("CLS"); //Dato no v�lido
					printf("Dato no válido");
					getchar();
					getchar();
					break;
				}
		}
	}
	while(menu!=7);
	
	getchar();
}

void CrearLista()
{
	if(p==NULL)
	{
		p=new(struct nodo);
		p->num=x;
		p->ap=NULL;
		q=p;
		r=p;
	}
	else
	{
		r=new(struct nodo);
		r->num=x;
		r->ap=NULL;
		q->ap=r;
		q=r;
	}
}

void ImprimirLista()
{
	TipoLista a;
	a=p;
	if(p==NULL)
	{
		printf("Lista vacía");
	}
	else
	{
		do
		{
			printf("%d\n",a->num);
			a=a->ap;
		}
		while(a);
	}
}

void InsertarDerecha()
{
	r=new(struct nodo);
	r->num=x;
	r->ap=NULL;
	q->ap=r;
	q=r;
}

void InsertarIzquierda()
{
	TipoLista a;
	a=new(struct nodo);
	a->num=x;
	a->ap=p;
	p=a;
}

void InsertarEnMedio()
{
	int flag=0;
	TipoLista a;
	a=p;
	TipoLista b;
	
	do
	{
		if(a->num==y)
		{
			b=new(struct nodo);
			b->num=x;
			b->ap=a->ap;
			a->ap=b;
			flag=1;
			printf("Dato agregado exitosamente\n");
		}
		a=a->ap;
	}
	while(a);
	if(flag==0)
	{
		printf("El dato proporcionado no se encuentra en la lista\n");
	}
}

void Ordenar()
{
	TipoLista a;
	TipoLista b;
	int aux;
	a=p;
	do
	{
		b=a->ap;
		if(a->num>b->num)
		{
			aux=b->num;
			b->num=a->num;
			a->num=aux;
			a=p;
		}
		else
		{
			a=a->ap;
			b=a->ap;
		}
		
	}
	while(b!=NULL);
	printf("Ordenamiento Terminado\n");
}
