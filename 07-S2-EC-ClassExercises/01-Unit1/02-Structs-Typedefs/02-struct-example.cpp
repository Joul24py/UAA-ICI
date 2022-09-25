#include <stdio.h> //Programa para Estructuras
#include <string.h>

struct CD
	{
		char titulo[30];
		char artista[25];
		float precio;
		int canciones;
	} CD1=
	{
		//Inicializamos la estructura CD1 creando sus valores usando las definiciones iniciales
		"Divide", //Título
		"Ed Sheeran", //Artista
		102, //Precio
		16 //Canciones
	};

main()
{
	struct CD CD2; //Definimos una nueva estructura llamada CD2
	strcpy(CD2.titulo,"Moving Past");
	strcpy(CD2.artista,"The Fold");
	CD2.precio=1000;
	CD2.canciones=13;
	
	printf("CD 1:\n");
	printf("Titulo: %s\n",CD1.titulo);
	printf("Artista: %s\n",CD1.artista);
	printf("Precio: %.2f\n",CD1.precio);
	printf("Total Canciones: %d\n",CD1.canciones);
	
	printf("\n\n\nCD 2:\n");
	printf("Titulo: %s\n",CD2.titulo);
	printf("Artista: %s\n",CD2.artista);
	printf("Precio: %.2f\n",CD2.precio);
	printf("Total Canciones: %d\n",CD2.canciones);
	
}
