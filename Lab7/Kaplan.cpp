#include <iostream> 
using namespace std;
#include "Kaplan.h"
#include "Bron.h"

// klasa Kaplan
//

Kaplan::Kaplan(string imie) : imie(imie),punktyZycia(30),zrecznosc(5),sila(5),madrosc(5),ile_zaklec(0)
{
	sila_ataku = sila;
	poziom_ochrony = zrecznosc;
	bron_w_rece = nullptr;
	symbol_w_rece = nullptr;
	for (int i = 0; i < wielkosc_ekwipunku; i++)
		ekwipunek[i] = nullptr;
	ekwipunek[0] = new Bron("Miecz", "klasyczny miecz jednoreczny", 3);
	ekwipunek[1] = new SymbolWiary("Pierscien z granitem", "pierscien z symbolem zywiolu ziemi");
	ekwipunek[2] = new Bron("Sztylet", "sztylet krotki", 1);

	for (int i = 0; i < ilosc_zaklec; i++)
		znane_zaklecia[i] = nullptr;
	znane_zaklecia[0] = new ZaklecieOfensywne("Lodawa strzala", 2, 5);
	znane_zaklecia[1] = new ZaklecieDefensywne("Leczniczy dotyk", 1, 4);
	znane_zaklecia[2] = new ZaklecieOfensywne("Widmowe Ostrza", 1, 2);
	znane_zaklecia[3] = new ZaklecieOfensywne("Ognisty deszcz", 7, 10);
}
Kaplan::~Kaplan()
{
	for (int i=0;i<wielkosc_ekwipunku;i++)
		delete ekwipunek[i];
	for (int i=0;i<ilosc_zaklec;i++)
		delete znane_zaklecia[i];
	delete bron_w_rece;
	delete symbol_w_rece;

}
//
void Kaplan::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

ostream& operator<<(ostream& out, const Kaplan& p)
{
	out << p.imie << " - calkowita sila ataku: " << p.sila_ataku << " calkowity poziom ochrony: " << p.poziom_ochrony << " punkty zycia: " << p.punktyZycia << " liczba zaklec: " << p.ile_zaklec << endl;
	for (int i = 0; i < p.wielkosc_ekwipunku; i++)
	{
		if (p.ekwipunek[i])
			out << i+1 << ". " << *p.ekwipunek[i];
		else
			out << i+1 << ". " << "pusto" << endl;
	}
	return out;
}
int Kaplan::znajdz_zaklecie_ofensywne() const
{
	ZaklecieOfensywne* p;
	for(int i=0;i<ilosc_zaklec;i++)
	{
		p=dynamic_cast<ZaklecieOfensywne*>(znane_zaklecia[i]);
		if(p!=NULL)
			return i;
	}
	return 0;

}
int Kaplan::znajdz_zaklecie_defensywne() const
{
	ZaklecieDefensywne* p;
	for(int i=0;i<ilosc_zaklec;i++)
	{
		p=dynamic_cast<ZaklecieDefensywne*>(znane_zaklecia[i]);
		if(p!=NULL)
			return i;
	}
	return -1;
}
int Kaplan::wykonaj_atak(int poziom_ochrony_przeciwnika)
{
	return sila;
}

