#include <stdio.h>

main()
{
	int u=3;
	int v;
	int *pu; //Apuntador a un entero
	int *pv; //Apuntador a un entero
	
	pu=&u; //Asigna dirección de u a pu
	//v=*pu; //Asigna valor de u a v
	//pv=&v; //Asigna dirección de v a pv
	
	printf("u &u pu *pu  ");
	printf("%d %d %d %d\n",u,&u,pu,*pu); //u y *pu son iguales. &u y pu son iguales
	printf("v &v pv *pv  ");
	printf("%d %d %d %d\n",v,&v,pv,*pv);
	
	/*
	Como observaremos al correr el programa, u y v son valores estáticos (en este caso es 3)
	pu y pv son valores dinámicos (por ser los apuntadores)
	El procedimiento viene arriba sobre los valores asignados
	*/
	
	getchar();
}
