/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa resuelve sistemas de ecuaciones con la regla de Cramer
			 de matrices de 3*3 dadas por el ususario. En donde la última columna es tomada como el 
			 resultado del sistema de ecuaciones y la matriz restante las incógnitas dependientes.
--------------------------------------------------------------------------------------*/ 

#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	
	setlocale(LC_ALL,"");
    int i=0,j=0,op,n, mat[10][10],dim;
    float determinante;
    float determinante1;
    float determinante2;
    float determinante3;
    float x,y,z;
   
		
	do{
		system("CLS");
		printf("\n----------------Resolución de sistemas de ecuaciones de 3x3 con regla de Cramer---------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Escriba la dimensión del sistema\n\n");
		printf("2.- Escriba los datos\n\n");
		printf("3.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
		
		system("CLS");
		
	
		
			switch(op){
				
				case 1:
					{
						printf("Proporcione la cantidad de ecuaciones del sistema: ");
						scanf("%d",&dim);
						break;
					}
				case 2:
				printf("Tomando en cuenta que en las posiciones [1, 3],[2, 3],[3, 3] son el resultado del sistema de ecuaciones");
				for(i=0; i<3; i++)
   				 {
       				 for(j=0; j<4; j++)
						{
          				  printf("\nIngrese el dato [%d , %d]: ",i,j);
          				  scanf("%d",&mat[i][j]);
       					}
    			}
    			
    			printf("\nMatriz original:\n\n");
   			    for(i=0; i<3; i++)
				   {
				     for(j=0; j<4; j++)
					 {	
						printf(" %d ",mat[i][j]);
        		   	 }
        	     	    printf("\n");
   				   }
   				   
   				for(i=0; i<3; i++)
				   {
				     for(j=0; j<4; j++)
				        {
				        	
				          determinante=((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+
						  (mat[0][2]*mat[1][0]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][1])+
						  (mat[0][1]*mat[1][0]*mat[2][2]));
						  
						  determinante1=((mat[0][3]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][3])+
						  (mat[0][2]*mat[1][3]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][3])+(mat[0][3]*mat[1][2]*mat[2][1])+
						  (mat[0][1]*mat[1][3]*mat[2][2]));
						  
						  determinante2=((mat[0][0]*mat[1][3]*mat[2][2])+(mat[0][3]*mat[1][2]*mat[2][0])+
						  (mat[0][2]*mat[1][0]*mat[2][3]))-((mat[0][2]*mat[1][3]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][3])+
						  (mat[0][3]*mat[1][0]*mat[2][2]));
						  
						  determinante3=((mat[0][0]*mat[1][1]*mat[2][3])+(mat[0][1]*mat[1][3]*mat[2][0])+
						  (mat[0][3]*mat[1][0]*mat[2][1]))-((mat[0][3]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][3]*mat[2][1])+
						  (mat[0][1]*mat[1][0]*mat[2][3]));
				           
				        }   
   					 }
   					
	   				    //printf("\nDeterminante original=%f",determinante);
	   					//printf("\nDeterminante 1=%f",determinante1);
	   					//printf("\nDeterminante 2=%f",determinante2);
	   					//printf("\nDeterminante 3=%f\n",determinante3);
	   					  
	   					x=(determinante1)/(determinante);
	   					y=(determinante2)/(determinante);
	   					z=(determinante3)/(determinante);
	   					  
	   					printf("\nEl valor de x es: %f",x);
	   					printf("\nEl valor de y es: %f",y);
	   					printf("\nEl valor de z es: %f",z);
	   					getchar();
						
						break;		
				
				case 3:	break;		
		}
		getchar();
	}while(op!=3);	
}

    
    
