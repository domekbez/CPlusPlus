#include "FabrykaSamolotow.hpp"
using namespace std;

int FabrykaSamolotow::ZwrocSrodki() const
{
	return srodkiDoProdukcji;
}

void FabrykaSamolotow::OdnowSrodki(int noweSrodki)
{
	srodkiDoProdukcji += noweSrodki;
}
Silnik * FabrykaSamolotow::Produkuj(const Silnik& wzorzec)
{
	if (srodkiDoProdukcji < wzorzec.kosztProdukcji)
		throw runtime_error("Niewystarczajace srodki do produkcji silnika");
	
	srodkiDoProdukcji -= wzorzec.kosztProdukcji;
	return wzorzec.Replikuj();
}