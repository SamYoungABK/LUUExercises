#include <iostream>

int main()
{
	int numberToFactor = 0;

	std::cout << "Enter a number to factor: " << std::endl;
	std::cin >> numberToFactor;


	std::cout << "Factors: ";
	for (int i = 1; i < numberToFactor; i++)
	{
		if (numberToFactor % i == 0) std::cout << i << ' ';
	}
}