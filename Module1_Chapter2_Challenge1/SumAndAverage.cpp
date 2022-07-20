// Gets the sum and average of three numbers.

#include <iostream>

void getInput(int* numberList);
int calculateSum(int* numberList);
double calculateAverage(int* numberList);
void printResult(int sum, double average);


int main()
{
	int numberList[3] = { 0, 0, 0 };
	getInput(numberList);

	int sum = calculateSum(numberList);
	double average = calculateAverage(numberList);

	printResult(sum, average);

	return 0;
}

void getInput(int* numberList)
{
	std::cout << "Enter three numbers: " << std::endl;
	std::cin >> numberList[0] >> numberList[1] >> numberList[2];
}


int calculateSum(int* numberList)
{
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += numberList[i];
	}

	return sum;
}

double calculateAverage(int* numberList)
{
	int sum = calculateSum(numberList);
	double average = (double)sum / 3.0;

	return average;
}

void printResult(int sum, double average)
{
	std::cout << std::endl <<
		"Sum: " << sum << std::endl <<
		"Average: " << average << std::endl;
}