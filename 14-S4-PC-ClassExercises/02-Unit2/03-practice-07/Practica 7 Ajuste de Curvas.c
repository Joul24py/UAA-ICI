/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa realiza distintos métodos de ajuste de curvas. El programa
                  permite la selección de cualquiera de estos métodos junto con algunos que permite
                  la interpolación de un dato a querer conocer. Entre ellos tenemos el método de
                  Mínimos Cuadrados, el polinomio único de interpolación, el método de interpolación
                  por el polinomio de Lagrange y también por el polinomio de Newton
--------------------------------------------------------------------------------------*/ 

#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL,"");
	int a,b,c,dim,e=0,i,j=0,k=0,n,op;
	float d,den=1,fx,interseccion,m,num=1,sumx=0,sumy=0,sumxy=0,sumx2=0,t=0,valor,x,y;
	
	do
	{
		system("CLS");
		printf("\n---------------------Ajuste de Curvas---------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Ejecutar el método de interpolación por Mínimos Cuadrados\n\n");
		printf("2.- Ejecutar el método del Polinomio único de interpolación\n\n");
		printf("3.- Ejecutar el método de interpolación por Polinomio de Lagrange\n\n");
		printf("4.- Ejecutar el método de interpolación por Polinomio de Newton\n\n");
		printf("5.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
		
		system("CLS");
		
		switch(op)
		{
			case 1:
				{
					printf("\n---------------------Método de Mínimos Cuadrados---------------------\n\n");
					
					printf ("Ingresa la cantidad de datos (n): ");
					scanf("%d",&n);
  					for(i=0; i<n; i++)
					{
  						printf("Ingrese el valor de X n %d: ",i+1);
            			scanf("%f", &x);
            			printf("Ingrese el valor de Y n %d: ",i+1);
            			scanf("%f" ,&y);
						
						sumx+=x;
            			sumy+=y;
            			sumxy+=(x)*(y);
						sumx2+=(x)*(x);
					}	
		  			printf("\n");
 					
 					
					//Resolviendo la ecuacion de la Pendiente ajustada a minimos cuadrados
					m=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
					printf("La pendiente ajustada por minimos cuadrados es: %f \n",m);	
					
					//Resolviendo la ecuacion para hallar el punto de corte por minimos cuadrados 
					interseccion=(sumy-((m)*sumx))/n;
					printf("\nEl punto de intersección por minimos cuadrados es: %f", interseccion);
					
					do
					{
						printf("Ingrese una coordenada en x que se deseé conocer dentro de la función (0 para salir):\n");
						scanf("%f",&valor);
						if(valor!=0)
						{
							fx = (m*valor) + interseccion;
							printf("x | y\n");
							printf("%f | %f\n",valor,fx);
						}
					}
					while(valor!=0);
					
					getchar();
					getchar();
					break;
				}
			case 2:
				{
					printf("\n------------------Polinomio único de interpolación-------------------\n\n");
					
					printf("Proporcione la cantidad de puntos: ");
					scanf("%d",&dim);
					float mat[dim][dim+1];
					
					for(i=0;i<dim;i++)
					{
						printf("Escriba el valor de x%d:\n",i+1);
						scanf("%f",&valor);
						printf("Escriba el valor de y%d:\n",i+1);
						scanf("%f",&mat[i][dim]);
						for(j=0;j<dim;j++)
						{
							if(j==0)
							{
								mat[i][j]=1;
							}
							else
							{
								mat[i][j]=pow(valor,j);
							}
						}
					}
					
					float res[dim];
					
					b=0;
					for(a=dim-1;a>=0;a--)
					{
						c=b;
						while(c!=0)
						{
							mat[a][dim]=mat[a][dim]-(mat[a][dim-c]*res[dim-c]);
							c--;
						}
						b++;
						res[a]=mat[a][dim]/mat[a][a];
					}
					
					printf("\n");
					printf("Polinomio:\n");
					for(i=0;i<dim;i++)
					{
						if(i==0)
						{
							printf("Pn(xi) = %f",res[i]);
						}
						if(i==1)
						{
							printf(" + %fx",res[i]);
						}
						printf(" + %fx^%d",res[i],i);
					}
					
					getchar();
					getchar();
					break;
				}
			case 3:
				{
					printf("\n---------------Polinomio de interpolación de Lagrange----------------\n\n");
					
					printf ("Ingresa la cantidad de datos (n): ");
					scanf("%d",&n);
					
					float datos[n][2];
					
					for(i=0;i<n;i++)
					{
						printf("Ingrese el valor de X n %d: ",i+1);
            			scanf("%f", &x);
            			printf("Ingrese el valor de Y n %d: ",i+1);
            			scanf("%f" ,&y);
            			datos[i][0]=x;
            			datos[i][1]=y;
					}
					
					printf("Ingrese una coordenada en x que se deseé conocer dentro de la función (0 para salir):\n");
					scanf("%f",&valor);
					fx=0;
					num=1;
					den=1;
					t=0;
					for(i=0;i<n;i++)
					{
						j=0;
						do
						{
							if(j!=i)
							{
								num=num*(valor-datos[j][0]);
								den=den*(datos[i][1]-datos[j][1]);
							}
							j++;
						}
						while(j<n);
						t=(num/den)*datos[i][1];
						fx=fx+t;
					}
					
					printf("\n\nx | y\n");
					printf("%f | %f\n",valor,fx);
					
					getchar();
					getchar();
					break;
				}
			case 4:
				{
					printf("\n----------------Polinomio de interpolación de Newton-----------------\n\n");
					
					printf("Número de datos (n): ");
					scanf("%d",&n);
					float a[n];
					float b[n];
					float copiab[n];
					float coef[n];
					
					for(i=0;i<n;i++)
					{
						printf("Valor de x%i: ",i);
						scanf("%f",&a[i]);
					}
					
					for(i=0;i<n;i++)
					{
						printf("Valor de y%i: ",i);
						scanf("%f",&b[i]);
					}
					
					coef[0]=b[0];
					for(k=0;k<n;k++)
					{
						for(j=0;j<n-(1+k);j++)
						{
							if(k==(j+k))
							{
								for(i=0;i<n;i++)
								{
									copiab[i]=b[i];
								}
							}
							
							b[j]=(copiab[j+1]-copiab[j])/(a[j+(1+k)]- a[j]);
							if(k==(j+k))
							{
								coef[k+1]=b[j];
							}
						}
						printf("\n");
					}
				        
					printf("\n");
					float res,x,eval;
					printf("\n¿En qué punto se evaluará? ");
					scanf("%f",&x);
					eval=coef[0];
					
					for(i=1;i<n;i++)
					{
						res=coef[i];
						for(j=0;j<i;j++)
						{
							res=res*(x-a[j]);
						}
						printf("%.1fx * %.1fx - %.1fx + ",res,x,a[j]);
						eval=eval+res;
					}
					
					printf("\n");
					printf("\nEl valor de f(x) cuando x=%.1f es %.1f",x,eval);
					
					getchar();
					getchar();
					break;
				}
			case 5:
				{
					break;
				}		
		}
		getchar();
		
	}
	while(op!=5);	
}
