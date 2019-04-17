#pragma once
using namespace std;
template <class T>
class unique
{

	T* wsk;

public:

	unique(T* a)
	{
		
		wsk = a;
		if (a)
		cout << "Tworzenie obiektu unique" << endl;
	}
	unique() { wsk = nullptr; }

	~unique()
	{
		if(wsk != nullptr)
		{
			delete wsk;
			cout << "Zwalnianie pamieci" << endl;
		}
	}
	unique& operator=(const unique& u) = delete;
	unique(const unique& u) = delete;
	unique(unique&& u)
	{
		wsk = u.wsk;
		u.wsk = nullptr;
	}
	unique& operator=(unique&& u)
	{
		if (this != &u)
		{
			this->~unique();
			wsk = u.wsk;
			u.wsk = nullptr;
		}
		return *this;
	}	
	T& operator*()
	{
		return *wsk;
	}
	T* operator->()
	{
		return wsk;
	}
	const T& operator*() const 
	{
		return *wsk;
	}
	const T* operator->() const 
	{
		return wsk;
	}
		
};