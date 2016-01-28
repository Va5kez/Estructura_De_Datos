// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	list<int> *cartas = new list<int>();
	cartas->push_back(1);
	cartas->push_back(3);
	cartas->push_back(4);
	cartas->push_back(6);
	cartas->push_back(5);
	cartas->push_back(8);
	cartas->push_back(1);
	cartas->push_back(5);
	cartas->push_back(10);
	cartas->push_back(8);

	list<int>::iterator i;
	cout <<"Lista sin eliminacion de repetidos "<< endl;
	for (i = cartas->begin(); i != cartas->end(); ++i)
		cout << *i << " ";
	cout << endl;

	set<int> tem;
	for (list<int>::iterator x = cartas->begin(); x != cartas->end();) {
		if (!tem.insert(*x).second) {
			x = cartas->erase(x);
		}
		else {
			++x;
		}
	}

	cout << "Lista eliminando los repetidos" << endl;
	for (i = cartas->begin(); i != cartas->end(); ++i)
		cout << *i << " ";
	cout << endl;
	return 0;
}

