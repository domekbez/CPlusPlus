#include "moneta.h"
#include <string.h>
// uzupe³nij
moneta::moneta(string nominal, int rok, double cena):rok(rok),nominal(nominal),cena(cena)
{
	przewidywana_wartosc = NULL;

	ile_lat_przewidywan=0;
}
moneta::moneta(string nominal, int rok, double cena, grading &gr):grading(gr),rok(rok),cena(cena),nominal(nominal)
{
	przewidywana_wartosc = NULL;

	ile_lat_przewidywan=0;
}
moneta::moneta(string nominal, int rok, double cena, int nota, firma centrum):grading(nota,centrum),cena(cena),rok(rok),nominal(nominal)
{
	przewidywana_wartosc = NULL;

	ile_lat_przewidywan=0;
}
moneta::moneta(const moneta& b)
{
	cena=b.cena;
	rok=b.rok;
	ile_lat_przewidywan=b.ile_lat_przewidywan;
	przewidywana_wartosc = new (nothrow) double[ile_lat_przewidywan];
	for(int i=0; i<ile_lat_przewidywan;i++)
	{
		przewidywana_wartosc[i]=b.przewidywana_wartosc[i];
	}
}
moneta::~moneta()
{
	delete [] przewidywana_wartosc;
}
moneta& moneta::operator = (const moneta& b)
{
	(grading&)(*this)=(grading&)b;
	cena=b.cena;
	rok=b.rok;
	delete [] przewidywana_wartosc;
	ile_lat_przewidywan=b.ile_lat_przewidywan;
	przewidywana_wartosc = new (nothrow) double[ile_lat_przewidywan];
	for(int i=0; i<ile_lat_przewidywan;i++)
	{
		przewidywana_wartosc[i]=b.przewidywana_wartosc[i];
	}
	return *this;

}

ostream& operator<<(ostream& out, const moneta& b)
{
	
	out << "Moneta o nominale " << b.nominal << " z roku " << b.rok << " cena: " << b.cena << " wartosc: " << b.cena*b.wsp_ceny;
	out << (grading&)b;
	return out;
}
void moneta::oblicz_wartosc(int ile_lat)
{
	if(ile_lat==0)
	{
		przewidywana_wartosc=NULL;
		return;
	}
	ile_lat_przewidywan=ile_lat;

	przewidywana_wartosc = new (nothrow) double[ile_lat];
	if(!przewidywana_wartosc)
		return;
	przewidywana_wartosc[0]=cena*wsp_ceny;
	for(int i=1;i<ile_lat;i++)
	{
		przewidywana_wartosc[i]=przewidywana_wartosc[i-1]*1.05;
	}
}


void moneta::wypisz_przewidywana_wartosc()
{
	
	cout << *this << endl;
	for(int i=0; i<ile_lat_przewidywan;i++)
	{
		cout << i << ". " << przewidywana_wartosc[i] << endl;
	}
}
