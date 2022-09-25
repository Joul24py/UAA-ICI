#include <stdio.h>

main()
{
	int v=3;
	int *pv;
	
	pv=&v;
	
	printf("v = %d, pv = %d",v,*pv);
	*pv=0;
	printf("\n");
	printf("v = %d, pv = %d",v,*pv);
	
	getchar();
}
