#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void CasoMejor(int arreglo[], int tam);
void CasoPromedio(int arreglo[], int tam);
void CasoPeor(int arreglo[], int tam);
void Imprimir(int arreglo[], int tam);
void BubbleSort(int arreglo[], int tam);
void InsertionSort(int arreglo[], int tam);
void SelectionSort(int arreglo[], int tam);
void ShellSort(int arreglo[], int tam);
void QuickSort(int arreglo[],int first,int last);
void MergeSort(int arr[], int l, int r);
	void PreMerge(int arr[], int l, int m, int r);
void RadixSort(int arreglo[], int tam);
void HeapSort(int arreglo[], int tam);
	void heapify(int arreglo[],int tam, int i);

main()
{
	setlocale(LC_ALL,"");
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	getchar();
}

void CasoMejor(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		arreglo[cont]=cont+1;
		cont++;
		if(cont==tam-2)
		{
			arreglo[tam-2]=tam;
			arreglo[tam-1]=tam-1;
			break;
		}
	}
	while(cont<tam);
}

void CasoPromedio(int arreglo[], int tam)
{
	int cont=0;
	srand(time(NULL));
	do
	{
		arreglo[cont]=1+rand()%(10000000);
		cont++;
	}
	while(cont<tam);
}

void CasoPeor(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		arreglo[cont]=tam-cont;
		cont++;
	}
	while(cont<tam);
}

void Imprimir(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		printf("[%d]\n",arreglo[cont]);
		cont++;
	}
	while(cont<tam);
}

void BubbleSort(int arreglo[], int tam)
{
	int cont=0,aux;
	
	do
	{
		if(arreglo[cont]>arreglo[cont+1])
		{
			aux=arreglo[cont];
			arreglo[cont]=arreglo[cont+1];
			arreglo[cont+1]=aux;
			cont=0;
		}
		else
		{
			cont++;
		}
	}
	while(cont<tam);
}

void InsertionSort(int arreglo[], int tam)
{
	for(int cont=1; cont<tam; cont++)
	{
		int aux1 = arreglo[cont];
		int aux2 = cont;
		while(aux2>0&&arreglo[aux2-1]>aux1)
		{
			arreglo[aux2] = arreglo[aux2-1];
			aux2--;
		}
		arreglo[aux2]=aux1;
	}
}

void SelectionSort(int arreglo[], int tam)
{
	int aux,min;
	for(int cont1=0; cont1<tam; cont1++)
	{
		min=cont1;
		for(int cont2=cont1+1; cont2<tam; cont2++)
		{
			if(arreglo[cont2]<arreglo[min])
			{
				min=cont2;
			}
		}
		aux=arreglo[cont1];
		arreglo[cont1]=arreglo[min];
		arreglo[min]=aux;
	}
}

void ShellSort(int arreglo[], int tam)
{
	int saltos, aux;
    saltos=tam/2;

    	while(saltos>0)
    	{
	    	for(int i=saltos+1;i<=tam;i++)
		   	{
		   		int j=i-saltos;
            	while(j>=0)
            	{
             		if(arreglo[j]>=arreglo[j+saltos])
					{
        	    		aux=arreglo[j];
                    	arreglo[j]=arreglo[j+saltos];
                    	arreglo[j+saltos]=aux;
					}
					else
					{
						j=0;
					}
					j=j-saltos;
			 	}
		   	}
			saltos=saltos/2;
	  	}	
}

void QuickSort(int arreglo[],int first,int last)
{
	int cont1,cont2,pivot,aux;

   	if(first<last)
   	{
      	pivot=first;
      	cont1=first;
      	cont2=last;

      	while(cont1<cont2)
	  	{
         	while(arreglo[cont1]<=arreglo[pivot]&&cont1<last)
         	{
         		cont1++;
		 	}
         	while(arreglo[cont2]>arreglo[pivot])
         	{
         		cont2--;
		 	}
         	if(cont1<cont2)
		 	{
            	aux=arreglo[cont1];
            	arreglo[cont1]=arreglo[cont2];
            	arreglo[cont2]=aux;
         	}
      	}
      	
      	aux=arreglo[pivot];
      	arreglo[pivot]=arreglo[cont2];
      	arreglo[cont2]=aux;
      	QuickSort(arreglo,first,cont2-1);
      	QuickSort(arreglo,cont2+1,last);
   	}
}

void MergeSort(int arr[], int l, int r) 
{
	if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
  
        PreMerge(arr, l, m, r); 
    }
}

void PreMerge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void RadixSort(int arreglo[], int tam)
{
	int max = arreglo[0];
	for (int i=1;i<tam;i++)
	{
    	if (arreglo[i] > max)
    	{
    		max = arreglo[i];
		}
	}
	int m=max;
	
    for (int exp=1;m/exp>0;exp*=10)
	{
		int salida[tam];
		int i,count[10]={0}; 
	  
	    for (i=0;i<tam;i++)
	    {
	    	count[(arreglo[i]/exp)%10]++; 
		}
	  
	    for (i=1;i<10;i++)
	    {
	    	count[i]+=count[i-1]; 
		}
		
	    for (i=tam-1;i>=0;i--) 
	    { 
	        salida[count[(arreglo[i]/exp)%10]-1]=arreglo[i]; 
	        count[(arreglo[i]/exp)%10]--; 
	    } 
	   
	    for (i=0;i<tam;i++) 
	    {
	    	arreglo[i]=salida[i]; 
		}
	}
}

void HeapSort(int arreglo[], int tam)
{
	int aux;
	for (int i = tam / 2 - 1; i >= 0; i--)
		heapify(arreglo,tam, i);

	for (int i=tam-1; i>=0; i--)
	{
		aux=arreglo[0];
		arreglo[0]=arreglo[i];
		arreglo[i]=aux;

		heapify(arreglo,i, 0);
	}
}

void heapify(int arreglo[],int tam, int i)
{
	int largest = i,aux;
	int d = 2*i + 1;
	int iz = 2*i + 2;

	if (iz < tam && arreglo[iz] > arreglo[largest])
		largest = iz;

	if (d < tam && arreglo[d] > arreglo[largest])
		largest = d;

	if (largest != i)
	{
		aux=arreglo[i];
		arreglo[i]=arreglo[largest];
		arreglo[largest]=aux;

		heapify(arreglo,tam, largest);
	}
}
