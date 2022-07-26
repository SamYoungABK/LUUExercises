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
		factors[i - 1] == true ? (printf("%d ", i)) : 0;
}

bool* GenerateFactors(int numberToFactor) {
	bool* factors = new bool[numberToFactor];

	for (int i = 1; i <= numberToFactor; i++)
		numberToFactor% i == 0 ? factors[i - 1] = true : factors[i - 1] = false;

	return factors;
}