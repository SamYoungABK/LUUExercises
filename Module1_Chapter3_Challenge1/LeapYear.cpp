#include <iostream>
#include <ctime>

bool isLeapYear(int year);

int main()
{
	time_t now;
	time(&now);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);

	int year = 1900 + timeinfo.tm_year;

	std::cout << "Enter the year to check if it's a leap year (Default: " <<
		year << "): " << std::endl;
	std::cin >> year;

	if (isLeapYear(year))
	{
		std::cout << year << " is a leap year!" << std::endl;
	}
	else
	{
		std::cout << year << " is not a leap year!" << std::endl;
	};
}

bool isLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}