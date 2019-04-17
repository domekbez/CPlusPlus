#pragma once
   
#include <iostream>
using namespace std;

class lokata 
{
	double wartosc;		// wartosc lokaty na starcie
	double oproc;		// oprocentowanie bankowe w momencie za�o�enia lokaty, w procentach np. 6%
	
public:
	lokata(double wartosc, double oproc);
		
	double wartosc_lokaty() const;	// oblicz warto�� lokaty razem z oprocentowaiem

	friend ostream& operator<<(ostream& out, const lokata& l);

};