#include "bank.h"

   
//------------------------------------------------------------------
double bank::oproc_lokaty  = 10;		// oprocentowanie lokaty wynosi 10%
//------------------------------------------------------------------

ostream& operator<<(ostream& out, const bank& b)
{
	cout << "-------------------------------------------";
	if (!b.n)
		out << endl << "Brak kont w banku" << endl;

	for (int i = 0; i < b.n; i++)
		out << *b.konta[i] << endl;
	cout << "-------------------------------------------";

	return out;
}
//------------------------------------------------------------------
/*
int bank::znajdz_konto(unsigned int nr_konta) const
{
	int i = -1;

	// uzupe³nij w ETAP 3

	return i;
}
*/
//------------------------------------------------------------------

bool bank::nowe_konto(const klient& k)
{
	konto ** konta2;
	konta2=new (nothrow) konto*[n+1];
	if(!konta2)
		return false;
	for(int i=0;i<n;i++)
	{
		konta2[i]=new(nothrow) konto;
	}
	for(int i=0;i<n;i++)
	{
		konta2[i]->saldo=konta[i][1].saldo;
		konta2[i]->l=konta[i][1].l;
		strcpy(konta2[i]->wlasciciel.imie,konta[i][1].wlasciciel.imie);
		strcpy(konta2[i][1].wlasciciel.nazwisko,konta[i][1].wlasciciel.nazwisko);
	}
	
	konta2[n]=new konto(k.osoba,nadaj_nr_konta);
	konta2[n][1].saldo=0;
	konta2[n][1].l=NULL;
	for(int i=0;i<n;i++)
	{
		delete [] konta[i];
	}
	delete [] konta;
	konta=konta2;
	
	nadaj_nr_konta++;
	


	return true;
}

//------------------------------------------------------------------

bool bank::kasuj_konto(const klient& k)
{
	// uzupe³nij w ETAP 3

	return true;
}

//------------------------------------------------------------------

bool bank::wplata_na_konto(const klient& k)
{
	// uzupe³nij w ETAP 4a

	return true;
}

//------------------------------------------------------------------

bool bank::wyplata_z_konta(const klient& k)
{
	// uzupe³nij w ETAP 4b

	return true;
}

//------------------------------------------------------------------

bool bank::wez_lokate(const klient& k)
{
	// uzupe³nij w ETAP 5

	return true;
}

//------------------------------------------------------------------

bool bank::kasuj_lokate(const klient& k)
{
	// uzupe³nij w ETAP 6

	return true;
}

//-----------------------------------------------------------------


