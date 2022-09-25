#include <bits/stdc++.h>
using namespace std;//Necesario para los stings

//Base de datos
void basededatos(string nombre [], int clave[], float sueldo[]);

//Buscar por nombre
void buscarxnombre(string nombre [], int clave[], float sueldo[]);

//Buscar por clave
void buscarxclave(string nombre [], int clave[], float sueldo[]);

//Ordenar alfabeticamente
//void ordenarAlfa(string nombre [], int clave[], float sueldo[]); MEN ESTO ESTA EN FACE BETA NO LE HAGAS CASO

//Insertar nuevo 
void nuevoregistro(string nombre [], int clave[], float sueldo[]);

//Eliminar por nombre
void eliminarxnombre(string nombre [], int clave[], float sueldo[]);

//Eliminar por clave
void eliminarxclave(string nombre [], int clave[], float sueldo[]);

//Modificar por nombre
void modificarxnombre(string nombre [], int clave[], float sueldo[]);

//Modificar por clave
void modificarxclave(string nombre [], int clave[], float sueldo[]);

//Modificar por sueldo
void modificarxsueldo(string nombre [], int clave[], float sueldo[]);

int main(){

	//Generales
	setlocale(LC_ALL,"spanish");//Acentos y esas cosas
	srand((unsigned int)time(NULL)); //Semilla para los random
	int menu; //Menu
	int repetir; //Para el segundo menu
	bool flag2; //Para el segundo menu


	//Nombres aleatorios
	string nombre[10]; //Base de datos
	string nombres[10]={"César","Joul","Jose","Jimena","Gloria","Rosy","Angel","Pedro","Rick","Summer"};
	string apellido1[10]={"Perez","Sanchez","Cardona","Padilla","Lopez","Jaime","Lira","Alvarez","Becerra","Parker"};
	string apellido2[10]={"Guerra","Avila","Vaca","Montoya","Santos","Ponce","Martinez","Alonso","Cuello","Flores"};
	int n=0, a1=0, a2=0;
		
	//Clave de trabajador
	int clave[10]; //Base de datos
	int cl;
	
	//Sueldo del trabajador
	float sueldo[10]; //Base de datos
	float decimal=0, suma=0;
	int entero=0;
	//Llenado de base de datos
	
	for(int i=0;i<10;i++)
	{
		//Nombre
		
		n=1+rand()%(9);//Elige un nomre aleatorio
		a1=1+rand()%(9);//Elige un apellido aleatorio
		a2=1+rand()%(9);//Elige un apellido aleatorio
		nombre[i]=nombres[n]+" "+apellido1[a1]+" "+apellido2[a2]; //Composicion de todo el nombre
		
		//Clave
		
		cl=1000+rand()%(9000); //Elige un numero aleatorio de 4 cifras
		clave[i]=cl; 
		
		//Sueldo
		
		entero = ((int)rand())/3;
	    decimal = 1000+((float)rand())/(9000);
	    suma=entero+decimal;
	    sueldo[i]=suma;
	}
	bool flag = true;
		do
		{
			system("color 0f");
			system("cls");
			printf("     \t            Menu\n");
			printf("\n");
			printf("1- \tMostrar base de datos\n");
			printf("2- \tBuscar por nombre\n");
			printf("3- \tBuscar por clave\n");
			printf("4- \tOrdenar alfabeticamente\n");
			printf("5- \tInsertar nuevo\n");
			printf("6- \tEliminar por nombre\n");
			printf("7- \tEliminar por clave\n");
			printf("8- \tModificar por nombre\n");
			printf("9- \tModificar por clave\n");
			printf("10- \tModificar por sueldo\n");
			printf("11- \tSalir\n");
			printf("\n");
			printf("�Que quieres hacer?\n");
			scanf("%d",&menu);
			system("cls");
			switch(menu){
				case 1:{
					basededatos(nombre,clave,sueldo);
					break;
				}
				case 2:{
					buscarxnombre(nombre,clave,sueldo);
					break;
				}
				case 3:{
					buscarxclave(nombre,clave,sueldo);
					break;
				}
				/*case 4:{
					ordenarAlfa(nombre,clave,sueldo);
					break;
				}*/
				case 5:{
					nuevoregistro(nombre,clave,sueldo);
					break;
				}
				case 6:{
					eliminarxnombre(nombre,clave,sueldo);
					break;
				}
				case 7:{
					eliminarxclave(nombre,clave,sueldo);
					break;
				}
				case 8:{
					modificarxnombre(nombre,clave,sueldo);
					break;
				}
				case 9:{
					modificarxclave(nombre,clave,sueldo);
					break;
				}
				case 10:{
					modificarxsueldo(nombre,clave,sueldo);
					break;
				}
				case 11:{
					flag = false;
					break;
				}
				default:{
					printf("Opcion invalida\n");
					break;
				}
			}
			if (flag){
				printf("\n");
				printf("¿Quieres regresar al menu? |1-Si| |!=1-No| ");
				scanf("%d",&repetir);
				if (repetir==1){
					flag2=true;
				}
				else{
					flag2= false;
				}
				if(!flag2){
					break;
				}
			}
			else
			break;
	}while(true);
}




void basededatos(string nombre [], int clave[], float sueldo[]){
	printf("Nombre del trabajador\tID\tSalario\n");
	for (int i = 0;i<10;i++){
		printf("%s\t%d\t%f\n",nombre[i].c_str(),clave[i],sueldo[i]);
		//.c_str() es necesario para poder imprimir el string, lo concierte en char para poder imprimirlo de otra manera causa errores
	}	
}

void buscarxnombre(string nombre [], int clave[], float sueldo[]){
	char buscador[50];
	bool flag = true;
	printf("Introduce el nombre que deseas buscar(Respeta mayusculas, minisculas, espacios y signos de puntuacion):\n");
	fflush(stdin);//Limpia de buffer, añadido para evitar errores
	gets(buscador);
	string flagnombre = buscador;
	for(int i=0;i<10;i++)
	{
		if(!flagnombre.compare(nombre[i])){
			printf("Se encontro un registro \n");
			//Sintaxis para comparar strings con funcion "Compare"
			printf("%s\t%d\t%f\n",nombre[i].c_str(),clave[i],sueldo[i]);
			flag = false;
		}
	}
	printf("\n");
	if(flag){
		printf("No se encontro ningun registro");
	}
	
}

void buscarxclave(string nombre [], int clave[], float sueldo[]){
    int claveb;
    bool flag = true;
	printf("Introduce la clave de trabajador que deseas buscar:\n");
	scanf("%d",&claveb);
	for(int i=0;i<10;i++)
	{
		if(claveb==clave[i]){
			printf("Se encontro un registro \n");
			printf("%s\t%d\t%f\n",nombre[i].c_str(),clave[i],sueldo[i]);
		flag = false;
		}
	}
	printf("\n");
	if(flag){
		printf("No se encontro ningun registro");
	}
	
}

/*
void ordenarAlfa(string nombre [], int clave[], float sueldo[]){
	std::set<std::string> sortedItems;

	for (int i = 0;i<10;i++){
		sortedItems.insert(nombre[i]);
	}
	std::for_each(sortedItems.begin(), sortedItems.end(), &print);
	printf("\n");
}
*/ 

void nuevoregistro(string nombre [], int clave[], float sueldo[]){
	bool flag= false;
	int posicion;
	char x[50];
	for(int i=0;i<10;i++)
	{
		if(!nombre[i].compare("")){
			flag = true;
			posicion = i;
		}
	}
	if(flag){
		printf("Dame el nombre a guardar (Nombre Apellido Apellido): ");
		fflush(stdin);
		gets(x);
		nombre[posicion]=x;
		printf("Dame la clave a guardar (4 numeros): ");
		fflush(stdin);
		scanf("%d",&clave[posicion]);
		printf("Dame el sueldo a guardar (4 enteros y 4 decimales, SE DEBE USAR LA COMA PARA MARCAR EL PUNTO DECIMAL): ");
		scanf("%f",&sueldo[posicion]);
		printf("\nSe guardó el nuevo registro correctamente");
	}
	else
	{
		printf("La base de datos esta llena");
	}
	printf("\n");
}

void eliminarxnombre(string nombre [], int clave[], float sueldo[]){
	char nombree[50];
	bool flag = true;
	printf("Introduce el nombre que deseas eliminar(Respeta mayusculas, minisculas, espacios y signos de puntuacion):\n");
	fflush(stdin);
	gets(nombree);
	string nombree2 = nombree;
	for(int i=0;i<10;i++)
	{
		if(!nombree2.compare(nombre[i])){
			nombre[i] = "";
			clave[i] = 0;
			sueldo[i] = 0;
			flag = false;
			printf("El registro se elimino correctamente\n");
		}
	}
	if(flag){
		printf("No se encontro ningun registro");
	}
}

void eliminarxclave(string nombre [], int clave[], float sueldo[]){
	int clavee;
	bool flag = true;
	printf("Introduce la clave de trabajador que deseas eliminar:\n");
	scanf("%d",&clavee);
	for(int i=0;i<10;i++)
	{
		if(clavee==clave[i])
		{
			nombre[i] = "";
			clave[i] = 0;
			sueldo[i] = 0;
			flag = false;
			printf("El registro se elimino correctamente\n");
		}
	}
	if(flag){
		printf("No se encontro ningun registro");
	}
	
}

void modificarxnombre(string nombre [], int clave[], float sueldo[]){
	char nombrem[50], x[50];
	bool flag = true;
	printf("Introduce el nombre que deseas modificar(Respeta mayusculas, minisculas, espacios y signos de puntuacion):\n");
	fflush(stdin);
	gets(nombrem);
	string nombrem2 = nombrem;
	for(int i=0;i<10;i++)
	{
		if(!nombrem2.compare(nombre[i])){
			printf("Dame el nombre a guardar (Nombre Apellido Apellido): ");
			fflush(stdin);
			gets(x);
			nombre[i]=x;
			printf("Dame la clave a guardar (4 numeros): ");
			fflush(stdin);
			scanf("%d",&clave[i]);
			printf("Dame el sueldo a guardar (4 enteros y 4 decimales, SE DEBE USAR LA COMA PARA MARCAR EL PUNTO DECIMAL): ");
			scanf("%f",&sueldo[i]);
			flag = false;
			printf("\nEl registro de modifico correctamente");
		}
	}
	printf("\n");
	if(flag){
		printf("No se encontro ningun registro");
	}
}

void modificarxclave(string nombre [], int clave[], float sueldo[]){
	int clavee;
	bool flag = true;
	char x[50];
	printf("Introduce la clave de trabajador que deseas modificar:\n");
	scanf("%d",&clavee);
	for(int i=0;i<10;i++)
	{
		if(clavee==clave[i])
		{
			printf("Dame el nombre a guardar (Nombre Apellido Apellido): ");
			fflush(stdin);
			gets(x);
			nombre[i]=x;
			printf("Dame la clave a guardar (4 numeros): ");
			fflush(stdin);
			scanf("%d",&clave[i]);
			printf("Dame el sueldo a guardar (4 enteros y 4 decimales, SE DEBE USAR LA COMA PARA MARCAR EL PUNTO DECIMAL): ");
			scanf("%f",&sueldo[i]);
			flag = false;
			printf("\nEl registro de modifico correctamente");
		}
	}
	printf("\n");
	if(flag){
		printf("No se encontro ningun registro");
	}
}

void modificarxsueldo(string nombre [], int clave[], float sueldo[]){
	float sueldom;
	bool flag = true;
	char x[50];
	printf("Introduce el sueldo que deseas modificar:\n");
	scanf("%f",&sueldom);
	for(int i = 0;i<10;i++){
		if(sueldom==sueldo[i]){
			printf("Dame el nombre a guardar (Nombre Apellido Apellido): ");
			fflush(stdin);
			gets(x);
			nombre[i]=x;
			printf("Dame la clave a guardar (4 numeros): ");
			fflush(stdin);
			scanf("%d",&clave[i]);
			printf("Dame el sueldo a guardar (4 enteros y 4 decimales, SE DEBE USAR LA COMA PARA MARCAR EL PUNTO DECIMAL): ");
			scanf("%f",&sueldo[i]);
			flag = false;
			printf("\nEl registro de modifico correctamente");
		}
	}
	printf("\n");
	if(flag){
		printf("No se encontro ningun registro");
	}
}


