#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Skorpion
{	
protected:
	int punktyZycia;
	int sila_ataku;
	int poziom_ochrony;

public:
	Skorpion():punktyZycia(15),sila_ataku(2),poziom_ochrony(2){};
	virtual ~Skorpion() {};
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Skorpion&);
};

class SkorpionOlbrzymi : public Skorpion
{
public:
	
	virtual void info(ostream& out) const;
	int atak_ostrym_odnozem() const;
	int wykonaj_atak(int poziom_ochrony_przeciwnika) const;

};

class JadowitySkorpionOlbrzymi : public SkorpionOlbrzymi
{
	static int ktory_atak;
public:
	// uzupelnij
	JadowitySkorpionOlbrzymi();
	virtual void info(ostream& out) const;
	int atak_jadowitym_kolcem() const;
	int JadowitySkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const;

};