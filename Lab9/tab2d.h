#pragma once
#include <iostream>
using namespace std;
template <class T, int m, int n>
class tab2d
{
	static const int M = 100;
	static const int N = 100;
	T tab[M][N];

public:
	tab2d();
	T& operator()(int i, int j);
	T maks() const;

	friend ostream& operator<<(ostream& out, const tab2d<T,M,N>& t);
};
template <class T, int M, int N>
tab2d<T,M,N>::tab2d()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) tab[i][j] = 0;
}

template <class T, int M, int N>
T& tab2d<T,M,N>::operator()(int i, int j)
{
	return tab[i][j];
}
template <class T, int M, int N>
T tab2d<T,M,N>::maks() const
{
	T m = tab[0][0];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (tab[i][j] > m) m = tab[i][j];

	return m;
}

ostream& operator<<(ostream& out, const tab2d& t)
{
	for (int i = 0; i < t.M; i++)
	{
		for (int j = 0; j < t.N; j++) 	out << t.tab[i][j];
		cout << endl;
	}
	return out;
}






