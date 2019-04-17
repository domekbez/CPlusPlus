#pragma once
#include <iostream>
using namespace std;
#include <windows.h>

class element
{
	char z = '*';
	int color;	//reprezentuje kolor 
public:
	element(int kolor=0) :color(kolor) {}

	friend ostream& operator<<(ostream& out, const element& el)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), el.color);	//ustawia kolor do wypisania znaku
		out << el.z;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//powr�t do warto�ci domy�lnych konsoli
		return out;
	}

	// uzupe�nij brakuj�ce elementy klasy - ETAP 4





};



