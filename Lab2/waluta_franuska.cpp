
#include "waluta_francuska.h"


waluta_francuska::waluta_francuska()
{
	liwr=1;
	solid=0;
	denar=0;
}
waluta_francuska::waluta_francuska(int a, int b, int c)
{
	if(a<0||b<0||c<0)
	{
		liwr=0;
		solid=0;
		denar=0;
	}
	else
	{
		liwr=a;
		solid=b;
		denar=c;
	}
	porzadkowanie();
}
waluta_francuska::waluta_francuska(double a)
{

	if(a<0)
	{
		liwr=0;
		solid=0;
		denar=0;
	}
	else
	{
		denar=int(a*240);
		solid=0;
		liwr=0;
	}

	
	porzadkowanie();
}
ostream& operator<<(ostream& out, const waluta_francuska& wal)
{
	out << "L " << wal.liwr << "." << wal.solid << "." << wal.denar << endl;
	return out;
}
istream& operator>>(istream& in, waluta_francuska& wal)
{
	
	double ile;
	cout << "Podaj liczbe typu double: ";
	in >> ile;
	wal.denar=int(240*ile);
	wal.solid=0;
	wal.liwr=0;
	wal.porzadkowanie();

	return in;
}
void waluta_francuska::porzadkowanie()
{
	while(denar>=12)
	{
		denar-=12;
		solid+=1;
	}
	while(solid>=20)
	{
		solid-=20;
		liwr+=1;
	}
}
waluta_francuska::waluta_francuska(const waluta_francuska& w)
{
	liwr=w.liwr;
	solid=w.solid;
	denar=w.denar;
	porzadkowanie();
}
waluta_francuska operator-(const waluta_francuska& a, const waluta_francuska& b)
{
	waluta_francuska d(0,0,0),e,f;
	e=a;
	f=b;

	if((e.denar-f.denar)>=0)
	{
		d.denar=e.denar-f.denar;
	}
	else
	{
		d.denar=e.denar+12-f.denar;
		e.solid-=1;
		
	}
	if((e.solid-f.solid)>=0)
	{
		d.solid=e.solid-f.solid;
	}
	else
	{
		d.solid=e.solid+20-f.solid;
		e.liwr-=1;
	}
	if((e.liwr-f.liwr)>=0)
	{
		d.liwr=e.liwr-f.liwr;
	}
	else
	{
		d.liwr=e.liwr+20-f.liwr;
		e.liwr-=1;
	}
	return d;
}
void operator+=(waluta_francuska& a, const waluta_francuska& b)
{
	a.denar+=b.denar;
	a.solid+=b.solid;
	a.liwr+=b.liwr;
	a.porzadkowanie();
}
waluta_francuska operator*(const waluta_francuska& a, int b)
{
	waluta_francuska c(0,0,0);
	c.denar=a.denar*b;
	c.solid=a.solid*b;
	c.liwr=a.liwr*b;
	c.porzadkowanie();
	return c;
}
waluta_francuska operator*(int b, const waluta_francuska& a)
{
	waluta_francuska c(0,0,0);
	c.denar=a.denar*b;
	c.solid=a.solid*b;
	c.liwr=a.liwr*b;
	c.porzadkowanie();
	return c;
}
waluta_francuska& operator--(waluta_francuska& wal)
{
	wal.denar--;
	return wal;
}
waluta_francuska operator--(waluta_francuska& wal, int k)
{
	waluta_francuska c;
	c=wal;
	c.denar--;
	return c;
}
waluta_francuska& operator++(waluta_francuska& wal)
{
	wal.denar++;
	return wal;
}
waluta_francuska operator++(waluta_francuska& wal, int k)
{
	waluta_francuska c;
	c=wal;
	c.denar++;
	return c;
}
double waluta_francuska::operator()()
{
	double z;
	solid=solid+20*liwr;
	denar=denar+12*solid;
	z=(double(denar)/240.0);
	return z;
}
