#pragma once
#include <iostream>
using namespace std;
#include "dane.h"
#include "lokata.h"

class bank;

class konto
{
private:
	dane wlasciciel;
	double saldo;		// rachunek bie��cy nieoprocentowany
	lokata* l;			// na koncie mo�na za�o�y� tylko jedn� lokat�
		
public:
	const unsigned int nr_konta;	// numer konta nie jest tajny (pole sta�e po nadaniu numeru)

public:
	konto();
	konto(const dane& wlasciciel, unsigned int nr_konta=0);	// ETAP 2
	~konto();												// ETAP 2

	//bool czy_wlasciciel_konta(const dane& os) const;		// ETAP 3
	//bool czy_lokata() const;								// ETAP 3
	
	//bool wplata(double kwota);							// ETAP 4a
	//bool wyplata(double kwota);							// ETAP 4b
	//bool wez_lokate(double kwota);						// ETAP 5
	//bool kasuj_lokate(double kwota);						// ETAP 6
			
	friend ostream& operator<<(ostream& out, const konto& k);
	friend class bank;

};
