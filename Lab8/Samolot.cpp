#include "Samolot.hpp"

#include "FabrykaSamolotow.hpp"
using namespace std;

#pragma region Samolot

std::ostream & operator<<(std::ostream & out, const Samolot & samolot)
{
	samolot.ZwrocInformacje(out);
	return out;
}

void Samolot::ZwrocInformacje(std::ostream & out) const
{
	out << "Cena: " << ZwrocCene() << std::endl;
	out << *silnik;
	out << "Liczba siedzien: " << liczbaSiedzen << std::endl;
	out << "Waga: " << wagaBezSilnika + silnik->ZwrocWage() << std::endl;
	out << "Oplywowosc: " << oplywowosc << std::endl;
	out << "Przyspieszenie: " << ZwrocPrzyspieszenie() << std::endl;
	out << "Predkosc maksymalna: " << ZwrocPredkoscMaksymalna() << std::endl;
}

Silnik & Samolot::ZwrocSilnik() const
{
	return *silnik;
}

int Samolot::ZwrocLiczbeSiedzen() const
{
	return liczbaSiedzen;
}

int Samolot::ZwrocCene() const
{
	return static_cast<int>(ZwrocKosztProdukcji() * 1.4f);
}

int Samolot::ZwrocKosztProdukcji() const
{
	return kosztProdukcjiBezSilnika + silnik->ZwrocKosztProdukcji();
}

float Samolot::ZwrocWage() const
{
	return wagaBezSilnika + silnik->ZwrocWage();
}

float Samolot::ZwrocOplywowosc() const
{
	return oplywowosc;
}

float Samolot::ZwrocWspolczynnikMocy() const
{
	return 1.0f;
}

float Samolot::ZwrocPrzyspieszenie() const
{
	return silnik->ObliczPrzyspieszenie(ZwrocWage(), ZwrocWspolczynnikMocy());
}

float Samolot::ZwrocPredkoscMaksymalna() const
{
	return silnik->ObliczPredkoscMaksymalna(ZwrocOplywowosc(), ZwrocWspolczynnikMocy());
}

// Implementacja konstruktora i destruktora
Samolot::Samolot(Silnik* silnik=nullptr, int liczbaSiedzen=0, int kosztProdukcjiBezSilnika=0, float wagaBezSilnika=0, float oplywowosc=0):liczbaSiedzen(liczbaSiedzen),kosztProdukcjiBezSilnika(kosztProdukcjiBezSilnika),wagaBezSilnika(wagaBezSilnika),oplywowosc(oplywowosc)
{
	this->silnik = silnik;
}
Samolot::~Samolot()
{
	delete silnik;
}


#pragma endregion
#pragma region Samolot Pasazerski

// Implementacja samolotu pasazerskiego
void SamolotPasazerski::ZwrocInformacje(ostream& out) const
{
	out << "Samolot pasazerski";
	out << (Samolot&)(*this) << endl;
	if (ogrzewanie)
		out << "ogrzewanie wlaczone" << endl;
	else
		out << "ogrzewanie wylaczone" << endl;
}
void SamolotPasazerski::UstawPodgrzewanieSiedzen(bool a)
{
	if (a == true)
		ogrzewanie = true;
	else
		ogrzewanie = false;
}
float SamolotPasazerski::ZwrocWspolczynnikMocy() const
{
	if (ogrzewanie == true)
		return 0.9;
	else
		return 1.0;

}
#pragma endregion
#pragma region Samolot Transportowy

// Implementacja samolotu transportowego
void SamolotTransportowy::ZwrocInformacje(ostream& out) const
{
	out << "Samolot transportowy";
	out << (Samolot&)(*this) << endl;
	out << "Zawartosc luku: " << towar << endl;


}
void SamolotTransportowy::UstawIloscTowaru(float a)
{
	towar = a;
}
float SamolotTransportowy::ZwrocWage() const
{
	return towar;
}
#pragma endregion
#pragma region Samolot Wyczynowy

// Implementacja samolotu wyczynowego
void SamolotWyczynowy::ZwrocInformacje(ostream& out) const
{
	out << "Samolot wyczynowy";
	out << (Samolot&)(*this) << endl;
	if (otwarte)
		out << "Klapy sa otwarte " << endl;
	else
		out << "Klapy sa zamkniete" << endl;

}
void SamolotWyczynowy::UstawCzyKlapyOtwarte(bool a)
{
	otwarte = a;
}
float SamolotWyczynowy::ZwrocOplywowosc() const
{
	if (otwarte)
		return 0.9;
	return 1;
}
#pragma endregion
