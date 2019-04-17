#include <iostream>
#include "kolor.h"
using namespace std;
// uzupe³nij plik implementacyjny klasy kolor
int Kolor::ilosc_C=0;
int Kolor::ilosc_M=0;
int Kolor::ilosc_Y=0;
int Kolor::ilosc_K=0;
Kolor::Kolor(int r, int g, int b)
{
	if(r>ZAKRES)
		cyan=0;
	else if(r<0)
		cyan=ZAKRES;
	else
		cyan=ZAKRES-r;
	if(g>ZAKRES)
		magenta=0;
	else if(g<0)
		magenta=ZAKRES;
	else
		magenta=ZAKRES-g;
	if(b>ZAKRES)
		yellow=0;
	else if(b<0)
		yellow=ZAKRES;
	else
		yellow=ZAKRES-b;
}
Kolor::Kolor(kolor_zdefiniowany k)
{
	if(k==RED)
	{
		cyan=0;
		magenta=ZAKRES;
		yellow=ZAKRES;
	}
	if(k==GREEN)
	{
		cyan=ZAKRES;
		magenta=0;
		yellow=ZAKRES;
	}
	if(k==BLUE)
	{
		cyan=ZAKRES;
		magenta=ZAKRES;
		yellow=0;
	}
	if(k==CYAN)
	{
		cyan=ZAKRES;
		magenta=0;
		yellow=0;
	}
	if(k==MAGENTA)
	{
		cyan=0;
		magenta=ZAKRES;
		yellow=0;
	}
	if(k==YELLOW)
	{
		cyan=0;
		magenta=0;
		yellow=ZAKRES;
	}
}
int Kolor::operator[](kolor_zdefiniowany k)
{
	int s;
	if(k==RED)
	{
		s=ZAKRES-cyan;
	}
	if(k==GREEN)
	{
		s=ZAKRES-magenta;
	}
	if(k==BLUE)
	{
		s=ZAKRES-yellow;
	}
	return s;

}
ostream& operator<<(ostream & out, const Kolor& k)
{
	Kolor m;
	m.cyan=k.cyan;
	m.magenta=k.magenta;
	m.yellow=k.yellow;
	out << "RGB: " << m[RED] << ", " << ", " << m[GREEN] << ", " << m[BLUE] << endl;
	return out;
}
istream& operator>>(istream & in, Kolor& k)
{
	int a,b,c,d;
	in >> hex >> a;
	b=a&0x0000ff;
	k.yellow=ZAKRES-b;
	c=a&0x00ff00;
	c>>=8;
	k.magenta=ZAKRES-c;
	d=a&0xff0000;
	d>>=16;
	k.cyan=ZAKRES-d;
	
	return in;
}
Kolor Kolor::operator-(Kolor & k)
{
	
	int red,green,blue,red2,green2,blue2,red3,green3,blue3;
	red=ZAKRES-k.cyan;
	green=ZAKRES-k.magenta;
	blue=ZAKRES-k.yellow;
	red2=ZAKRES-cyan;
	green2=ZAKRES-magenta;
	blue2=ZAKRES-yellow;
	if(red>=red2)
		red3=red-red2;
	else
		red3=ZAKRES;
	if(green>=green2)
		green3=green-green2;
	else
		green3=ZAKRES;
	if(blue>=blue2)
		blue3=blue-blue2;
	else
		blue3=ZAKRES;
	Kolor z(red3,green3,blue3);
	return z;
}
Kolor Kolor::operator-=(Kolor & k)
{
	Kolor z;
	z.cyan=cyan;
	z.magenta=magenta;
	z.yellow=yellow;
	z=z-k;
	return z;
}