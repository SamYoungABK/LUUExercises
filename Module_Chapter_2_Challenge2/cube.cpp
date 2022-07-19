#include <iostream>

int cube(int x) {
	return x * x * x;
}
int main() {
	int userInput;
	std::cout << "Enter value to cube: " << std::endl;
	std::cin >> userInput;
	std::cout << cube(userInput) << std::endl;
}
