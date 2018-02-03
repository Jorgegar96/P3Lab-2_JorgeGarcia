#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265

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


//Ejercicio de los triangulos con sus angulos y areas
void Ejercicio2();

bool comprobacionTriangulo(float, float, float);

void calcularArea(float, float, float);

void calcularAngulos(float, float, float);


//Ejercicio de los numeros de catalan
void Ejercicio3();

int generacionCatalan(int, int, int, int, int, int, int);

int main(){
	bool salir = false;
	while(!salir){
		switch (menuPrincipal()){
			case 1:
				Ejercicio1();
				break;
			case 2:
				Ejercicio2();
				break;
			case 3:
				Ejercicio3();
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

void Ejercicio3(){
	int numero = -1;
	while (numero < 1){
		cout<<"Ingrese la cantidad de numeros de la serie Catalan que desea mostrar";
		cin>>numero;
	}
	generacionCatalan(0,1,1,numero,1,0,0);

}

int generacionCatalan(int num1, int num2, int guardado1, int lim, int fila, int guardado2, int ciclo){
	if (ciclo == lim){
		guardado1 = num1 + num2;
		
		return 0;
	} else {
		if (fila%2 == 1){
			cout<<guardado1<<" ";
			generacionCatalan(num1, num2, num1+num2, 2, 1, guardado2, ciclo);	

		} else{
			generacionCatalan(guardado1,num1,num1+num2,lim,fila+1,guardado2, ciclo+1);
			
		}
	}	
}
void Ejercicio2(){
	float lado1 = 0;
	float lado2 = 0;
	float lado3 = 0;
	for (int i=1; i < 4; i++){
		cout<<"Ingrese la medida del lado numero "<<i<<":"<<endl;
		switch (i){
			case 1:
				cin>>lado1;
				break;
			case 2:
				cin>>lado2;
				break;
			case 3:
				cin>>lado3;
				if (!comprobacionTriangulo(lado1,lado2,lado3)){
					i = 0;
					cout<<"Las medidas no pueden formar un triangulo, porfavor ingrese otras"<<endl;
				}
				break;
		}	
	}
	calcularArea(lado1, lado2, lado3);
	calcularAngulos(lado1, lado2, lado3);
}

bool comprobacionTriangulo(float lado1, float lado2, float lado3){
	if (lado1 + lado2 > lado3 && 
	    lado1 + lado3 > lado2 &&
	    lado2 + lado3 > lado1){
		return true;
	}
	return false;
}

void calcularArea(float lado1, float lado2, float lado3){
	float semi_perimetro = (lado1+lado2+lado3)/2;
	float area = sqrt( semi_perimetro*(semi_perimetro-lado1)*(semi_perimetro-lado2)*(semi_perimetro-lado3) );
	cout<<"Area: "<<area<<"u^2"<<endl;
	//Calculo de altura de un triangulo
	float altura1 = 2*area/lado1;
	cout<<"Altura 1: "<<altura1<<endl;
	float altura2 = 2*area/lado2;
	cout<<"Altura 2: "<<altura2<<endl;
	float altura3 = 2*area/lado3;
	cout<<"Altura 3: "<<altura3<<endl;
}

void calcularAngulos(float lado1, float lado2, float lado3){
	//La formula despejada para encontrar los angulos reprsentada como el lado principal al cuadrado
	//menos la resta de los otros dos lados restantes (ya al cuadrado), todo eso entre 2 por la multiplicacion
	//de los dos lados restandes y negativo 1, por ultimo se utiliza el coseno inverso.
	float angulo1 = acos ( -1*((lado1*lado1)-((lado2*lado2)+(lado3*lado3)))/(2*lado2*lado3) );
	angulo1 = angulo1 * 180 / PI;
	float angulo2 = acos ( -1*((lado2*lado2)-((lado1*lado1)+(lado3*lado3)))/(2*lado1*lado3) );
	angulo2 = angulo2 * 180 / PI;
	float angulo3 = acos ( -1*((lado3*lado3)-((lado2*lado2)+(lado1*lado1)))/(2*lado2*lado1) );
	angulo3 = angulo3 * 180 / PI;
	cout<<"Angulo 1: "<<angulo1<<endl;
	cout<<"Angulo 2: "<<angulo2<<endl;
	cout<<"Angulo 3: "<<angulo3<<endl;
	if (angulo1 == 90 || angulo2 == 90 || angulo3 == 90){
		cout<<"El triangulo es recto!"<<endl;
	} else{
		cout<<"El triangulo no es recto"<<endl;
	}
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
