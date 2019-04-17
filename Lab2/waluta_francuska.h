#pragma once
#include <iostream>
using namespace std;

class waluta_francuska
{
	int liwr,solid,denar;
	void porzadkowanie();
public:
	waluta_francuska();
	waluta_francuska(int a, int b, int c);
	waluta_francuska(double a); 
	waluta_francuska(const waluta_francuska& w);
	double operator()();
	friend waluta_francuska operator-(const waluta_francuska& a, const waluta_francuska& b);
	friend void operator+=(waluta_francuska& a, const waluta_francuska& b);
	friend waluta_francuska operator*(const waluta_francuska& a, int b);
	friend waluta_francuska operator*(int b, const waluta_francuska& a);
	friend ostream& operator<<(ostream& out, const waluta_francuska& wal);
	friend istream& operator>>(istream& in, waluta_francuska& wal);
	friend waluta_francuska& operator--(waluta_francuska& wal);
	friend waluta_francuska operator--(waluta_francuska& wal, int k);
	friend waluta_francuska& operator++(waluta_francuska& wal);
	friend waluta_francuska operator++(waluta_francuska& wal, int k);

};
