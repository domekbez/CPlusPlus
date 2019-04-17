#include <iostream>
#include "Obrazek.h"
using namespace std;
Obrazek::Obrazek()
{
	wiersze=0;
	kolumny=0;
	dane = NULL;
}
Obrazek::Obrazek(int a, int b)
{
	wiersze=a;
	kolumny=b;
	dane=new(nothrow) char*[wiersze];
	if(!dane||a<0||b<0)
	{
		wiersze=0;
		kolumny=0;
		dane=NULL;
		return;
	}
	for(int i=0;i<wiersze;i++)
	{
		dane[i]=new(nothrow) char[kolumny];
		if(!dane[i])
		{
			wiersze=0;
			kolumny=0;
			dane=NULL;
			return;
		}
	}
	for(int k=0;k<wiersze;k++)
		for(int l=0;l<kolumny;l++)
			dane[k][l]=' ';
}
Obrazek::Obrazek(int a, int b, const char  * w)
{
	wiersze=a;
	kolumny=b;
	dane=new(nothrow) char*[wiersze];
	if(!dane||a<0||b<0)
	{
		wiersze=0;
		kolumny=0;
		dane=NULL;
		return;
	}
	for(int i=0;i<wiersze;i++)
	{
		dane[i]=new(nothrow) char[kolumny];
		if(!dane[i])
		{
			wiersze=0;
			kolumny=0;
			dane=NULL;
			return;
		}
	}
	for(int k=0;k<wiersze;k++)
		for(int l=0;l<kolumny;l++)
			dane[k][l]=w[k*kolumny+l];
}
Obrazek::~Obrazek()
{
	for(int i=0;i<wiersze;i++)
		delete [] dane[i];
	delete [] dane;
}
void Obrazek::UstawZnak(const char& z)
{
	for(int i=0; i<wiersze; i++)
		for(int j=0; j<kolumny; j++)
			dane[i][j]=z;
}
ostream& operator<<(ostream& out, const Obrazek& o)
{
	if(!o.dane)
	{
		out << "Nieudana alokacja pamieci" << endl;
			return out;
	}
	for(int i=0; i<o.wiersze; i++)
	{
		for(int j=0;j<o.kolumny;j++)
		{
			out << o.dane[i][j];
		}
		out << endl;
	}
	out << endl;
	return out;
}
//2 Etap:
Obrazek::Obrazek(const Obrazek& o)
{
	wiersze=o.wiersze;
	kolumny=o.kolumny;
	dane=new(nothrow) char*[wiersze];
	if(!dane)
	{
		wiersze=0;
		kolumny=0;
		dane=NULL;
		return;
	}
	for(int i=0;i<wiersze;i++)
	{
		dane[i]=new(nothrow) char[kolumny];
		if(!dane[i])
		{
			wiersze=0;
			kolumny=0;
			dane=NULL;
			return;
		}
	}
	for(int k=0;k<wiersze;k++)
		for(int l=0;l<kolumny;l++)
			dane[k][l]=o.dane[k][l];
}
Obrazek& Obrazek::operator=(const Obrazek& o)
{
	if(this==&o)
	{
		return *this;
	}
	for(int i=0;i<wiersze;i++)
		delete [] dane[i];
	delete [] dane;
	wiersze=o.wiersze;
	kolumny=o.kolumny;
	dane=new(nothrow) char*[wiersze];
	if(!dane)
	{
		wiersze=0;
		kolumny=0;
		dane=NULL;
		return *this;
	}
	for(int i=0;i<wiersze;i++)
	{
		dane[i]=new(nothrow) char[kolumny];
		if(!dane[i])
		{
			wiersze=0;
			kolumny=0;
			dane=NULL;
			return *this;
		}
	}
	for(int k=0;k<wiersze;k++)
		for(int l=0;l<kolumny;l++)
			dane[k][l]=o.dane[k][l];
	return *this;
}
istream& operator>>(istream& in, Obrazek& o)
{
	char m;
	cout << "Ile wierszy: ";
	in >> o.wiersze;
	cout << "Ile kolumny: ";
	in >> o.kolumny;
	cout << "Jaki znak: ";
	in >> m;
	for(int i=0;i<o.wiersze;i++)
		delete [] o.dane[i];
	delete [] o.dane;
	o.dane=new(nothrow) char*[o.wiersze];
	if(!o.dane)
	{
		o.wiersze=0;
		o.kolumny=0;
		o.dane=NULL;
		return in;
	}
	for(int i=0;i<o.wiersze;i++)
	{
		o.dane[i]=new(nothrow) char[o.kolumny];
		if(!o.dane[i])
		{
			o.wiersze=0;
			o.kolumny=0;
			o.dane=NULL;
			return in;
		}
	}
	for(int k=0;k<o.wiersze;k++)
		for(int l=0;l<o.kolumny;l++)
			o.dane[k][l]=m;
	return in;
}
void Obrazek::ZwrocRozmiar(int & w, int & k) const
{
	w=wiersze;
	k=kolumny;
	
}
char& Obrazek::operator()(int i, int j)
{
	return dane[i][j];
}
const char& Obrazek::operator()(int i, int j) const
{
	return dane[i][j];
}
char& Obrazek::operator[](int i)
{

	return dane[i/kolumny][i%kolumny];

}

const char& Obrazek::operator[](int i) const
{

	return dane[i/kolumny][i%kolumny];

}
Obrazek& Obrazek::Odbij()
{
	char pom;
	for(int i=0;i<wiersze;i++)
		for(int j=0;j<kolumny/2;j++)
		{
			pom=dane[i][j];
			dane[i][j]=dane[i][kolumny-j-1];
			dane[i][kolumny-j-1]=pom;
		}
	return *this;
}
Obrazek& Obrazek::ObrocWLewo()
{
	Obrazek pom;
	int s;
	pom=(*this);
	dane=new(nothrow) char*[kolumny];
	if(!dane)
	{
		wiersze=0;
		kolumny=0;
		dane=NULL;
		return *this;
	}
	for(int i=0;i<kolumny;i++)
	{
		dane[i]=new(nothrow) char[wiersze];
		if(!dane[i])
		{
			wiersze=0;
			kolumny=0;
			dane=NULL;
			return *this;
		}
	}
	for (int i=0; i<wiersze; i++)
		for(int j=0;j<kolumny;j++)
		{
			dane[kolumny-1-j][i]=pom.dane[i][j];
		}
	s=wiersze;
	wiersze=kolumny;
	kolumny=s;
	return *this;
}