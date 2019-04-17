#pragma once

#include <iostream>

class FabrykaSamolotow;

class Silnik
{
	friend class FabrykaSamolotow;

private:
	float waga;
	float moc;
	int kosztProdukcji;

protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
	virtual Silnik* Replikuj() const = 0;

public:
	Silnik(float waga=0, float moc=0, int kosztProdukcji=0) :waga(waga), moc(moc), kosztProdukcji(kosztProdukcji) {};
	virtual ~Silnik() {};

	float ZwrocWage() const;
	float ZwrocMoc() const;
	int ZwrocKosztProdukcji() const;

	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const = 0;
	float ObliczPredkoscMaksymalna(float oplywowosc, float wspolczynnikMocy) const;

	friend std::ostream& operator << (std::ostream& out, const Silnik& silnik);
};
class SilnikSpalinowy :public Silnik
{
	public:
		SilnikSpalinowy(float mocc);
		virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
		virtual Silnik* Replikuj() const;
};
class SilnikElektryczny : public Silnik
{
public:
	SilnikElektryczny(float moc):Silnik(140, moc, 14 * moc) {};
	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
	virtual Silnik* Replikuj() const;

};
class SilnikOdrzutowy : public Silnik
{
public:
	SilnikOdrzutowy(float moc) :Silnik(1100, moc, 16 * moc) {};
	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
	virtual Silnik* Replikuj() const;
};
