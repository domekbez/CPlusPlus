#ifndef OBRAZEK_HPP
#define OBRAZEK_HPP

#include <iostream>
using namespace std;

class Obrazek
{
private:
	// Iloœæ wierszy obrazka
	int wiersze;
	// Iloœæ kolumn obrazka
	int kolumny;
	// WskaŸnik na dwuwymiarow¹ tablicê
	char** dane;

public:
	// Etap 1
	Obrazek();
	Obrazek(int a, int b);
	Obrazek(int a, int b, const char * w);
	~Obrazek();
	void UstawZnak(const char& z);
	friend ostream& operator<<(ostream& out, const Obrazek& o);

	// Etap 2
	Obrazek(const Obrazek& o);
	Obrazek& operator=(const Obrazek& o);
	friend istream& operator>>(istream& in, Obrazek& o);
	void ZwrocRozmiar(int & w, int & k) const;
	char& operator()(int i, int j);
	const char& operator()(int i, int j) const; 
	// Etap 3
	char& operator[](int i);
	const char& operator[](int i) const; 
	Obrazek& Odbij();
	Obrazek& ObrocWLewo();

};

#endif // !OBRAZEK_HPP
