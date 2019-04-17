#include <iostream> 
using namespace std;
#include "Skorpion.h"

// uzupelnij
int JadowitySkorpionOlbrzymi::ktory_atak=0;

// Klasa Skorpion

void Skorpion::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

ostream& operator<<(ostream& out, const Skorpion& p)
{
	p.info(out);
	return out;
}

// Klasa SkorpionOlbrzymi

// uzupelnij

void SkorpionOlbrzymi::info(ostream& out) const
{
	out << "Skropion olbrzymi - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia << endl;
}
int SkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if(sila_ataku>poziom_ochrony_przeciwnika)
		return atak_ostrym_odnozem();
	return 0;
}
int SkorpionOlbrzymi::atak_ostrym_odnozem() const
{
	return 2;
}



// Klasa JadowitySkorpionOlbrzymi
JadowitySkorpionOlbrzymi::JadowitySkorpionOlbrzymi()
{
	punktyZycia*=2;
	sila_ataku*=2;
	poziom_ochrony*=2;
}
void JadowitySkorpionOlbrzymi::info(ostream& out) const
{
	out << "Jadowity Skropion olbrzymi - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia << endl;

}
int JadowitySkorpionOlbrzymi::atak_jadowitym_kolcem() const
{
	
		
	if(ktory_atak%2==0)
	{
		
		return 8;
	}
		
		return 2;
}
int JadowitySkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	ktory_atak++;
	int a=atak_jadowitym_kolcem();
	if(a==8)
		return a;
	if(sila_ataku>poziom_ochrony_przeciwnika)
		return atak_jadowitym_kolcem();
	return 0;
}
// uzupelnij
