#include <iostream>

int cube(int x);

int main()
{
	int userInput = 0;

	std::cout << "Enter value to cube: " << std::endl;
	std::cin >> userInput;
	std::cout << cube(userInput) << std::endl;
}

int cube(int x)
{
	if (x == 0) return 1;

	return x * x * x;
}