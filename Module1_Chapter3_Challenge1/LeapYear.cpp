#include <iostream>

bool isLeapYear(int year);

int main() {
	int year;

	std::cout << "Enter the current year: " << std::endl;
	std::cin >> year;

	if (isLeapYear(year)) {
		std::cout << year << " is a leap year!" << std::endl;
	}
	else {
		std::cout << year << " is not a leap year!" << std::endl;
	};
}

bool isLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	if (year % 100 == 0) {
		return false;
	}
	if (year % 4 == 0) {
		return true;
	}
	return false;
}