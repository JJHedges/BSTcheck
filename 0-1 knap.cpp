#include <iostream>
#include <vector>
#include <algorithm>

//Solve 0/1 knapsack problem for specified values, weights, capacity and amount of items
int knapSolve(std::vector<int> values, std::vector<int> weights, int capacity, int itemCount)
{
	std::vector<std::vector<int> > dpTable(capacity, std::vector<int>(itemCount, 0));
	
	for(int i = 1; i < itemCount; i++)
	{
		for(int j = 0; j < capacity; j++)
		{
			//If we cannot take the item then
			if(weights[i-1] > j)
			{
				dpTable[i][j] = dpTable[i-1][j];
			}
			//Two options, not taking item or taking item respectively
			else dpTable[i][j] = std::max(dpTable[i-1][j], 
				dpTable[i-1][j-weights[i-1]] + values[i-1]);
		}
	}
	return dpTable[itemCount - 1][capacity - 1];
}

void test1()
{
	std::vector<int> vals = {3, 4, 5, 6};
	std::vector<int> weights = {2, 3, 4, 5};
	if(knapSolve(vals, weights, 5, 4) == 5)
	{
		std::cout << "Correctly found value of best knapsack" << std::endl;
	}
}

int main(int argc, char **argv)
{
	test1();
}
