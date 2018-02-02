#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int menuPrincipal(){
	int opcion;
	cout<<"Menu: " << endl
	    <<"1) Ejercicio 1"   <<endl
	    <<"2) Ejercicio 2"   <<endl
	    <<"3) Ejercicio 3"   <<endl
	    <<"4) Salir"	 <<endl
	    <<"--------------- " <<endl
	;
	cin >> opcion;
	return opcion;
}

int menuEjercicio1(){
	int opcion;
	cout<<"Ejercicio 1: " << endl
	    <<"1)Compromar numero ingresado"	   <<endl
	    <<"2)Comprobar numero al azar"	   <<endl
	    <<"3)Comprobar triangular mas cercano" <<endl
	    <<"4)Salir"				   <<endl
	    <<"----------------------------------" <<endl
	;
	cin >> opcion;
	return opcion;
}

int menuEjercicio2();

int menuEjercicio3();

//Ejercicio de los numeros triangulares y sus prototipos de funciones
void Ejercicio1();

void comprobarTriangular(int);

void triangularMasCercano(int);

int main(){
	bool salir = false;
	while(!salir){
		switch (menuPrincipal()){
			case 1:
				Ejercicio1();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				salir = true;
				break;
			default:
				cout<<"Opcion no valida, porfavor ingrese otro numero"<<endl;
		}
	}
	return 0;	
}

void Ejercicio1(){
	bool salir = false;
	int numero = 0;
	while(!salir){
		switch (menuEjercicio1()){
			case 1:
				cout<<"Ingrese un numero"<<endl;
				cin>>numero;
				comprobarTriangular(numero);		
				break;
			case 2:
				srand (time(NULL));
				numero = rand() % 5 + 1;
				cout<<"El numero al azar es: "<<numero<<endl;
				comprobarTriangular(numero);
				break;
			case 3:
				cout<<"Ingrese un numero"<<endl;
				cin>>numero;
				triangularMasCercano(numero);
				break;
			case 4:
				salir = true;
				break;
			default:
				cout<<"Opcion no valida, porfavor ingrese otro numero"<<endl;
		}
	}	
}

void comprobarTriangular(int numero){
	int suma_triangular = 0;
	for (int i=1; i <= numero; i++){
		suma_triangular += i;
		if (suma_triangular == numero){
			cout<<"El numero es triangular"<<endl;
			break;
		}else if(i == numero){
			cout<<"El numero no es triangular"<<endl;
		}
	}
}

void triangularMasCercano(int numero){
	int suma_triangular = 0;
	int triangular = 1;
	for (int i=1; i <= numero; i++){
		suma_triangular += i;
		if (suma_triangular > numero){
			break;
		}else {
			triangular = suma_triangular;
		}
	}
	cout<<"El numero triangular mas cercano al ingresado que no lo supere es: "<<triangular<<endl;
}
