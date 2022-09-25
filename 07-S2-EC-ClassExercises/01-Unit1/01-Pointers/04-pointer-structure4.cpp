#include <stdio.h>

main()
{
	int u=1;
	int v=3;
	void func1(int u, int v);
	void func2(int *pu, int *pv);
	
	printf("u = %d     v = %d\n",u,v);
	func1(u,v);
	printf("u = %d     v = %d\n",u,v);
	printf("Antes de la llamada a func 2: u = %d     v = %d\n",u,v);
	func2(&u,&v);
	printf("Despues de la llamada a func 2: u = %d     v = %d\n",u,v);
	getchar();
}

func1(int u,int v)
{
	u=0;
	v=0;
	printf("Dentro de la Funcion 1: u = %d     v = %d\n",u,v);
}

func2(int *pu, int *pv)
{
	*pu=0;
	*pv=0;
	printf("Dentro de la Funcion 2: *pu = %d     *pv = %d\n",|,*pv);
}
