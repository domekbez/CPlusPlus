#include <iostream>
#include "unique.h"
#include <vector>

template <class T>
bool IsValid(unique<T>& u)
{

	return (u.operator->());

}
template <class T>
unique<T> Bigger(unique<T>& u1, unique<T>& u2)
{

	if (*u1 > *u2)
	{
		u2 = nullptr;
		return move(u1);
	}
	if (*u1 < *u2)
	{
		u1 = nullptr;
		return move(u2);
	}
	
	return (unique<T>(nullptr));
	

}

int main() {

	std::cout << "============= ETAP 1 ==============" << std::endl;
	{
		unique<double> ptr(new double(18.4));
	}
	{
		unique<int> ptr(new int(1));
		unique<std::vector<int>> ptr2(new std::vector<int>{ 1,2,3,19, 47 });
	}

	std::cout << "============= ETAP 2 ==============" << std::endl;
	{
		std::string val1 = "hello";
		std::string val2 = "world";
		unique<std::string> ptr1(new std::string(val1));
		unique<std::string> ptr2(new std::string(val2));

		// tylko niekt�re z poni�szych linijek s� prawid�owe. Kt�re?
		ptr2 = std::move(ptr1);
		//ptr2 = ptr1;
		unique<std::string> ptr3(std::move(ptr2));
		//unique<int> ptr2(ptr2);

		unique<std::string> empty{};

	}
	std::cout << "============= ETAP 3 ==============" << std::endl;

	{
		unique<double> small(new double(3.14));
		unique<double> big(new double(6.28)); // recommend reading tau manifesto.
		if (*small <= *big) {
			std::cout << "Wszystko gra: " << *big << std::endl;
		}
		else {
			std::cout << "Co� jest nie tak..." << std::endl;
		}
	}

	{
		class HandyObjectHolder {
		public:
			std::vector<int> ints;
			int b;
		};
		unique<HandyObjectHolder> holder(new HandyObjectHolder{ std::vector<int>{122}, 82 });

		std::cout << "ints: ";
		for (const auto& elem : holder->ints) {
			std::cout << elem << " ";
		}
		std::cout << " i b: " << holder->b << std::endl;
	}
	{
		unique<int> shouldBeEmpty{};
		unique<int> alsoEmpty(nullptr);//konstruktor
		unique<int> notEmpty(new int(17438));//konstruktor
		if (!IsValid(shouldBeEmpty) && IsValid(notEmpty) && !IsValid(alsoEmpty)) {
			std::cout << "IsValid dziala ok" << std::endl;
		}
		else {
			std::cout << "IsValid nie dzia�a" << std::endl;
		}
	}

	std::cout << "============= ETAP 4 ==============" << std::endl;
	{
		int val1 = 12;
		int val2 = 28;
		int val3 = 18293;
		unique<int> ptr1(new int(val1));
		unique<int> ptr2(new int(val2));
		unique<int> ptr3(new int(val3));

		auto result = Bigger(std::move(ptr1), std::move(ptr2));
		
		if (*result != 28 || IsValid(ptr1) || IsValid(ptr2)) {
			std::cout << "Nieprawid�owy bigger" << std::endl;
		}

		auto result2 = Bigger(std::move(result), std::move(ptr3));
		if (*result2 != val3 || IsValid(result) || IsValid(ptr3)) {
			std::cout << "Nieprawid�owy bigger2..." << std::endl;
		}

		unique<int> equal1(new int(val1));
		unique<int> equal2(new int(val1));

		auto result3 = Bigger(std::move(equal1), std::move(equal2));
		if (IsValid(result3) || !IsValid(equal1) || !IsValid(equal2)) {
			std::cout << "Nieprawid�owy bigger3..." << std::endl;
		}
	}

	std::cout << std::endl;
	return 0;
}