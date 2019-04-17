#include <string>
#include "alkohol.h"
using namespace std;


bool operator==(const Wino& w1, const Wino& w2)
{
	return (w1.nazwa == w2.nazwa && w1.rodzaj == w2.rodzaj);

}
bool operator==(const Piwo& w1, const Piwo& w2)
{
	return (w1.nazwa == w2.nazwa && w1.rodzaj == w2.rodzaj);
	
}

string Wino::pobierz_rodzaj() const
{
	if (rodzaj == SLODKIE)
		return "SLODKIE";
	if (rodzaj == POLSLODKIE)
		return "POLSLODKIE";
	if (rodzaj == POLWYTRAWNE)
		return "POLWYTRAWNE";
	else
		return "WYTRAWNE";
}
string Piwo::pobierz_rodzaj() const
{
	
	
	if (rodzaj == BIALE)
		return "BIALE";
	if (rodzaj == JASNE)
		return "JASNE";
	if (rodzaj == CIEMNE)
		return "CIEMNE";
	if (rodzaj == NIEFILTROWANE)
		return "NIEFILTROWANE";
	else
		return "NIEPASTERYZOWANE";
}
string Piwo::pobierz_opakowanie() const
{
	if (opakowanie == PUSZKA)
		return "PUSZKA";
	else
		return "BUTELKA";

}
void Wino::wyprowadz_na_ekran(ostream& out) const
{

	out << "Wino " << nazwa << ", " << pobierz_rodzaj() << ", rocznik " << rocznik << ", cena: " << cena << endl;
}
void Piwo::wyprowadz_na_ekran(ostream& out) const
{
	out << "Piwo " << nazwa << ", " << pobierz_rodzaj() << ", " << pobierz_zawartosc_alkoholu() << ", " << pobierz_opakowanie() << ", cena: " << cena << endl;
}
ostream& operator<<(ostream& out, const Alkohol& w)
{
	w.wyprowadz_na_ekran(out);
	return out;
}