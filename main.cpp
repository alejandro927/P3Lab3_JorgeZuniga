#include <iostream>
#include <random>
#include <ctime>
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

void Ejercicio1(){
	
}

void Ejercicio2(){
	
}

void Ejercicio3(){
	
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
				Ejercicio1();
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