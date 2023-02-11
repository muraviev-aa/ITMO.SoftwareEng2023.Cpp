// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Контрольные задания.
// Задание 1_1. Передача массива в функцию
//

#include <iostream> 
using namespace std;

int funcSum(int mas[], int n);
double funcMiddle(int mas[], int n);
int funcNegative(int mas[], int n);
int funcPositive(int mas[], int n);
int funcOdd(int mas[], int n);
int funcEven(int mas[], int n);

int main()
{
	system("chcp 1251");
	const int n = 10;    // размер массива
	int mas[n];

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	funcSum(mas, n);        // cумма всех элементов массива
	cout << "Сумма всех элементов массива: " << funcSum(mas, n) << endl;
	funcMiddle(mas, n);     // среднее значение элементов массива
	funcNegative(mas, n);   // cумма всех отрицательных элементов массива
	funcPositive(mas, n);   // cумма всех положительных элементов массива
	funcOdd(mas, n);        // cумма элементов с нечетными индексами
	funcEven(mas, n);       // cумма элементов с четными индексами
}

int funcSum(int mas[], int n)
{
	int s = 0;           // cумма всех элементов массива
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
	}
	return s;
}

double funcMiddle(int mas[], int n)
{
	double m;            // среднее значение элементов массива
	m = (double)funcSum(mas, n) / n;
	cout << "Среднее значение элементов массива: " << m << endl;
	return m;
}

int funcNegative(int mas[], int n)
{
	int sNegative = 0;   // cумма всех отрицательных элементов массива
	for (int i = 0; i < n; i++)
	{
		if (mas[i] < 0)
		{
			sNegative += mas[i];
		}
	}
	cout << "Сумма всех отрицательных элементов массива: " << sNegative << endl;
	return sNegative;
}

int funcPositive(int mas[], int n)
{
	int sPositive = 0;   // cумма всех положительных элементов массива
	for (int i = 0; i < n; i++)
	{

		if (mas[i] > 0)
		{
			sPositive += mas[i];
		}
	}
	cout << "Сумма всех положительных элементов массива: " << sPositive << endl;
	return sPositive;
}

int funcOdd(int mas[], int n)
{
	int sOdd = 0;        // cумма элементов с нечетными индексами
	for (int i = 1; i < n; i = i + 2)
	{
		sOdd += mas[i];
	}
	cout << "Сумма элементов с нечетными индексами: " << sOdd << endl;
	return sOdd;
}

int funcEven(int mas[], int n)
{
	int sEven = 0;       // cумма элементов с четными индексами
	for (int i = 0; i < n; i = i + 2)
	{
		sEven += mas[i];
	}
	cout << "Сумма элементов с четными индексами: " << sEven << endl;
	return sEven;
}

