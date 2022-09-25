#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Programa que lea la contraseña de un usuario y si la contraseña es igual a "12345" desplegar "Contraseña correcta" y terminar el programa.
De lo contrario mostrar "Contraseña Incorrecta" y seguir pidiendo la contraseña*/

int cont=12345,dat;

main()
{
	setlocale(LC_ALL, "");
	
	do
	{
		printf("Escribe la contraseña\n");
		scanf("%d",&dat);
		cont=12345;
	}
	while(cont!=dat);
	printf("Descifraste la contraseña\n");
		
	getchar();
}
