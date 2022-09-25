#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Para poner acentos o caracteres especiales hay dos formas

main()
{
	setlocale(LC_ALL, "");
	
	//La más convencional es código ASCII
	printf("%c\n",164);
	printf("a%co\n",164);
	//La otra es incluir la librería <stdlib.h> y <locale.h> y dentro del main se pone la primera línea
	printf("Hola mi compañero, estoy usando caracteres especiales: ñ");
	//Sin embargo, al usar ambos métodos, el del ASCII se buguea y no se ve claramente el caracter esperado
}
