#include "knight_move.hpp"
#include <iomanip>
#include <iostream>
using namespace std;
void KnightMoveSolver::PrintSolution(int xSize, int ySize, const Solution &solution)
{
	auto it = solution.begin();
	//cout << setw(3);
	for (int i = ySize-1; i >=0; i--)
	{ 
		for (int j = 0; j < xSize; j++)
		{
			cout << setw(3);
			cout << *(it + i*xSize + j) << " ";
		}
		cout << endl;
	}

}



Solution KnightMoveSolver::Solve(int xSize,  int ySize, int x, int y,
                                 const Solution &initialFields)
{
    return {};
}
void rekur(int a, int b, int j, int i, vector<int>& obecny,vector<int>& naj,int p)
{
	vector<int> z(a*b);
	if (p == a*b)
		return;

	if (j + 1 < a && i - 2 >= 0)
	{
		
		if (obecny[(i - 2)*a + j + 1] == 0)
		{
			obecny[i*a+ j] = p;
			obecny[(i - 2)*a + j + 1] = p + 1;
			rekur(a, b, j + 1, i - 2, obecny,naj, p+1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			p--;
			return;
		}
	}
	if (j + 2 < a && i - 1 >= 0)
	{
		

		if (obecny[(i - 1)*a + j + 2] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i - 1)*a + j + 2] = p + 1;
			rekur(a, b, j + 2, i - 1, obecny,naj, p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			p--;
			return;

		}
	}
	if (j + 2 < a && i + 1 < b)
	{
		

		if (obecny[(i + 1)*a + j + 2] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i + 1)*a + j + 2] = p + 1;
			rekur(a, b, j + 2, i + 1, obecny, naj,p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			p--;
			return ;

		}
	}
	if (j + 1 < a && i + 2 < b)
	{


		if (obecny[(i + 2)*a + j + 1] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i + 2)*a + j + 1] = p + 1;
			rekur(a, b, j + 1, i + 2, obecny,naj, p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			
		

		}
	}
	if (j - 1 >= 0 && i - 2 >= 0)
	{

		if (obecny[(i - 2)*a + j - 1] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i - 2)*a + j - 1] = p + 1;
			rekur(a, b, j - 1, i - 2, obecny,naj, p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			

		}
	}
	if (j - 2 >= 0 && i - 1 >= 0)
	{
		
		if (obecny[(i - 1)*a + j - 2] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i - 1)*a + j - 2] = p + 1;
			rekur(a, b, j -2, i - 1, obecny, naj,p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
		
		}
	}
	if (j - 2 >= 0 && i + 1 < b)
	{
		

		if (obecny[(i + 1)*a + j - 2] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i + 1)*a + j -2] = p + 1;
			rekur(a, b, j -2, i + 1, obecny,naj, p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			

		}
	}
	if (j - 1 >= 0 && i + 2 < b)
	{


		if (obecny[(i + 2)*a + j - 1] == 0)
		{
			obecny[i*a + j] = p;
			obecny[(i + 2)*a + j - 1] = p + 1;
			rekur(a, b, j - 1, i + 2, obecny, naj, p + 1);
			int max1 = 0;
			int max2 = 0;
			for (int s = 0; s < a*b; s++)
				if (max1 < obecny[s])
					max1 = obecny[s];
			for (int s = 0; s < a*b; s++)
				if (max2 <naj[s])
					max2 = naj[s];
			if (max2 < max1)
				naj = obecny;
			
		}
	}
	else
	{
		obecny[i*a + j] = p;
		
		return;
	}

}
Solution KnightMoveSolver::Solve(int xSize, int ySize, int x, int y)
{
	vector<int> obecny(xSize*ySize);
	vector<int> naj(xSize*ySize);
	for (int i = 0; i<ySize; i++)
		for (int j = 0; j < xSize; j++)
		{
			rekur(xSize, ySize, i, j, obecny,naj, 1);
		}

	return Solution(naj);
}