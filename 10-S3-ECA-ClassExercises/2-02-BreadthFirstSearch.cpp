/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Anchura

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 18 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

//Variables globales y declaraciones---------------------------------------------------------------------------
struct nodo
{
	int valor;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo *ABB;

void inserta(ABB &arbol,int x);
void verArbol(ABB arbol, int nro );
void recorrexNivel(ABB arbol);

struct nodoCola
{
	ABB ptr;
	struct nodoCola *sig;
};

struct cola
{
	struct nodoCola *adelante; //Primero
	struct nodoCola *atras; //Atras
};

void inicializa(struct cola &q);
void encola(struct cola &q, ABB n);
ABB desencola(struct cola &q);

//La función main----------------------------------------------------------------------------------------------
main()
{
	setlocale(LC_ALL,"");
	
	ABB arbol = NULL;
	int n,x;
	printf("Cantidad de elementos del árbol\n");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		printf("Ingrese el valor: ");
		scanf("%d",&x);
		inserta(arbol, x);
	}

	printf("Árbol: \n\n\n");
	verArbol(arbol, 0);
	printf("\n\nEmpieza el recorrido... \n\n");
	recorrexNivel(arbol);
	return 0;
}

//Insertar al árbol--------------------------------------------------------------------------------------------
void inserta(ABB &arbol, int x)
{
	if(arbol==NULL)
	{
		arbol=new (struct nodo);
		arbol->valor = x;
		arbol->der = NULL;
		arbol->izq = NULL;
	}
	else
	{
		if(x<arbol->valor) 
		{
			inserta(arbol->izq,x);
		}
		else
		{
			if(x>arbol->valor)
			{
				inserta(arbol->der,x);
			}
		}
	}
}

//Imprimir el árbol--------------------------------------------------------------------------------------------
void verArbol(ABB arbol,int nro)
{
	int i;
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		verArbol(arbol->der,nro+1);
		for (i=0;i<nro;i++)
		{
			printf("   ");
	 	}
	 	printf("%d \n",arbol->valor);
		verArbol(arbol->izq,nro+1);
	}
}

//Hace el recorrido en anchura---------------------------------------------------------------------------------
void recorrexNivel(ABB arbol)
{
	struct cola q;  //La cola
	inicializa(q); //Inicializa la cola
	if(arbol!=NULL)
	{
		encola(q, arbol);
		while(q.adelante!=NULL)
		{
			arbol = desencola(q);
			printf("%d  ",arbol->valor);
			if(arbol->izq!=NULL)
			{
				encola(q,arbol->izq);
			}
   			if(arbol->der!=NULL) encola(q, arbol->der);
  		}
 	}
}

//Validación de inicio-----------------------------------------------------------------------------------------
void inicializa(struct cola &q)
{
	q.adelante =NULL; //Sin primer elemento
	q.atras = NULL; //Sin último elemento
}

//Agrega a cola de apoyo del recorrido-------------------------------------------------------------------------
void encola(struct cola &q, ABB n) //Inserta al final de la cola
{
	struct nodoCola *p;        //Apunta a items en la cola
	p =new struct nodoCola;   //Memoria para nuevo items
	p->ptr =n;                //Asigna el valor
	p->sig =NULL;             //Se convierte en el ultimo items
	if(q.adelante ==NULL)
	{
		q.adelante=p; //Encola el primer item
	}
	else
	{
		q.atras->sig =p;      //Sino apunta a un nuevo item
	}
 	q.atras=p;                 //El ultimo item ahora es el ingresado
}

//Elimina de la cola de apoyo del recorrido--------------------------------------------------------------------
ABB desencola(struct cola &q)  //...Retira el elemento de la cola
{
	struct nodoCola *p;
	p=q.adelante;     //p apunta al primer item
	ABB n=p->ptr;
	q.adelante = q.adelante->sig;   //Retiro item de la cola
	delete (p);                     //Libera memoria
	return n;
}
