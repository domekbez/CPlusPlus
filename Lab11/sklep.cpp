#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include "sklep.h"
using namespace std;

class Drogie
{
	double cena;
public:
	Drogie(double a) :cena(a) {}
	bool operator()(Alkohol* a)
	{
		return a->cena > cena;
	}

};
class Tanie
{
	double cena;
public:
	Tanie(double a) :cena(a) {}
	bool operator()(Alkohol* a)
	{
		return a->cena <= cena;
	}

};

void Zapasy::dodaj_do_zapasow(Alkohol* a)
{
	zapasy.push_back(a);
}
double Zapasy::wartosc_zapasow()
{
	double suma = 0;
	list<Alkohol*>::iterator it;
	for (it = zapasy.begin(); it != zapasy.end(); it++)
	{
		suma += (*it)->pobierz_cene();
	}
	return suma;

}
ostream& operator<<(ostream& out, const Zapasy& s)
{
	list<Alkohol*>::const_iterator it;
	int i = 1;
	if (s.zapasy.empty())
		out << "Lista jest pusta" << endl;
	else
		for (it = s.zapasy.begin(); it != s.zapasy.end(); it++, i++)
		{
			out << i << ". " << **it << endl;
		}
	return out;
}
Alkohol* Zapasy::sprzedaj()
{
	int n = zapasy.size();
	int a = rand() % n;
	list<Alkohol*>::iterator it = zapasy.begin();
	advance(it, a);
	Alkohol* b = *it;
	zapasy.erase(it);
	return b;
}
void Zapasy::wczytaj(const char* naz)
{
	fstream plik(naz, ios::in | ios::binary);
	if (!plik)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}

	char nazwa[100];
	double cena;
	int rok;
	int rodzaj;
	while (!plik.eof())
	{
		plik.read((char*)nazwa, 100);
		plik.read((char*)&cena, sizeof(double));
		plik.read((char*)&rok, sizeof(int));
		plik.read((char*)&rodzaj, sizeof(int));
		if (!plik.eof())
		{
			Alkohol* a = new Wino(nazwa, cena, rok, rodzaje_win(rodzaj));
			zapasy.push_back(a);
		}
	}
}
list<Alkohol*> Zapasy::usun_duplikaty()
{
	list<Alkohol*>::iterator it1 = zapasy.begin();
	list<Alkohol*>::iterator it2 = zapasy.begin();
	list<Alkohol*> lista;
	
	for (; it1 != zapasy.end(); it1++)
	{
		
		it2 = it1;
		it2++;
		for (; it2 !=zapasy.end(); it2++)
		{
			Wino* a = dynamic_cast<Wino*>(*it1);
			Wino* b = dynamic_cast<Wino*>(*it2);
			Piwo* c = dynamic_cast<Piwo*>(*it1);
			Piwo* d = dynamic_cast<Piwo*>(*it2);
			if ((!a&&b) || (a && !b))
				continue;
			else if (a && b && *a == *b)
			{
				lista.push_back(*it2);
				it2=zapasy.erase(it2);
				it2--;
			}
			else if (c && d && *c == *d)
			{
				lista.push_back(*it2);
				it2 = zapasy.erase(it2);
				it2--;
			}
		}
	}
	return lista;

}
list<Alkohol*> Zapasy::sprzedaj(double cena)
{
	list<Alkohol*> lista;
	lista = zapasy;
	zapasy.remove_if(Drogie(cena));
	lista.remove_if(Tanie(cena));
	return lista;

}