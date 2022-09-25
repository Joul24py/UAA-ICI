/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Profundidad

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 14 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
// 1 50 1 25 1 75 1 18 1 30 1 71 1 99 2
// 1 50 1 25 1 75 1 5 1 30 1 60 1 90 1 26 1 65 1 80 1 28 2

//Variables globales-------------------------------------------------------------------------------------------
int flag=0,pos=0;

//Estructuras--------------------------------------------------------------------------------------------------
struct arbol
{
	struct arbol *ant;
	int num;
	bool visitado;
	struct arbol *der;
	struct arbol *izq;
};

struct pila
{
	int num;
	struct pila *ap;
};

//Tipos definidos----------------------------------------------------------------------------------------------
typedef struct arbol *TipoLista1;
typedef struct pila *TipoLista2;

TipoLista1 o = NULL;
TipoLista1 o1 = NULL;

TipoLista2 p=NULL;
TipoLista2 q;
TipoLista2 r;

//Las funciones------------------------------------------------------------------------------------------------
void InsertarNodo(TipoLista1 &o, int n, TipoLista1 &o1);
void MostrarArbol(TipoLista1 o, int cont);
void Profundidad(TipoLista1 o, int n);
void AgregarPila(int x);
void EliminarPila();
void ImprimirPila();

//La función main----------------------------------------------------------------------------------------------
main()
{
	setlocale(LC_ALL,"");
	
	int cont,menu,x;
	
	do
	{
		cont=0;
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n\n");
		printf("1.- Insertar un elemento al árbol\n");
		printf("2.- Mostrar el árbol\n");
		printf("3.- Búsqueda en Profundidad\n");
		printf("4.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); // Insertar nodo
					
					printf("Escriba el dato a agregar:\n");
					scanf("%d",&x);
					InsertarNodo(o,x,o1);
					
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); // Mostrar árbol
					
					MostrarArbol(o,cont);
					
					getchar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); // Búsqueda en Profunidad
					
					printf("Escriba el dato a buscar:\n");
					scanf("%d",&x);
					printf("\n");
					printf("==============================================\n");
					printf("Comenzando búsqueda...\n\n");
					Profundidad(o,x);
					
					getchar();
					getchar();
					break;
				}
			case 4:
				{
					system("CLS"); // Salir
					
					getchar();
					break;
				}
			default:
				{
					system("CLS"); // Dato no v�lido
					
					getchar();
					break;
				}
		}
	}
	while(menu!=4);
	
	getchar();
}

//Insertar un nodo al árbol------------------------------------------------------------------------------------
void InsertarNodo(TipoLista1 &o, int n, TipoLista1 &o1)
{
	if(o==NULL)
	{
		o=new(struct arbol);
		o->num=n;
		o->der=NULL;
		o->visitado=false;
		o->izq=NULL;
		
		o->ant=o1;
	}
	else
	{
		int ValorRaiz = o->num;
		
		if(n<ValorRaiz)
		{
			InsertarNodo(o->izq,n,o);
		}
		else
		{
			InsertarNodo(o->der,n,o);
		}
	}
}

//Mostrar el árbol---------------------------------------------------------------------------------------------
void MostrarArbol(TipoLista1 o, int cont)
{
	if(o==NULL)
	{
		return;
	}
	else
	{
		MostrarArbol(o->der,cont+1);
		for(int i=0; i<cont; i++)
		{
			printf("   ");
		}
		printf("%d\n",o->num);
		MostrarArbol(o->izq,cont+1);
	}
}

//Algoritmo de profundidad-------------------------------------------------------------------------------------
void Profundidad(TipoLista1 o, int n)
{
	if(o->num==n)
	{
		AgregarPila(o->num);
		ImprimirPila();
		printf("\n");
		Sleep(1200);
		flag=1;
		return;
	}
	else
	{
		if(o->izq!=NULL && o->izq->visitado==false)
		{
			AgregarPila(o->num);
			ImprimirPila();
			printf("\n");
			Sleep(1200);
			//system("CLS");
			Profundidad(o->izq,n);
			if(flag==1)
			{
				return;
			}
			//Agregar a la pila
		}
		if(o->der!=NULL && o->der->visitado==false)
		{
			AgregarPila(o->num);
			ImprimirPila();
			printf("\n");
			Sleep(1200);
			//system("CLS");
			Profundidad(o->der,n);
			if(flag==1)
			{
				return;
			}
		}
		o->visitado=true;
		
		if(o->ant!=NULL)
		{
			AgregarPila(o->num);
			ImprimirPila();
			printf("\n");
			Sleep(1200);
			//system("CLS");
			EliminarPila();
			EliminarPila();
			Profundidad(o->ant,n);
			if(flag==1)
			{
				return;
			}
		}
	}
}

//Agregar a la pila que apoya el recorrido---------------------------------------------------------------------
void AgregarPila(int x)
{
	if(p==NULL)
	{
		p=new(struct pila);
		p->num=x;
		p->ap=NULL;
		q=p;
		r=p;
		pos++;
	}
	else
	{
		r=new(struct pila);
		r->num=x;
		r->ap=NULL;
		q->ap=r;
		q=r;
		pos++;
	}
}

//Eliminar de la pila que apoya al recorrido-------------------------------------------------------------------
void EliminarPila()
{
	TipoLista2 a;
	a=p;
	if(pos==0)
	{
		printf("Pila vacía");
	}
	else
	{
		if(pos==1)
		{
			p=NULL;
			pos--;
		}
		else
		{
			q=p;
			while(q->ap!=r)
			{
				q=q->ap;
			}
			delete r;
			r=q;
			pos--;
		}
	}
}

//Imprimir la pila que apoya al recorrido----------------------------------------------------------------------
void ImprimirPila()
{
	TipoLista2 a;
	int i=0;
	a=p;
	if(pos==0)
	{
		printf("Pila vacía");
		printf("\n");
	}
	else
	{
		do
		{
			printf("%d ",a->num);
			a=a->ap;
			i++;
		}
		while(i<pos);
		//printf("\n");
	}
}
