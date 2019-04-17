#include "TeamManager.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
using namespace std;

const vector<char> characters = { '0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F', 'G','H','I','J','K', 'L','M','N','O','P',
'Q','R','S','T','U', 'V','W','X','Y','Z', 'a','b','c','d','e','f',
'g','h','i','j','k', 'l','m','n','o','p', 'q','r','s','t','u',
'v','w','x','y','z' };

void printPeople(std::ostream &stream, const vector<Employee>& people)
{
	std::ostream_iterator<Employee> it(stream, "\n");

	copy(people.begin(), people.end(), it);
}

string GenerateRandomString(int n)
{
	string a;
	generate_n(back_inserter(a), n, []() { int i = rand() % characters.size(); return characters[i]; });
	return a;
}

int main()
{
	srand(5555);

	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL

	cout << "---------------ETAP I------------------" << endl;

	//ETAP I
	//napisać metodę GenerateRandomString, która przyjmuje zadaną długość i na podstawie wektora characters zwraca losowo wygenerowanego stringa
	//podpowiedź wykorzystać generate_n
	cout << GenerateRandomString(10) << endl;
	cout << GenerateRandomString(7) << endl;
	cout << GenerateRandomString(5) << endl;
	cout << GenerateRandomString(3) << endl;
	cout << GenerateRandomString(1) << endl;


	cout << "---------------ETAP II------------------" << endl;

	//ETAP II
	//wektor people1 uzupełnić w następujący sposób
	//-imię pracownika jest losowe (wykorzystaj poprzedni punkt). Nieparzyste pozycje w wektorze mają długość imienia 5, parzyste 10 
	//wykorzystaj zmienną pomocniczą peopleCounter przekazując ją odpowiednio do wyrażenia lambda
	//-wiek pracownika jest równy 22
	//-pensja to zmienna losowa z przedziału [minSalary,maxSalary] 
	//podpowiedź wykorzystać generate
	//UWAGA: losowane wartości to liczby całkowite z rozkładem równomiernym
	//podpowiedź wykorzystać generate i odpowiednie wyrażenie lambda
	vector<Employee> people1(10);

	

	int peopleCounter = 0;

	const int minSalary = 5000;
	const int maxSalary = 15000;
	generate(people1.begin(), people1.end(), [&peopleCounter,minSalary,maxSalary]() 
	{
		string a;
		int b = 22;
		int c = 0;
		if (peopleCounter % 2 == 0)
		{


			c = (rand() % (maxSalary - minSalary + 1)) + minSalary;
			a = GenerateRandomString(10);

		}
		else
		{
			c = (rand() % (maxSalary - minSalary + 1)) + minSalary;
			a = GenerateRandomString(5);
			
		}
		
		//c=(rand() % (maxSalary - minSalary+1)) + minSalary;
		peopleCounter++;
		return Employee(a, b, c);
	}
	);
	//Uzupełnij wnętrze metody printPeople, aby wypisać pracowników na ekran
	printPeople(cout, people1);

	//wektor people2 uzupełnić w następujący sposób
	//-imię pracownika jest losowe o długości 7
	//-wiek pracownika jest losowy z przedziału [minAge,maxAge]
	//-pensja pracownika jest losowa z przedziału [minSalary,maxSalary] 
	//UWAGA: losowane wartości to liczby całkowite z rozkładem równomiernym na zadanym przedziale
	
	vector<Employee> people2(10);
	const unsigned int minAge = 20;
	const unsigned int maxAge = 65;
	generate(people2.begin(), people2.end(), [minAge, maxAge, minSalary, maxSalary]()
	{
		string a = GenerateRandomString(7);

		int b = (rand() % (maxAge - minAge + 1)) + minAge;
		int c = (rand() % (maxSalary - minSalary)) + minSalary;
		return Employee(a, b, c);
	}
	);
	cout << endl;
	printPeople(cout, people2);


	cout << "---------------ETAP III------------------" << endl;

	//ETAP III
	//Do wektora people3 wstawić pracowników z wektora people1 podwyższając im pensję o salaryIncrease,
	//a z wektora people2 pracowników odmłodzonych o 10 lat, pod warunkiem że ich wiek nie zmniejszy się poniżej 20 lat.	
	//podpowiedź: wykorzystaj wartość zwróconą przez transform

	vector<Employee> people3(people1.size() + people2.size());
	const int salaryIncrease = 2000;
	const int ageDecrease = 10;

	//people3.clear();

	
	auto it=transform(people1.begin(), people1.end(), people3.begin(), [salaryIncrease](const Employee& e)
	{
		
		return Employee(e.GetName(), e.GetAge(), e.GetSalary() + salaryIncrease);
		
	}
	);
	transform(people2.begin(), people2.end(), it, [ageDecrease](const Employee& e)
	{
		int z = e.GetAge();
		if (e.GetAge() > 30)
			z -= ageDecrease;
		return Employee(e.GetName(), z, e.GetSalary());
	
	}
	);


	//transform(people1.begin(), people1.end(), back_inserter(people3), [salaryIncrease](Employee& e)
	//{

	//	return Employee(e.GetName(), e.GetAge(), e.GetSalary() + salaryIncrease);
	//}
	//);
	//transform(people2.begin(), people2.end(), back_inserter(people3), [salaryIncrease](Employee& e)
	//{
	//	int z = e.GetAge();
	//	if (e.GetAge() >= 30)
	//		z -= 10;
	//	return Employee(e.GetName(), z, e.GetSalary());
	//}
	//);


	printPeople(cout, people3);

	//Do wektora people4 na koniec wstawić pracowników z people1, którzy zarabiają mniej niż 10000 i są starsi niż 35 lat
	//oraz pracowników z people2, którzy zarabiają mniej niż 7000 i są starsi niż 25 lat
	//użyc tego samego wyrażenia lambda zapisanego do zmiennej, przekazując odpowiednie wartości.
	//podpowiedź: wykorzystaj wartość zwróconą przez copy_if
	//można wykorzystać std::back_inserter

	vector<Employee> people4;

	int salary = 10000;
	unsigned int age = 35;

	//tutaj uzupełnić o kopiowanie z wektora people1
	copy_if(people1.begin(), people1.end(), back_inserter(people4), [salary,age](const Employee& e)
	{
		if (e.GetAge() >= age && e.GetSalary() < salary)
			return true;
		return false;
	}
	);
	salary = 7000;
	age = 25;
	
	//tutaj uzupełnić o kopiowanie z wektora people2
	copy_if(people1.begin(), people1.end(), back_inserter(people4), [salary,age](const Employee& e)
	{
		return (e.GetAge() >= age && e.GetSalary() < salary);
	
	}
	);
	cout << endl;

	printPeople(cout,people4);

	cout << "---------------ETAP IV------------------" << endl;

	//ETAP IV
	//Napisz funkcję CalculateTotalAndAverageSalary przyjmującą wektor pracowników i zwracającą dwie wartości:
	//całkowitą sumę zarobków w zespole oraz średnią zarobków.
	//Dla wektorów people1,people2,people3,people4 wywołać napisaną funkcję i wyświetlić wyniki

	double totalSalary = 0;
	double averageSalary = 0;

	//todo wywolanie funkcji dla people1
	cout << "1. Sum: " << totalSalary << " Average: " << averageSalary << endl;

	//todo wywolanie funkcji dla people2
	cout << "2. Sum: " << totalSalary << " Average: " << averageSalary << endl;

	//todo wywolanie funkcji dla people3
	cout << "3. Sum: " << totalSalary << " Average: " << averageSalary << endl;

	//todo wywolanie funkcji dla people4
	cout << "4. Sum: " << totalSalary << " Average: " << averageSalary << endl;


	cout << "--------------SORTING----------------" << endl;

	//posortować wektor pracowników po imieniu. Uwaga wielkość litery nie powinna mieć znaczenia (podpowiedź: wykorzytaj tolower)


	cout << "--------------ETAP V----------------" << endl;

	//ETAP V
	//uzupełnić klasę TeamManager o publiczną metodę addTeam, która przyjmuje nazwę zadania oraz drużynę (wektor pracowników) odpowiedzialną za zadanie i tworzy odpowiedni wpis w kolekcji
	//w razie pomyślnego dodania wypisać "team for the task was added"
	//w razie istnienia już odpowiedzialnej drużyny dla danego zadania, wypisać na konsolę "team already exists for that task"

	TeamManager teamManager;


	//dodać metodę performLambdaOnTasksTeam do klasy TeamManager, przyjmującą nazwę zadania i wyrażenie lambda, 
	//które podniesie pensję pracowników o zadaną pensję i policzy liczbę pracowników starszych niż zadany wiek.
	//Ilość pracowników spełniających kryterium, ma być zapisana w zmiennej counter

	int counter = 0;
	unsigned int givenAge = 20;

	printPeople(cout,people1);
	
	//Tutaj wywołać funkcję performLambdaOnTasksTeam
	
	cout << "Number of people older than " << givenAge << ": " << counter << endl;

	printPeople(cout, teamManager.getTeam("Programming"));
	
	counter = 0;
	givenAge = 25;
	
	//Tutaj wywołać funkcję performLambdaOnTasksTeam
	
	cout << "Number of people older than " << givenAge << ": " << counter << endl;
	
	return 0;
}