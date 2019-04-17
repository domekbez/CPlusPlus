
#include "Interpreter.hpp"

namespace SimpleInterpreter
{
#pragma region Etap 0
	
	// Konwertuje tekst na float. Jesli sie nie da, to rzuca wyjatkiem.
	float Interpreter::StringToFloat(const std::string& valueStr)
	{
		float value;
		std::stringstream stream{ valueStr };
		if (!(stream >> value))
			throw std::runtime_error{ "Invalid value" };

		return value;
	}

	// Konwertuje float na tekst
	std::string Interpreter::FloatToString(float value)
	{
		std::stringstream stream;
		stream << value;
		return stream.str();
	}

	// Wykonuje funkcje odpowiadajaca podanej operacji.
	void Interpreter::ExecuteOperation(const Operation& operation)
	{
		switch (operation.OperationType)
		{
			case OperationTypes::CreateVariable:
			CreateVariable();
			break;

			case OperationTypes::RemoveVariable:
			RemoveVariable();
			break;

			case OperationTypes::Store:
			Store();
			break;

			case OperationTypes::Push:
			Push(operation.Param);
			break;

			case OperationTypes::Print:
			Print();
			break;

			case OperationTypes::Add:
			Add();
			break;

			case OperationTypes::Subtract:
			Subtract();
			break;

			case OperationTypes::Multiply:
			Multiply();
			break;

			case OperationTypes::Divide:
			Divide();
			break;

			default:
			throw std::runtime_error{ "Invalid operation" };
		}
	}

	std::ostream& operator << (std::ostream& out, const Interpreter& interpreter)
	{
		out << "VARIABLES:" << std::endl;
		interpreter.PrintVariables(out);

		out << "OPERATIONS:" << std::endl;
		interpreter.PrintOperations(out);

		out << "OPERATIONS QUEUE:" << std::endl;
		interpreter.PrintOperationsQueue(out);

		out << "DATA STACK:" << std::endl;
		interpreter.PrintDataStack(out);

		return out;
	}

#pragma endregion

#pragma region Etap 1

	// Etap 1:
	// Zwracana jest wartoœæ ze szczytu stosu (przekonwertowana ze string na float).
	// Etap 2:
	// Jesli wartosc na szczycie stosu to nazwa zmiennej, to zwraca jej wartosc.
	// W przeciwnym wypadku zwraca wartoœæ ze stosu (przekonwertowana ze string na float).
	float Interpreter::PopValue()
	{
		if (stos.empty())
			return 0.0f;
		std::string a = stos.top();
		if (multi.find(a) == multi.end())

		{
			float b = StringToFloat(a);

			stos.pop();
			return b;
		}
		else
		{
			stos.pop();
			return (--multi.upper_bound(a))->second;
		}


		// Etap 1
		// Etap 2
		return 0.0f;
	}

	// Zamienia wartosc na string i wrzuca na stos.
	void Interpreter::PushValue(float value)
	{
		std::string a = FloatToString(value);
		stos.push(a);
		// Etap 1
	}

	// Wrzuca string na stos.
	void Interpreter::Push(const std::string& param)
	{
		stos.push(param);
		// Etap 1
	}
	
	// Sciaga 2 elementy ze stosu, dodaje je, wynik zapisuje na stosie.
	void Interpreter::Add()
	{
		float c = PopValue();
		c += PopValue();
		PushValue(c);

		// Etap 1
	}

	// Sciaga 2 elementy ze stosu, odejmuje od pierwszego drugi, wynik zapisuje na stosie.
	void Interpreter::Subtract()
	{
		float c = PopValue();
		c -= PopValue();
		PushValue(c);
		// Etap 1
	}

	// Sciaga 2 elementy ze stosu, mnozy pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Multiply()
	{
		float c = PopValue();
		c *= PopValue();
		PushValue(c);
		// Etap 1
	}

	// Sciaga 2 elementy ze stosu, dzieli pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Divide()
	{
		float c = PopValue();
		c /= PopValue();
		PushValue(c);
		// Etap 1
	}
	
	void Interpreter::PrintDataStack(std::ostream& out) const
	{
		int i = 0;
		std::stack<std::string> pom = stos;
		while (!pom.empty())
		{
			out << i << ". " << pom.top() << std::endl;
			pom.pop();
			i++;
		}
		// Etap 1
	}

#pragma endregion

#pragma region Etap 2

	// Zwraca string ze szczytu stosu
	std::string Interpreter::PopName()
	{
		if (!stos.empty())
		{
			
			std::string a=stos.top();
			stos.pop();
			return a;
		}
		// Etap 2
		return "";
	}

	// Pobiera nazwe zmiennej ze stosu, nastepnie jej wartosc i tworzy zmienna.
	void Interpreter::CreateVariable()
	{
		std::string a = PopName();
		float b = PopValue();
		multi.insert(make_pair(a, b));

		// Etap 2
	}

	// Pobiera nazwe zmiennej ze stosu i usuwa ja.
	void Interpreter::RemoveVariable()
	{
		std::string a = PopName();
		multi.erase((--multi.upper_bound(a)));
		// Etap 2
	}

	// Pobiera nazwe zmiennej ze stosu, pobiera wartosc ze stosu i przypisuje zmiennej wartosc.
	void Interpreter::Store()
	{
	
		std::string a = PopName();
		float b = PopValue();
		(--multi.upper_bound(a))->second = b;
		// Etap 2
	}
	
	// Sciaga wartosc ze stosu i ja drukuje na ekran.
	void Interpreter::Print()
	{
		
		std::cout << PopValue() << std::endl;
		
		// Etap 2
	}
	
	void Interpreter::PrintVariables(std::ostream& out) const
	{
		std::cout << std::endl;
		std::for_each(multi.begin(), multi.end(), [&](const std::pair<std::string, float>& para) {out << para.first << "  " << para.second << " "; });
		std::cout << std::endl;
		// Etap 2
	}

#pragma endregion

#pragma region Etap 3

	void Interpreter::SetOperations(const std::vector<Operation>& operations)
	{
		// Etap 3
	}

	// Wykonuje caly program
	void Interpreter::Execute()
	{
		// Etap 3
	}

	void Interpreter::PrintOperations(std::ostream& out) const
	{
		// Etap 3
	}

	void Interpreter::PrintOperationsQueue(std::ostream& out) const
	{
		// Etap 3
	}

#pragma endregion

#pragma region Etap 4

	void Interpreter::ParseOperations(const std::vector<std::pair<std::string, std::string>>& operations)
	{
		// Etap 4
	}

#pragma endregion
}
