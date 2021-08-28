#include <iostream>
#include <list>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double average{};
	list<double> numbers{ 828.75, 254.33, -133.55, 982.64, -71.83, 817.54, 610.31, -451.72,
		593.17, 200.40, 524.77, 924.66, 162.22, -15.35, 267.40, 147.24 };
	for (auto n : numbers)
	{
		average += n;
	}
	average/= numbers.size();
	numbers.push_back(average);
	cout << "Список со средним значением всех элементов в конце:" << endl;
	for (auto n : numbers)
	{
		cout << n << "\t";
	}
	return 0;
}