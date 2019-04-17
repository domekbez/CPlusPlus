#include "Silnik.hpp"
using namespace std;


float Silnik::ZwrocWage() const
{
	return waga;
}
float Silnik::ZwrocMoc() const
{
	return moc;
}
int Silnik::ZwrocKosztProdukcji() const
{
	return kosztProdukcji;
}
void Silnik::ZwrocInformacje(std::ostream & out) const
{
	out << "  Waga: " << waga << std::endl;
	out << "  Moc: " << moc << std::endl;
}
float Silnik::ObliczPredkoscMaksymalna(float oplywowosc, float wspolczynnikMocy) const
{
	return 0.1*oplywowosc*moc*wspolczynnikMocy + 300.0;
}
std::ostream& operator << (std::ostream& out, const Silnik& silnik)
{
	if(typeid(silnik)==typeid(SilnikSpalinowy))
		out << "Silnik spalinowy" << std::endl;
	if (typeid(silnik) == typeid(SilnikElektryczny))
		out << "Silnik elektryczny" << std::endl;
	if (typeid(silnik) == typeid(SilnikOdrzutowy))
		out << "Silnik odrzutowy" << std::endl;
	silnik.ZwrocInformacje(out);
	
	return out;
}
float SilnikSpalinowy::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	float a = ZwrocMoc();
	return ((0.05*waga) / sqrt(a*wspolczynnikMocy));
}
SilnikSpalinowy::SilnikSpalinowy(float mocc):Silnik(200,mocc,11*mocc)
{}
float SilnikElektryczny::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	float a = ZwrocMoc();
	return (0.5*waga) / (a*wspolczynnikMocy);
}
float SilnikOdrzutowy::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	float a = ZwrocMoc();
	return (100 * waga) / ((a*wspolczynnikMocy)*(a*wspolczynnikMocy));
}
Silnik* SilnikElektryczny::Replikuj() const
{
	return new (nothrow) SilnikElektryczny(*this);
}
Silnik* SilnikSpalinowy::Replikuj() const
{
	return new (nothrow) SilnikSpalinowy(*this);

}
Silnik* SilnikOdrzutowy::Replikuj() const
{
	return new (nothrow) SilnikOdrzutowy(*this);
}