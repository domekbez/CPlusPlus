#pragma once

#include <iostream>
using namespace std;
#include <cmath>


//------------------------------------------------

// zaimplementuj generuj_wielomian - ETAP 2
template <class T>
Function<T>* generuj_wielomian(T tablica[], int n)
{
	Function<T>* pom = new FSub<T>(new FIdent<T>, new FConst<T>(tablica[0]));
	for (int i = 1; i < n; i++)
	{
		pom = new FProd<T>(new FSub<T>(new FIdent<T>(), new FConst<T>(tablica[i])),pom);
		
	}
	return pom;
}
// zaimplementuj pierwiastek - ETAP 3

template <class T>
T pierwiastek(Function<T>* f, T a, int& licznik)
{
	double eps = 1e-3;
	int max_it = 100;
	T n = a;
	T nast = 0;
	licznik = 0;
	while (abs(f->value(n)) > eps)
	{
		if (abs(f->prim(n)) < eps)
			throw "BRAK ZBIEZNOSCI";
		nast = n - (f->value(n) / f->prim(n));
		n = nast;
		licznik++;
		if (licznik > max_it)
			throw "BRAK ZBIEZNOSCI";
	}
	return nast;
}




