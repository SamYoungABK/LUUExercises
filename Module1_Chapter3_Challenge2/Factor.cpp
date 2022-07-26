#include <iostream>
#include "Factor.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int numberToFactor = 0;
	bool* factors = nullptr;

	cout << "Enter a number to factor: " << endl;
	cin >> numberToFactor;
	
	factors = GenerateFactors(numberToFactor);
	OutputFactors(numberToFactor, factors);

	delete[] factors;
}

void OutputFactors(int numberToFactor, bool* factors)
{
	for (int i = 1; i <= numberToFactor; i++)
		factors[i] == true ? (printf("%d ", i)) : 0;
}

bool* GenerateFactors(int numberToFactor) {
	// adding +1 to the size since 0 index will not be used
	bool* factors = new bool[numberToFactor+1];

	for (int i = 1; i <= numberToFactor; i++)
		numberToFactor% i == 0 ? factors[i] = true : factors[i] = false;

	return factors;
}