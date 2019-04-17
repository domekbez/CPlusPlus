#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;
#include "druzyna.h"

ostream& operator<<(ostream& out, const Druzyna& d)
{
	out << "Reprezentacja: " << setw(12) << d.reprezentacja_kraju << ",";
	out << " pozycja: " << setw(3) << d.pozycja_w_rankingu << ",";
	out << " punkty: " << setw(4) << d.aktualna_liczna_punktow() << ",";
	out << " Z: " << setw(2) << d.zwyciestwa() << ",";
	out << " R: " << setw(2) << d.remisy() << ",";
	out << " P: " << setw(2) << d.przegrane() << ",";
	out << " Bramki: " << setw(2) << d.bramki().first << " : " << d.bramki().second;
	out << endl;
	return out;
}
int Druzyna::zwyciestwa() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](const pair<int,int>& p) {return p.first > p.second; });
}
int Druzyna::remisy() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](const pair<int,int>& p) {return p.first == p.second; });
}
int Druzyna::przegrane() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](const pair<int,int>& p) {return p.first < p.second; });
}
pair<int, int> Druzyna::bramki() const
{
	pair<int, int> a = make_pair(0, 0);
	return accumulate(wyniki_meczow.begin(), wyniki_meczow.end(), a, [](const pair<int, int>& a, const pair<int, int>& b) {return make_pair(a.first+b.first, a.second+b.second); });
	}
bool operator<(const Druzyna& a, const Druzyna& b)
{
	return a.ilosc_punktow < b.ilosc_punktow;
}
bool operator>(const Druzyna& a, const Druzyna& b)
{
	return a.ilosc_punktow > b.ilosc_punktow;
}
bool operator==(const Druzyna& a, const Druzyna& b)
{
	return a.reprezentacja_kraju == b.reprezentacja_kraju;
}
int Druzyna::aktualna_liczna_punktow() const
{

	
	vector<int> pom;
	vector<int> pom2;
	if (wyniki_meczow.empty())
		return ilosc_punktow;

	transform(rozegrane_mecze.begin(), rozegrane_mecze.end(), back_inserter(pom), [](const pair<Druzyna, Rodzaj_meczu>& p) {return (21-(p.first).pozycja_w_rankingu) *int(p.second); });

	transform(wyniki_meczow.begin(), wyniki_meczow.end(), back_inserter(pom2), [](const pair<int, int>& p) {if (p.first > p.second)return 3; if (p.first == p.second)return 1; if (p.first < p.second)return 0; });
	
	int wyn = int(inner_product(pom.begin(), pom.end(), pom2.begin(), 0) / wyniki_meczow.size()) + ilosc_punktow;

	return wyn;
}