// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Контрольные задания.
// Задание 2. Применение итерации реализации функции
//

#include <iostream>
#include <string>

using namespace std;

double cubicRoot(double);
double cubicRoot(double, double);

int main()
{
	system("chcp 1251");
	double a;
	double b = 3;
	cout << "Введите число: " << endl;
	cin >> a;
	cout << "Первый вариант вычисления: " << cubicRoot(a) << endl;
	cout << "Второй вариант вычисления: " << cubicRoot(a, b) << endl;
}

double cubicRoot(double a)
{
	return pow(a, 1.0 / 3);
}


double cubicRoot(double a, double b)
{
	return (2 * b + a / pow(b, 2)) / 3;
}