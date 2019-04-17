#pragma once
#include <iostream>

using namespace std;

const int ZAKRES = 255;
const int ILOSC_KOLORU_DO_MALOWANIA = 1000;

enum kolor_zdefiniowany { CYAN, MAGENTA, YELLOW, BLACK, RED, GREEN, BLUE };

class Kolor {
private:
	int cyan;
	int magenta;
	int yellow;
	static int ilosc_C;
	static int ilosc_M;
	static int ilosc_Y;
	static int ilosc_K;

public:
	Kolor(int r=ZAKRES, int g=ZAKRES, int b=ZAKRES);
	Kolor(kolor_zdefiniowany);
	int operator[](kolor_zdefiniowany);
	friend ostream& operator<<(ostream & out, const Kolor& k);
	friend istream& operator>>(istream & in,Kolor& k);
	Kolor operator-(Kolor & k);
	Kolor operator-=(Kolor & k);

};