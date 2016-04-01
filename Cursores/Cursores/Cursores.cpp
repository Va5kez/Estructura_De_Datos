// Cursores.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Numeros{
public:
	int valor;
	int next = -1;
};

Numeros num[10];
int disponible = 0;

void inicializarcursor(){
	for (int i = 0; i <9; i++)
		num[i].next = i+1;
	num[9].next = -1;
}

int crear(Numeros num1){
	int tem = disponible;
	disponible = num[disponible].next;
	num[tem] = num1;
	return tem;
}

Numeros buscar(int a, int Lista){
	while (Lista != -1 && num[Lista].valor != a){
		Lista = num[Lista].next;
	}
	if (Lista == -1){
		cout << "La lista no existe" << endl;
		return *new Numeros;
	}
	else{
		return num[Lista];
	}
}

Numeros buscarAnterior(int a, int lista)
{
	int tem = -1;
	while (lista != -1 && num[lista].valor != a)
	{
		tem = lista;
		lista = num[lista].next;
	}
	if (lista != -1)
	{
		return num[tem];
	}
}

void eliminar(int pos, int lista){
	if (pos<0 || pos>9){
		cout << "posicion fuera del arreglo \n" << endl;
	}
	else{
		num[pos].valor = NULL;
		num[pos].next = pos + disponible;
		disponible = pos;
	}
}

void agregar(Numeros numero, int Lista){
	while (num[Lista].next!=-1){
		Lista = num[Lista].next;
	}
	int tem = disponible;
	num[Lista].next = tem;
	disponible = num[disponible].next;
	num[tem] = numero;
}

void print(){
	for (int i = 0; i < 10; i++){
		cout << "Posicion: " << i <<"  Valor: " << num[i].valor << "  Next: " << num[i].next << endl;
	}
	cout << "Disponible: " << disponible << "\n" << endl;
}

int main()
{
	inicializarcursor();
	Numeros uno, dos, tres, cuatro, cinco, seis;
	uno.valor = 1; dos.valor = 2; tres.valor = 3; cuatro.valor = 4, cinco.valor = 5, seis.valor = 6;
	int lista = crear(uno);
	int lista2 = crear(dos);
	agregar(tres, lista); agregar(cuatro, lista2); agregar(cinco, lista); agregar(seis, lista2);
	print();
	eliminar(0,lista);
	print();
	return 0;
}

