// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Упражнение 1. Обработка данных массива
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	const int n = 10;    // размер массива
	double m;            // среднее значение элементов массива
	int s = 0;           // cумма всех элементов массива
	int sNegative = 0;   // cумма всех отрицательных элементов массива
	int sPositive = 0;   // cумма всех положительных элементов массива
	int sOdd = 0;        // cумма элементов с нечетными индексами
	int sEven = 0;       // cумма элементов с четными индексами

	int mas[n];

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	for (int i = 0; i < n; i++)
	{
		s += mas[i];
	}
	cout << "Сумма всех элементов массива: "<< s << endl;

	m = (double)s / n;
	cout << "Среднее значение элементов массива: " << m << endl;

	for (int i = 0; i < n; i++)
	{
		if (mas[i] < 0)
		{
			sNegative += mas[i];
		}
		else
		{
			sPositive += mas[i];
		}
	}
	cout << "Сумма всех отрицательных элементов массива: " << sNegative << endl;
	cout << "Сумма всех положительных элементов массива: " << sPositive << endl;

	for (int i = 1; i < n; i = i + 2)
	{
		sOdd += mas[i];
	}
	cout << "Сумма элементов с нечетными индексами: " << sOdd << endl;

	for (int i = 0; i < n; i = i + 2)
	{
		sEven += mas[i];
	}
	cout << "Сумма элементов с четными индексами: " << sEven << endl;
}