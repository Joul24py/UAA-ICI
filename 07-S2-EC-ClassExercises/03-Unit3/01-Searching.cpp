#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL,"");
	
	//Busqueda Secuencial
	
	int sec[10]={9,3,2,10,1,5,4,8,7,6};
	int i=0,dato,flag=0;
	
	printf("Pon el número a buscar:\n");
	scanf("%d",&dato);
	printf("\n\n");
	
	while((flag==0)&&(i<10))
	{
		if(sec[i]==dato)
		{
			flag=1;
		}
		i++;
	}
	
	if(flag==0)
	{
		printf("El número no existe en el arreglo");
	}
	
	if(flag==1)
	{
		printf("El número ha sido encontrado en la posición %d en el arreglo",i-1);
	}
	
	printf("\n\n");
	//Busqueda Binaria
	
	int bin[10]={2,8,12,14,17,18,20,30,45,99};
	int inf,sup,mitad,data,flag1=0;
	
	printf("Pon el número a buscar:\n");
	scanf("%d",&data);
	
	inf=0;
	sup=10;
	
	while(inf+1!=sup)
	{
		mitad=(inf+sup)/2;
		
		if(bin[mitad]==data)
		{
			flag1=1;
			break;
		}
		
		if(bin[mitad]>data)
		{
			sup=mitad;
			mitad=(inf+sup)/2;
		}
		
		if(bin[mitad]<data)
		{
			inf=mitad;
			mitad=(inf+sup)/2;
		}
	}
	
	if(flag1==0)
	{
		printf("El número no existe en el arreglo");
	}
	
	if(flag1==1)
	{
		printf("El número ha sido encontrado en la posición %d en el arreglo",mitad);
	}
	
	
	getchar();
	getchar();
}
