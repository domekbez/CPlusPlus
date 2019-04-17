#pragma once
#include <vector>

// y*xSize + x
// czyli wektor zorganizowany jest wierszami
using Solution = std::vector<int>;

class KnightMoveSolver {

	std::vector<int> board;

public:

	static Solution Solve(int xSize,
		int ySize, int x, int y);
	static Solution Solve( int xSize,
		int ySize, int x, int y,
		const Solution &initialFields);
	static void PrintSolution(int x, int y,
		const Solution &solution);
	/*int operator()(int x, int y)
	{
		return 
	}
*/

};
