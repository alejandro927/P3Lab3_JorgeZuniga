#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu() {
	int opcion=0;
	cout<<"\nLas opciones son:\n";
	cout<<"1)Ejercicio1\n";
	cout<<"2)Ejercicio2\n";
	cout<<"3)Ejercicio3\n";
	cout<<"4)salida salida\n";
	cout<<"Elija su opcion:\n";
	cin>>opcion;
	cout<<endl;
	return opcion;
}

void ImprimirArr(char* arreglo, int size) {
	cout<<"[";
	for(int i=0; i<size; i++) {
		cout<<"'"<< arreglo[i] <<"' ,";
	}
	cout<<"]";
}

void Im(int* arreglo, int size) {
	for(int i=0; i<size; i++) {
		cout<<arreglo[i]<<" ";
	}
}

void Ejercicio1(char* arreglo,int size) {

	int repeticiones [size];
	char caracteres [size];

	int contadorRepeticiones=0;
	int contadorCaracter=0;

	for(int i=0; i<size; i++) {
		cout<<"Ingrese el caracter:";
		cin>> arreglo[i];
		repeticiones[i]=0;
	}
	for(int i=0; i<size; i++) {
		if( (arreglo[i]>=48) && (arreglo[i]<=57) ) { //i=0 i=1
			if( (arreglo[i+1]>=48) && (arreglo[i+1]<=57) ) { //i=1 i=2
				int val = arreglo[i] - 48;
				repeticiones[contadorRepeticiones] = ( repeticiones[contadorRepeticiones] * 10) + val;
				//cout<<"Siguiente num"<<repeticiones[contadorRepeticiones]<<endl;
			} else {
				int val = arreglo[i] - 48;
				repeticiones[contadorRepeticiones] = ( repeticiones[contadorRepeticiones] * 10) + val;
				contadorRepeticiones++;
			}
		} else {
			caracteres[contadorCaracter] = arreglo[i];
			contadorCaracter++;
		}
	}

	ImprimirArr(arreglo,size);

	cout<<endl<<endl;
	for(int i=0; i<size/2; i++) {
		int rep = 0;
		for(int j=0 ; j < repeticiones[i] ; j++) {
			cout<<" "<<caracteres[i];
		}
	}

	delete []arreglo;

}

void LlenarMat(char** matrix, int sizeA,int sizeB) {
	for(int i = 0; i<sizeA; i++) {
		for(int j=0; j<sizeB; j++) {
			matrix[i][j] ='-';
		}
	}
}

void ImprimirMat(char** matrix, int sizeA,int sizeB) {
	for(int i = 0; i<sizeA; i++) {
		cout<<"| ";
		for(int j=0; j<sizeB; j++) {
			cout<<"'"<<matrix[i][j]<<"' ";
		}
		cout<<"|";
		cout<<endl;
	}
}

char** Obstaculos(char** matriz,int obstaculos,int filas, int columnas) {
	int fil[obstaculos];
	int col[obstaculos];
	for(int i=0; i < obstaculos; i++) {
		int ran1 = rand() % filas;
		int ran2 = rand() % columnas;
		for(int i=0; i<obstaculos; i++) {
			while(matriz[ran1][ran2]=='#') {
				ran1 = rand() % filas;
				ran2 = rand() % columnas;
			}
			fil[i] = ran1;
			col[i] = ran2;
		}
		matriz[ran1][ran2]='#';
	}
	cout<<endl;
	return matriz;
}

char** Ejercicio2() {

	int filas,columnas;
	cout<<"Ingrese las filas:";
	cin>>filas;
	cout<<"Ingrese las columnas:";
	cin>>columnas;
	cout<<"Ingrese la cantidad de obstaculos:";
	int obstaculos=0;
	cin>>obstaculos;
	char** matriz = 0;
	matriz=new char*[filas];
	for(int i=0; i<filas; i++) {
		matriz[i] = new char[columnas];
	}

	LlenarMat(matriz,filas,columnas);
	//ImprimirMat(matriz,filas,columnas);

	Obstaculos(matriz,obstaculos,filas,columnas);

	cout<<"Matriz final"<<endl;
	ImprimirMat(matriz,filas,columnas);
	return matriz;
//limpiar memoria
	for(int i = 0; i<filas; i++) {
		if(matriz[i]) {
			delete[] matriz[i];
			matriz[i] = 0; //asignar null
		}

	}

	if( matriz != NULL ) {
		delete[] matriz;
		matriz = 0;
	}

	if(matriz) {
		delete[] matriz;
		matriz = 0;
	}
}

char** MatrizEjercicio3(char** matriz,int filas,int columnas,int obstaculos) {
	LlenarMat(matriz,filas,columnas);
	//ImprimirMat(matriz,filas,columnas);
	Obstaculos(matriz,obstaculos,filas,columnas);
	cout<<"Matriz final"<<endl;
	ImprimirMat(matriz,filas,columnas);
	return matriz;
}

void Juego(char** matriz, char* arreglo,int size,int filas,int columnas) {
	int contador=0;
	while(contador<size) {
		for(int i=0; i<filas; i++) {
			for(int j=0; j<columnas; j++) {
				if(contador == 0) {
					switch(arreglo[i]) {
						//UDLR
						case 'U': {
							matriz[i][j] = 186;
						}
						break;
						case 'D': {
							matriz[i][j] = 186;
						}
						break;
						case 'L': {
							matriz[i][j] = 205;
						}
						break;
						case 'R': {
							matriz[i][j] = 205;
						}
						break;
					}
				} else {
					switch(arreglo[i]) {
						//UDLR
						case 'U': {
							matriz[i][j] = 186;
						}
						break;
						case 'D': {
							matriz[i][j] = 186;
						}
						break;
						case 'L': {
							matriz[i][j] = 205;
						}
						break;
						case 'R': {
							matriz[i][j] = 205;
						}
						break;
					}
				}
			}
		}




	}

}

void Ejercicio3() {
	int size=0;
	cout<<"Ingrese el tamano del arreglo:";
	cin>>size;
	char* arreglo = new char[size];
	Ejercicio1(arreglo,size);
	cout<<endl;


	int filas,columnas;
	cout<<"Ingrese las filas:";
	cin>>filas;
	cout<<"Ingrese las columnas:";
	cin>>columnas;
	cout<<"Ingrese la cantidad de obstaculos:";
	int obstaculos=0;
	cin>>obstaculos;

	char** matriz = 0;
	matriz=new char*[filas];
	for(int i=0; i<filas; i++) {
		matriz[i] = new char[columnas];
	}


	MatrizEjercicio3(matriz,filas,columnas,obstaculos);
	Juego(matriz,arreglo,size,filas,columnas);
	
	ImprimirMat(matriz,filas,columnas);
	

	//limpiar memoria
	for(int i = 0; i<filas; i++) {
		if(matriz[i]) {
			delete[] matriz[i];
			matriz[i] = 0; //asignar null
		}
	}

	if( matriz != NULL ) {
		delete[] matriz;
		matriz = 0;
	}

	if(matriz) {
		delete[] matriz;
		matriz = 0;
	}


}

int main(int argc, char** argv) {
	srand(time(NULL));
	int opcion=0;
	bool respuesta;
	respuesta=true;
	while(respuesta==true) {
		opcion = menu();
		switch(opcion) {
			case 1: {
				int size=0;
				cout<<"Ingrese el tamano del arreglo:";
				cin>>size;
				char* arreglo = new char[size];
				Ejercicio1(arreglo,size);
			}
			break;
			case 2: {
				Ejercicio2();
			}
			break;
			case 3: {
				Ejercicio3();
			}
			break;
			case 4: {
				respuesta = false;
				break;
			}
		}
	}
	return 0;
}