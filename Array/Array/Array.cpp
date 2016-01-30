// Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
int *numeros;

	void inicio(){
		numeros = new int[5];
		for (int i = 0; i < 5; i++)
			numeros[i] = i;
	}

	void buscar(int n){
		for (int i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++){
			if (numeros[i] == n){
				cout << "Valor encontrado" << endl;
				cout << "" << endl;
			}
		}
	}

	void agregar(int num){
		int* temp = new int[6];
		std::copy(numeros, numeros + num, temp);
		delete[] numeros;
		numeros = temp;
	}

	void eliminar(int a){

	}

	void print(){
		for (int a = 0; a < sizeof(numeros) / sizeof(numeros[0]); a++){
			cout << numeros[a] << endl;
		}
	}

int main()
{
	inicio();
	buscar(5);
	eliminar(7);
	print();
	return 0;
}

