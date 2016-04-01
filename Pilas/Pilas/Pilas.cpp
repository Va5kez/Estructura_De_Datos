// Pilas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


class Letters{
public:
	char valor;
	Letters* sig;
	Letters* ante;
	Letters(char letter){
		valor = letter;
	}
};

Letters* tail = NULL;

Letters* popPila(){
	if (tail != NULL){
		Letters* temp = tail;
		tail = tail->ante;
		return temp;
	}
	else{
		return NULL;
	}
}
void pushPila(char valor){
	if (tail != NULL){
		Letters *temp = new Letters(valor);
		temp->ante = tail;
		tail = temp;

	}
	else{
		tail = new Letters(valor);
	}

}
Letters* verPila(){
	if (tail == NULL){
		return NULL;
	}
	else{

		return tail;
	}
}

void menu(){
	bool exit = false;
	int opc;
	cout << "Escoja una opcion" << endl <<
		"1. Pilas" << endl <<
		"2. Salir" << endl;
	cin >> opc;
	if (opc == 1){
		while (exit == false){
			cout << "Ingrese una opcion" << endl <<
				"1. Ver Pila" << endl <<
				"2. Pop" << endl <<
				"3. Push" << endl <<
				"4. Exit" << endl;
			cin >> opc;
			if (opc == 1){
				Letters* find = verPila();
				if (find != NULL){
					cout << find->valor << endl;
				}
				else{
					cout << "Pila Vacia" << endl;
				}
			}
			else if (opc == 2){
				Letters* find = popPila();
				if (find != NULL){
					cout << "Se le a hecho Pop a : " << find->valor << endl;
				}
				else{
					cout << "Pila Vacia" << endl;
				}
			}
			else if (opc == 3){
				cout << "Ingrese un caracter" << endl;
				char j;
				cin >> j;
				pushPila(j);
			}
			else if (opc == 4){
				exit = true;
			}
			else{
				cout << "opcion no valida" << endl;
			}
		}
	}
}


int main(int argc, char *argv[])
{
	menu();
	return -1;
}