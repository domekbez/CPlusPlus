
#include <algorithm>
#include <iostream>

#include "knight_move.hpp"

// Testing utils
using Solver = KnightMoveSolver;

int SolutionSize(const Solution &s) {
	int num = 0;
	for (const auto& elem : s) {
		if (elem > 0) {
			num++;
		}
	}
	return num;
}

void CheckSolution(unsigned int xSize, unsigned int ySize,
	const Solution &solution, int properSize) {
	if (SolutionSize(solution) != properSize) {
		std::cout << " Zla wielkosc rozwiazania!" << std::endl;
		if (properSize == 0) {
			std::cout << "Oczekiwane pustego rozwiazania. Otrzymano:\n";
		}
	}
	if (solution.size() > 0) {
		Solver::PrintSolution(xSize, ySize, solution);
	}
}

void StartCase() {
	static unsigned int caseId = 1;
	std::cout << " Testcase " << caseId
		<< "======================================\n";
	caseId++;
}

template <typename... Args>
void Subcase(unsigned int id, unsigned int properSize, unsigned int xSize,
	unsigned int ySize, Args... args) {
	std::cout << " Subcase " << id << "\n";
	auto sol = Solver::Solve(xSize, ySize, args...);
	CheckSolution(xSize, ySize, sol, properSize);
}

void TestPrint() {
	std::cout << "Print test cases" << std::endl;
	Solution p{
		0,0,0,0,0,// najnizszy wiersz
		1,2,3,4,5,
		-1, -1,-1,-1,6,
		-1, -1, -1, -1,7,
		12,11,10,9,8 // najwyzszy wiersz
	};
	Solver::PrintSolution(5, 5, p);
	std::cout << "test 2:" << std::endl;
	Solution p2(120, 0);
	Solver::PrintSolution(20, 6, p2);
	std::cout << "test 3:" << std::endl;
	Solution p3{
		1,2,3,4,5,6,7,8,9,10,
		20,19,18,17,16,15,14,13,12,11
	};
	Solver::PrintSolution(10, 2, p3);
	std::cout << "test 4, empty:" << std::endl;
	Solution p4{};
	Solver::PrintSolution(0, 0, p4);
	Solver::PrintSolution(0, 6, p4);
	Solver::PrintSolution(3, 0, p4);
}

void Testcase1() {
	StartCase();

	auto xSize = 3;
	auto ySize = 3;

	Subcase(1, 8, xSize, ySize, 0, 0);
	Subcase(2, 8, xSize, ySize, 0, 1);
	Subcase(3, 8, xSize, ySize, 2, 2);
	Subcase(4, 0, xSize, ySize, 1, 1);
}

void Testcase2() {
	StartCase();
	auto xSize = 4;
	auto ySize = 4;

	Subcase(1, 14, xSize, ySize, 0, 0);
	Subcase(2, 14, xSize, ySize, 1, 0);
	Subcase(3, 14, xSize, ySize, 1, 1);
}

void Testcase3() {
	StartCase();
	auto xSize = 3;
	auto ySize = 4;

	Subcase(1, 10, xSize, ySize, 0, 0);
	Subcase(2, 10, xSize, ySize, 0, 1);
	Subcase(3, 8, xSize, ySize, 1, 0);
	Subcase(4, 10, xSize, ySize, 1, 1);

}

void Testcase4() {
	StartCase();
	auto xSize = 5;
	auto ySize = 5;
	Subcase(1, 24, xSize, ySize, 0, 0);

}

void ObstacleTestcase1() {
	StartCase();
	auto xSize = 5;
	auto ySize = 5;

	Solution p = {
		0,0,0,0,0,
		-1, -1, 0, -1, -1,
		-1, 0, 0, -1, -1,
		0,0,0,0,0,
		0,0,0,0,0,
	};
	Subcase(1, 8, xSize, ySize, 0, 0, p);
	Subcase(2, 2, xSize, ySize, 1, 0, p);
	Subcase(3, 8, xSize, ySize, 1, 3, p);
	Subcase(4, 0, xSize, ySize, 0, 1, p);
}

void ObstacleTestcase2() {
	StartCase();
	auto xSize = 10;
	auto ySize = 4;

	Solution p = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, -1,0, -1,0, -1,0, -1,0, -1,
		-1,0, -1,0, -1,0, -1,0, -1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	Subcase(1, 20, xSize, ySize, 0, 0, p);
	Subcase(2, 20, xSize, ySize, 0, 1, p);
	Subcase(3, 20, xSize, ySize, 1, 2, p);
}

void ObstacleTestcase3() {
	StartCase();
	auto xSize = 7;
	auto ySize = 3;

	Solution p = {
		-1,0,0,-1,0,0,0,
		0,0,0,0,0,0,0,
		0,0,-1,-1,0,0,0
	};

	Subcase(1, 12, xSize, ySize, 1, 0, p);
	Subcase(2, 0, xSize, ySize, 5, 1, p);
	Subcase(3, 12, xSize, ySize, 0, 2, p);
}

void BigTestCase() {
	// oba przypadki to pelne rozwiazania
	StartCase();
	Subcase(1, 30, 5, 6, 0, 0);

	Subcase(2, 36, 6, 6, 0, 0);
}
int main() {
	// krotki test wypisywania
	TestPrint();
	// normalne przypadki testowe
	Testcase1();
	Testcase2();
	Testcase3();
	Testcase4();
	//// przypadki z przeszkodami
	//ObstacleTestcase1();
	//ObstacleTestcase2();
	//ObstacleTestcase3();

	//// Duzy przypadek testowy
	//BigTestCase();
}
