#include <iostream> 
using namespace std;
#include "Bron.h"

// klasa Bron

Bron::Bron(string nazwa, string opis, int obrazenia) : Przedmiot(nazwa, opis), obrazenia(obrazenia) {}

// uzupelnij
void Bron::info(ostream& out) const
{
	out << nazwa << opis << ", obrazenia: " << obrazenia << endl;
}
int Bron::atak_bronia() const
{
	return obrazenia;
}



