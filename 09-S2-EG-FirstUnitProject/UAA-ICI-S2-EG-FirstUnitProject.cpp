#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>

float ad[4], bd[4], ao[4], bo[4], pm1[4],pm2[4], pe[4], xo[4], xd[4], yd[4], yo[4];
int pos=0,i , j;
int menu;
float tabla[5][5];

int cont=0,caux1=0,caux2=0,caux3=0;
float maxy=0,dify=0,otroy=0,maxx=0,difx=0,otrox=0;
float intsy[26];
char ecd1[15],eco1[15];


//Y=-a+b Demanda
//Y=a+b Oferta

void portada();
void pedir1();
void imprimir1();
void grafica1();
void pedir2();
void imprimir2();
void grafica2();

void gotoxy(int x, int y);

int main()
{
	setlocale(LC_ALL, "");
	//system("color F0");
	
	portada();
	pedir1();
	xd[pos]=bd[pos];
	xo[pos]=bo[pos];
	yd[pos]=(-1)*((bd[pos])/(ad[pos]));
	yo[pos]=(ao[pos]*yd[pos])+bo[pos];
	
	pe[pos]=(bo[pos]-bd[pos])/(ad[pos]-ao[pos]);
	pm1[pos]=pe[pos]/2;
	pm2[pos]=(pe[pos]+yd[pos])/2;
	
	tabla[0][0]=0;
	tabla[4][0]=yd[pos];
	tabla[2][0]=pe[pos];
	tabla[1][0]=pm1[pos];
	tabla[0][1]=xd[pos];
	tabla[4][1]=0;
	tabla[4][2]=yo[pos];
	tabla[0][2]=xo[pos];
	tabla[2][1]=(ad[pos]*pe[pos])+bd[pos];
	tabla[3][1]=(ad[pos]*pm2[pos])+bd[pos];
	tabla[1][2]=(ao[pos]*pm1[pos])+bo[pos];	
	tabla[2][2]=(ao[pos]*pe[pos])+bo[pos];
	tabla[3][2]=(ao[pos]*pm2[pos])+bo[pos];
	tabla[1][1]=(ad[pos]*pm1[pos])+bd[pos];
	tabla[3][0]=(pe[pos]+yd[pos])/2;
	
	imprimir1();
	printf("\n\n\n");
	grafica1();
	pos++;
	pedir2();
	tabla[0][3]=(ad[pos]*tabla[0][0])+bd[pos];
	tabla[1][3]=(ad[pos]*tabla[1][0])+bd[pos];
	tabla[2][3]=(ad[pos]*tabla[2][0])+bd[pos];
	tabla[3][3]=(ad[pos]*tabla[3][0])+bd[pos];
	tabla[4][3]=(ad[pos]*tabla[4][0])+bd[pos];
	imprimir2();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	grafica2();
	
	getch();
	return 0;
	
}

void portada()
{
	printf("                   UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES\n\n");
	printf("               Centro de Ciencias Económicas y Administrativas\n\n");
	printf("                          Departamento de Economía\n\n");
	printf("                              Economía General\n\n");
	printf("                                   2° \"A\"\n\n\n\n");
	printf("      Programa de Graficación de la Ecuación de la Oferta y la Demanda\n\n\n\n");
	printf("                    Asesor: Alejandro González Cadena\n\n\n");
	printf("                    Alumnos:\n");
	printf("                            Cardona Rivera José Luis\n");
	printf("                            Espinoza Sánchez Joel Alejandro\n");
	printf("                            Pardo Tinoco Jonathan David\n");
	printf("                            Pérez Jaime Julio César\n\n\n");
	printf("        Fecha de Entrega: Aguascalientes, Ags, 27 de marzo de 2019\n\n\n");
	printf("Presione \"ENTER\" para continuar ");
	getchar();
	system("CLS");
}

void pedir1()
{
	gotoxy(80,0);
	printf("Alumnos: ");
	gotoxy(80,1);
	printf("Cardona Rivera José Luis");
	gotoxy(80,2);
	printf("Espinoza Sánchez Joel Alejandro");
	gotoxy(80,3);
	printf("Pardo Tinoco Jonathan David");
	gotoxy(80,4);
	printf("Pérez Jaime Julio César");
	gotoxy(80,6);
	printf("Asesor:");
	gotoxy(80,7);
	printf("Alejandro González Cadena");
	gotoxy(0,0);
	printf("* Programa de Economía General para la Evaluación del Primer Parcial*\n\n");
	
	printf("Ingrese el valor de la pendiente de la ecuación de la demanda\n");
	scanf("%f",&ad[pos]);
	printf("Ingrese el valor de la ordenada al origen de la ecuación de la demanda\n");
	scanf("%f",&bd[pos]);
	printf("Ingrese el valor de la pendiente de la ecuación de la oferta\n");
	scanf("%f",&ao[pos]);
	printf("Ingrese el valor de la ordenada al origen de la ecuación de la oferta\n");
	scanf("%f",&bo[pos]);
	
}

void imprimir1()
{
	/*
	printf("%.2f\n",xd[pos]);
	printf("%.2f\n",xo[pos]);
	printf("%.2f\n",yd[pos]);
	printf("%.2f\n",yo[pos]);
	printf("%.2f\n",pe[pos]);
	printf("%.2f\n",pm1[pos]);
	printf("%.2f\n",pm2[pos]);
	*/
	
	printf("\n\nTabla de Datos:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==0&&j==0)
			{
				printf("| Qx  |");
			}
			if(i==1&&j==0)
			{
				printf("| Pdx |");
			}
			if(i==2&&j==0)
			{
				printf("| Pox |");
			}
			printf("| %.2f |",tabla[j][i]);
		}
		printf("\n");
	}
}




void grafica1(){
	gotoxy(0,17);
	printf("Gráfica de los Datos:");
	//Comienza grafica1 en gotoxy(0,18);
	maxy=bd[0];
	dify=maxy/25;
	otroy=maxy-(dify*caux1);
	intsy[0]=otroy;
	do
	{
		gotoxy(7,18+caux1);
		printf("| ");
		gotoxy(0,18+caux1);
		printf("%.2f",otroy);
		caux1++;
		otroy=maxy-(dify*caux1);
		intsy[caux1]=otroy;
	}
	while(caux1<26); //Al finalizar aquí, gotoxy termina de imprimir en (7,43) (o 44, not sure)
	caux1=0;
	maxx=tabla[4][0];
	difx=maxx/15;
	otrox=(caux1*difx);
	do
	{
		gotoxy(8+caux2,44);
		printf("_____");
		gotoxy(8+caux2,45);
		printf("%.1f",otrox);
		caux1++;
		otrox=(caux1*difx);
		caux2++;
		caux2++;
		caux2++;
		caux2++;
		caux2++;
	}
	while(caux2<(16*5)); //Termina de graficar los ejes adaptables
	
	caux1=0;
	caux2=0;
	do
	{
		gotoxy(8+caux2,18+caux1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("*");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		caux1++;
		caux2++;
		caux2++;
		caux2++;
		//caux2++;
		//caux2++;
	}
	while(caux1<26);
	
	//Ecuación de la oferta
	char a='*';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	caux1=25; //Primer punto
	caux2=10;
	caux3=0;
	do
	{
		if(bo[0]>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(8,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Segundo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*difx)+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(13,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Tercer punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*2))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(18,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Cuarto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*3))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(23,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Quinto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*4))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(28,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Sexto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*5))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(33,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Septimo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*6))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(38,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Octavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*7))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(43,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Noveno punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*8))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(48,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Decimo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*9))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(53,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Onceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*10))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(58,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Doceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*11))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(63,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Treceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*12))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(68,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Catorceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*13))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(73,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Quinceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*14))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(78,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Decimosexto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*15))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(83,18+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void pedir2()
{
	
	
	gotoxy(0,47);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n¿Qué deseas graficar?\n1-Demanda\n2-Oferta\n");
	scanf("%i",&menu);
	//ad[pos]=menu;
	if(menu==1){
		ad[1]=ad[0];
		
	}
	if(menu==2){
		ad[1]=ao[0];
	}
	printf("Ingrese el valor del intersecto en \"y\" de la nueva ecuación\n");
	scanf("%f",&bd[pos]);
	
}

void imprimir2()
{
	/*
	printf("%.2f\n",xd[pos]);
	printf("%.2f\n",xo[pos]);
	printf("%.2f\n",yd[pos]);
	printf("%.2f\n",yo[pos]);
	printf("%.2f\n",pe[pos]);
	printf("%.2f\n",pm1[pos]);
	printf("%.2f\n",pm2[pos]);
	*/
	
	printf("\n\nTabla de Datos:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==0&&j==0)
			{
				printf("| Qx  |");
			}
			if(i==1&&j==0)
			{
				printf("| Pdx |");
			}
			if(i==2&&j==0)
			{
				printf("| Pox |");
			}
			if(i==3&&j==0)
			{
				printf("|     |");
			}
			printf("| %.2f |",tabla[j][i]);
		}
		printf("\n");
	}
}

void grafica2(){
	
	
	gotoxy(0,67);
	printf("Gráfica de los Datos:");
	//Comienza grafica1 en gotoxy(0,18);
	maxy=bd[0];
	dify=maxy/25;
	caux1=0;
	otroy=maxy-(dify*caux1);
	intsy[0]=otroy;
	caux1=0;
	caux2=0;
	do
	{
		gotoxy(7,68+caux1);
		printf("| ");
		gotoxy(0,68+caux1);
		printf("%.2f",otroy);
		caux1++;
		otroy=maxy-(dify*caux1);
		intsy[caux1]=otroy;
	}
	while(caux1<26); //Al finalizar aquí, gotoxy termina de imprimir en (7,43) (o 44, not sure)
	caux1=0;
	maxx=tabla[4][0];
	difx=maxx/15;
	otrox=(caux1*difx);
	do
	{
		gotoxy(8+caux2,94);
		printf("_____");
		gotoxy(8+caux2,95);
		printf("%.1f",otrox);
		caux1++;
		otrox=(caux1*difx);
		caux2++;
		caux2++;
		caux2++;
		caux2++;
		caux2++;
	}
	while(caux2<(16*5)); //Termina de graficar los ejes adaptables
	
	caux1=0;
	caux2=0;
	do
	{
		gotoxy(8+caux2,68+caux1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("*");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		caux1++;
		caux2++;
		caux2++;
		caux2++;
		//caux2++;
		//caux2++;
	}
	while(caux1<26);
	
	//Ecuación de la oferta
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	char a='*';
	caux1=25; //Primer punto
	caux2=10;
	caux3=0;
	do
	{
		if(bo[0]>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(8,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Segundo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*difx)+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(13,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Tercer punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*2))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(18,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Cuarto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*3))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(23,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Quinto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*4))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(28,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Sexto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*5))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(33,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Septimo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*6))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(38,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Octavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*7))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(43,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Noveno punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*8))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(48,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Decimo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*9))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(53,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Onceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*10))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(58,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Doceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*11))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(63,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Treceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*12))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(68,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Catorceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*13))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(73,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Quinceavo punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*14))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(78,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	
	caux1=25; //Decimosexto punto
	caux2=10;
	caux3=0;
	do
	{
		if(((ao[0]*(difx*15))+bo[0])>=intsy[caux1])
		{
			caux1--;
		}
		else
		{
			caux2=0;
		}
	}
	while(caux2!=0);
	gotoxy(83,68+caux1+1);
	if(caux1>=0&&caux1<=25)
	{
		printf("%c",a);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	if(menu==1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		ao[0]=ad[0];
		bo[0]=bd[1];
		a='*';
		caux1=25; //Primer punto
		caux2=10;
		caux3=0;
		do
		{
			if(bo[0]>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(8,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Segundo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*difx)+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(13,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Tercer punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*2))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(18,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Cuarto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*3))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(23,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Quinto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*4))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(28,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Sexto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*5))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(33,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Septimo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*6))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(38,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Octavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*7))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(43,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Noveno punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*8))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(48,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Decimo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*9))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(53,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Onceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*10))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(58,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Doceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*11))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(63,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Treceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*12))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(68,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Catorceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*13))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(73,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Quinceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*14))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(78,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Decimosexto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*15))+bo[0])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(83,68+caux1+1);
		if(caux1>0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=0;
		caux2=0;
		do
		{
			gotoxy(8+caux2,94);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("_____");
			//gotoxy(8+caux2,95);
			//printf("%.1f",otrox);
			caux1++;
			otrox=(caux1*difx);
			caux2++;
			caux2++;
			caux2++;
			caux2++;
			caux2++;
		}
		while(caux2<(16*5));
		
		caux1=0;
		caux2=0;
		do
		{
			gotoxy(12+caux2,(94-25));
			printf("     ");
			//gotoxy(8+caux2,95);
			//printf("%.1f",otrox);
			caux1++;
			otrox=(caux1*difx);
			caux2++;
			caux2++;
			caux2++;
			caux2++;
			caux2++;
		}
		while(caux2<(16*5));
	}
	if(menu==2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		caux1=25; //Primer punto
		caux2=10;
		caux3=0;
		bo[1]=bd[1];
		do
		{
			if(bo[1]>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(8,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Segundo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*difx)+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(13,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Tercer punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*2))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(18,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Cuarto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*3))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(23,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Quinto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*4))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(28,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Sexto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*5))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(33,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Septimo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*6))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(38,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Octavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*7))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(43,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Noveno punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*8))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(48,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Decimo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*9))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(53,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Onceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*10))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(58,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Doceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*11))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(63,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Treceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*12))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(68,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Catorceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*13))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(73,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Quinceavo punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*14))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(78,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
		
		caux1=25; //Decimosexto punto
		caux2=10;
		caux3=0;
		do
		{
			if(((ao[0]*(difx*15))+bo[1])>=intsy[caux1])
			{
				caux1--;
			}
			else
			{
				caux2=0;
			}
		}
		while(caux2!=0);
		gotoxy(83,68+caux1+1);
		if(caux1>=0&&caux1<=25)
		{
			printf("%c",a);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}






void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
