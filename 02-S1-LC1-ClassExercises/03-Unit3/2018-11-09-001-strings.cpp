#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*
Autores:
		Cardona Rivera José Luis
		Espinoza Sánchez Joel Alejandro
		Pérez Jaime Julio César
*/

char nombres[20],app[20],apm[20],nombrecompleto[90];
int tam=0;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Escribe tu nombre:\n\nNombres:\n");
	gets(nombres); //gets
	printf("\nApellido Paterno:\n");
	gets(app); //gets
	printf("\nApellido Materno:\n");
	gets(apm); //gets
	strcpy(nombrecompleto,nombres);
	strcat(nombrecompleto," ");
	strcat(nombrecompleto,app);
	strcat(nombrecompleto," ");
	strcat(nombrecompleto,apm);
	printf("\nNombre Completo: %s\n",nombrecompleto);
	strlwr(nombrecompleto);
	printf("\nNombre Completo (en minúsculas): %s\n",nombrecompleto);
	strupr(nombrecompleto);
	printf("\nNombre Completo (en mayúsculas): %s\n",nombrecompleto);
	tam=strlen(nombrecompleto);
	printf("\nEl tamaño de su nombre es de %d bits\n",tam);
}
