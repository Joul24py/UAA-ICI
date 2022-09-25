//Ejercicio 2_08: Implemente un programa para obtener el número mayor de una lista de enteros
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,y,mayor=0;

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
		printf("6.- Salir\n");
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
					printf("\n\n El número mayor de la lista es: %d\n",mayor);
					
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
	while(menu!=6);
	
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
		if(x>mayor)
		{
			mayor=x;
		}
	}
	else
	{
		r=new(struct nodo);
		r->num=x;
		r->ap=NULL;
		q->ap=r;
		q=r;
		if(x>mayor)
		{
			mayor=x;
		}
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
