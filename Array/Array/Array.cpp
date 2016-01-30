// Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int buscar(int valor, int arreglo[], int tam){
	for (int i = 0; i < tam; i++){
		if (arreglo[i] == valor){
			return i;
		}
	}
	return -1;
}
void agregar(int arreglo[], int valor, int tam){
	int a = buscar(-1, arreglo, tam);
	if (a != -1)
		arreglo[a] = valor;
}

void insertar(int arreglo[], int valor, int pos, int tam){
	int a = arreglo[pos];
	int b;
	arreglo[pos] = valor;
	while (pos<tam){
		b = arreglo[pos + 1];
		arreglo[pos + 1] = a;
		a = b;
		pos++;
	}
}

void borrar(int valor, int arreglo[], int tam){
	int d = buscar(valor, arreglo, tam);
	if (d != -1){
		arreglo[d] = -1;
	}
}

void printArreglo(int arreglo[], int tam){
	for (int x = 0; x < tam; x++){
		cout << arreglo[x] << endl;
	}
}



int main()
{
	cout << "Empesando Codigo :v" << endl;
	cout << "" << endl;

	int arreglo[5] = {1,2,3,4,5};
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	agregar(arreglo, 45, tam);
	borrar(5, arreglo, tam);
	insertar(arreglo, 19, 3, tam);
	printArreglo(arreglo, tam);
	cout << "" << endl;
	cout << "Terminando codigo :,(" << endl;
	return 0;
}

