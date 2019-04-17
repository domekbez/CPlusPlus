#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Zaklecie
{
protected:
	string nazwa;
	int poziom_trudnosci;
public:
	Zaklecie(string nazwa, int poziom_trudnosci);
	virtual int wypowiedz_zaklecie() = 0;
	int jaki_poziom_trudnosci() const { return poziom_trudnosci; }
	void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Zaklecie&);
};

class ZaklecieOfensywne : public Zaklecie
{
protected:
	int obrazenia;
public:
	ZaklecieOfensywne(string nazwa, int poziom_trudnosci, int a):Zaklecie(nazwa,poziom_trudnosci),obrazenia(a){};
	virtual int wypowiedz_zaklecie();

};

class ZaklecieDefensywne : public Zaklecie
{
protected:
	int odzyskane_punkty_zycia;
public:
	ZaklecieDefensywne(string nazwa, int poziom_trudnosci, int a):Zaklecie(nazwa,poziom_trudnosci),odzyskane_punkty_zycia(a){};
	virtual int wypowiedz_zaklecie();
	// uzupelnij

};

