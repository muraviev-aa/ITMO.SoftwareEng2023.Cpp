// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Контрольные задания.
// Задание 3. Работа с различными треугольниками
//

#include <iostream>
#include <string>

using namespace std;

double areaTriangle(double);
double areaTriangle(double, double, double);

int main()
{
	system("chcp 1251");
	double a;
	double b;
	double c;
	int d;
	//cout << "Введите длину стороны треугольника: " << endl;
	//cin >> a;
	cout << "Треугольник равносторонний - введи 1, разносторонний - введи 2" << endl;
	cin >> d;

	if (d == 1)
	{
		cout << "Введите длину стороны равностороннего треугольника: " << endl;
		cin >> a;
		cout << "Площадь равностороннего треугольника: " << areaTriangle(a) << endl;
	}
	else
	{
		cout << "Введите длины сторон разностороннего треугольника через пробел: " << endl;
		cin >> a >> b >> c;
		cout << "Площадь разностороннего треугольника: " << areaTriangle(a, b, c) << endl;
	}
}

double areaTriangle(double a)
{
	return 0.5 * a * sqrt(pow(a, 2) - pow(a, 2) / 4);
}

double areaTriangle(double a, double b, double c)
{
	double p = 0.5 * (a + b + c);
	return sqrt(p * (p - a) * (p - b) * (p - c));
}