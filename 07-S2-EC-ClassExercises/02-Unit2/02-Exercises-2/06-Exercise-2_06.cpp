//Ejercicio 2_06: Implemente un programa para sumar los números pares de una lista doblemente ligada
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,y,suma=0,z;

struct nodo
{
	struct nodo *ant;
	int num;
	struct nodo *sig;
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
					if(p!=NULL)
					{
						printf("\nLa suma de los elementos de la lista es: %d",suma);
					}
					
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
					system("CLS"); //Dato no v�lido
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
		p->ant=NULL;
		p->num=x;
		p->sig=NULL;
		q=p;
		r=p;
		z=x%2;
		if(z==0)
		{
			suma=suma+x;
		}
	}
	else
	{
		r=new(struct nodo);
		r->ant=q;
		r->num=x;
		r->sig=NULL;
		q->sig=r;
		q=r;
		z=x%2;
		if(z==0)
		{
			suma=suma+x;
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
			a=a->sig;
		}
		while(a);
	}
}

void InsertarDerecha()
{
	r=new(struct nodo);
	r->ant=q;
	r->num=x;
	r->sig=NULL;
	q->sig=r;
	q=r;
}

void InsertarIzquierda()
{
	TipoLista a;
	a=new(struct nodo);
	a->ant=NULL;
	a->num=x;
	a->sig=p;
	p->ant=a;
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
			b->ant=a;
			b->num=x;
			b->sig=a->sig;
			a->sig=b;
			
			TipoLista c;
			c=a->sig;
			c->ant=b;
			
			flag=1;
			printf("Dato agregado exitosamente\n");
		}
		a=a->sig;
	}
	while(a);
	if(flag==0)
	{
		printf("El dato proporcionado no se encuentra en la lista\n");
	}
}
