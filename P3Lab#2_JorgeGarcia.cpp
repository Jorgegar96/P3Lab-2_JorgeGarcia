#include <iostream>;

using namesoace std;

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
}

int menuEjercicio2();

int menuEjercicio3();

//Ejercicio de los numeros triangulares y sus prototipos de funciones
void ejercicio1();

void comprobarTriangular(int);

void triangularMasCercano(int);

int main(){
	bool salir = false;
	while(!salir){
		switch (menuPrincipal()){
			case 1:
				ejercicio1();
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
		switch (menuEjercicio1){
			case 1:
				cout<<"Ingrese un numero";
				cin>>numero;
				comprobarTriangular(numero);		
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
}

void comprobarTrinagular(int numero)
	int suma_triangular = 0;
	for (int i=1; i <= numero; i++){
		suma_triangular =+ i;
		if (suma_triangular == numero){
			cout<<"El numero es triangular"<<endl;
		}else if(i == numero){
			cout<<"El numero no es triangular"<<endl;
		}
	}
}
