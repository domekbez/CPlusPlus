#include <iostream> 
using namespace std;
#include "Zaklecie.h"

// klasa Zaklecie

Zaklecie::Zaklecie(string nazwa,  int poziom_trudnosci) : nazwa(nazwa), poziom_trudnosci(poziom_trudnosci) {}

void Zaklecie::info(ostream& out) const
{
	out << nazwa << " ( poziom " << poziom_trudnosci << ") ";
}

ostream& operator<<(ostream& out, const Zaklecie& p)
{
	p.info(out);
	out << endl;
	return out;
}

// klasa ZaklecieOfensywne
int ZaklecieOfensywne::wypowiedz_zaklecie()
{
	return obrazenia;
}


// uzupelnij


// klasa ZaklecieDefensywne
int ZaklecieDefensywne::wypowiedz_zaklecie()
{
	return odzyskane_punkty_zycia;
}
// uzupelnij
