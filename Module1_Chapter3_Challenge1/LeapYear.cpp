#include <iostream>
#include <ctime>

bool IsLeapYear(int year);

int main()
{
	int year = 2022;

	std::cout << "Enter a year to check if it's a leap year: " << std::endl;
	std::cin >> year;

	if (IsLeapYear(year))
		std::cout << year << " is a leap year!" << std::endl;
	else
		std::cout << year << " is not a leap year!" << std::endl;
}

bool IsLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;

	return false;
}