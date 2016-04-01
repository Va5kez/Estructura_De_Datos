// Colas.cpp : Defines the entry point for the console application.
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

Letters* head = NULL;
Letters* tail = NULL;

Letters* popCola(){
	if (head != NULL){
		Letters* temp = head;
		head = temp->sig;
		return temp;
	}
	else{
		return NULL;
	}
}

void pushCola(char valor){
	if (head == NULL){
		head = new Letters(valor);
		tail = head;
	}
	else{
		tail->sig = new Letters(valor);
		tail = tail->sig;
	}

}

Letters* verCola(){
	if (head == NULL){
		return NULL;
	}
	else{
		return head;
	}
}

void menu(){
	bool exit = false;
	int opc;
	bool colas;
	cout << "Iniciando" << endl <<
		"1. Colas" << endl <<
		"2. Salir" << endl;
	cin >> opc;
	if (opc == 1){
		while (exit == false){
			cout << "Ingrese una opcion" << endl <<
				"1. Mostrar Cola" << endl <<
				"2. Pop" << endl <<
				"3. Push" << endl <<
				"4. Exit" << endl;
			cin >> opc;
			if (opc == 1){
				Letters* find = verCola();
				if (find != NULL){
					cout << find->valor << endl;
				}
				else{
					cout << "Cola Vacia" << endl;
				}
			}

			else if (opc == 2){
				Letters* find = popCola();
				if (find != NULL){
					cout << "Se le dio Pop a : " << find->valor << endl;
				}
				else{
					cout << "Cola Vacia" << endl;
				}
			}

			else if (opc == 3){
				cout << "Ingrese un caracter" << endl;
				char j;
				cin >> j;
				pushCola(j);
			}
			else if (opc == 4){
				exit = true;
			}
		}
	}
}


int main(int argc, char *argv[])
{
	menu();
	return -1;
}

