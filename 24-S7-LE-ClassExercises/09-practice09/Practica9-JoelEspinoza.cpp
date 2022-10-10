#include <stdio.h>

int funcion();

int main()
{
	int a = 0;
	printf("Con pase de valores\n");
	printf("100\n");
	a = funcion();
	printf("%d\n",a);
	
	return 0;
}

int funcion()
{
	__asm__
	(
		"MOV $100, %eax\n"
		"ret\n"
	);
	return 0;
}
