// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций 
// Упражнение 3. Реализация сложных алгоритмов с помощью функций
// Алгоритм бинарного поиска для вычисления корня указанной степени
//

#include <iostream>
#include <string>

using namespace std;

long double firBinSearch(double, int);

int main()
{
	system("chcp 1251");
	double a; // исходные данные
	int n;    // исходные данные
	cout << "Введите число a: " << endl;    // a - действительное, больше или равное 1, не превосходит 1000, 
	cin >> a;                               // задано с точностью до 6 знаков после десятичной точки.
	cout << "Введите число n: " << endl;    // n - натуральное, не превосходящее 10.
	cin >> n;
	long double firBinSearch(double, int);
	cout << "Вычисленное значение: " << firBinSearch(a, n) << endl; // выходные данные
}

long double firBinSearch(double a, int n)
{
	double L = 0;
	double R = a;
	while (R - L > 1e-10)
	{
		double M = (L + R) / 2;
		if (pow(M, n) < a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	return R;
}