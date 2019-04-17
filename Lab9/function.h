#pragma once

// klasa bazowa dla: FIdent, FConst, FSub, FProd
template <class T=double>
class Function
{
public:
	virtual T value(T x) const =0;
	virtual T prim(T x) const =0;
	virtual ~Function() {}
};
template <class T=double>
class FIdent : public Function<T>
{
public:
	virtual T value(T x) const;
	virtual T prim(T x) const;
	virtual ~FIdent() {};
};
template <class T=double>
class FConst : public Function<T>
{
	T x;
public:
	FConst(T x) :x(x) {}
	virtual T value(T x) const;
	virtual T prim(T x) const;
	virtual ~FConst() {};
};
template <class T=double>
class FSub : public Function<T>
{
	Function<T>* a;
	Function<T>* b;
public:
	FSub(Function<T>* c, Function<T>* d) :a(c), b(d) {}
	virtual T value(T x) const;
	virtual T prim(T x) const;
	virtual ~FSub();
};
template <class T=double>
class FProd : public Function<T>
{
	Function<T>* a;
	Function<T>* b;
public:
	FProd(Function<T>* c, Function<T>* d) :a(c), b(d) {}
	virtual T value(T x) const;
	virtual T prim(T x) const;
	virtual ~FProd();
};


// tutaj uzupe³nij definicje klas pochodnych: FIdent, FConst, FSub, FProd - ETAP 1
template <class T>
T FConst<T>::value(T x) const
{
	return this->x;
}
template <class T>
T FConst<T>::prim(T x) const

{
	return 0;
}
template <class T>
T FIdent<T>::value(T x) const
{
	return x;
}
template <class T>
T FIdent<T>::prim(T x) const
{
	return 1;
}
template <class T>
T FSub<T>::value(T x) const
{
	return a->value(x) - b->value(x);

}
template <class T>
T FSub<T>::prim(T x) const
{
	return a->prim(x) - b->prim(x);
}
template <class T>
FSub<T>::~FSub()
{
	delete a;
	delete b;
}

template <class T>
T FProd<T>::value(T x) const
{
	return a->value(x) * b->value(x);
}
template <class T>
T FProd<T>::prim(T x) const
{
	return a->prim(x)*b->value(x)+a->value(x)*b->prim(x);
}
template <class T>
FProd<T>::~FProd()
{
	delete a;
	delete b;
}







