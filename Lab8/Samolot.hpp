#pragma once

#include "Silnik.hpp"
using namespace std;

class FabrykaSamolotow;

class Samolot
{
	friend class FabrykaSamolotow;

private:
	Silnik * silnik;
	int liczbaSiedzen;
	int kosztProdukcjiBezSilnika;
	float wagaBezSilnika;
	float oplywowosc;

protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
//	virtual Samolot* Replikuj(FabrykaSamolotow& fabryka) const = 0;
	Silnik& ZwrocSilnik() const;

public:
	Samolot(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc);
	virtual ~Samolot();

	int ZwrocLiczbeSiedzen() const;
	int ZwrocCene() const;
	int ZwrocKosztProdukcji() const;
	virtual float ZwrocWage() const;
	virtual float ZwrocOplywowosc() const;
	virtual float ZwrocWspolczynnikMocy() const;

	float ZwrocPrzyspieszenie() const;
	float ZwrocPredkoscMaksymalna() const;


	friend std::ostream& operator << (std::ostream& out, const Samolot& samolot);
};

class SamolotPasazerski : public Silnik
{
	bool ogrzewanie = false;
public:
	SamolotPasazerski(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc) :Samolot(silnik, liczbaSiedzen, kosztProdukcjiBezSilnika, wagaBezSilnika, oplywowosc) {};
	virtual void ZwrocInformacje(ostream& out) const;
	void UstawPodgrzewanieSiedzen(bool a);
	virtual float ZwrocWspolczynnikMocy() const;
};
class SamolotTransportowy : public Silnik
{
	float towar = 0;
public:
	SamolotTransportowy(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc) :Samolot(silnik, liczbaSiedzen, kosztProdukcjiBezSilnika, wagaBezSilnika, oplywowosc) {};
	virtual void ZwrocInformacje(ostream& out) const;
	void UstawIloscTowaru(float a);
	virtual float ZwrocWage() const;
};
class SamolotWyczynowy : public Silnik
{
	bool otwarte = false;
public:
	SamolotWyczynowy(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc) :Samolot(silnik, liczbaSiedzen, kosztProdukcjiBezSilnika, wagaBezSilnika, oplywowosc) {};
	virtual void ZwrocInformacje(ostream& out) const;
	void UstawCzyKlapyOtwarte(bool a);
	virtual float ZwrocOplywowosc() const;

};