#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee() {}
	Employee(const string &Name, const unsigned int &Age, const int& Salary) :
		Name(Name), Age(Age), Salary(Salary)
	{}

	//uzupełnić o brakujące operatory

	friend ostream &operator<<(std::ostream &out, const Employee &in)
	{
		out << setw(10) << in.Name << " " << in.Age << " -- " << in.Salary;
		return out;
	}
	//void SetName(string name) { Name = name; }
	void SetAge(int age) { Age = age; }
	string GetName() const { return Name; }
	int GetSalary() const { return Salary; }
	unsigned int GetAge() const { return Age; }
	void SetSalary(const int newSalary) { Salary = newSalary; }

private:
	string Name;
	int Salary;
	unsigned int Age;
};