// ITMO.SoftwareEng2023.C++
// Практическое занятие 9. Обработка исключительных операций
// Контрольные задания.
// Задание 1. Безопасная реализация класса Triangle
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class InvalidLength
{
public:
	InvalidLength() : message("Сторона треугольника недопустимой длины") {}
	void printMessage() const { cout << message << endl; }

private:
	string message;
};

class Triangle
{
public:
	Triangle(double as, double bs, double cs)
	{
		a = as;
		b = bs;
		c = cs;
	}

	double funSquare()
	{
		if (a > b + c || b > a + c || c > a + b)
			throw InvalidLength();
		double pp = 0.5 * (a + b + c); // Полупериметр треугольника
		double sq = sqrt(pp * (pp - a) * (pp - b) * (pp - c)); // Площадь треугольника
		return sq;
	}

private:
	double a;
	double b;
	double c;
};

int main()
{
	system("chcp 1251");
	//Triangle tr(4.717, 4.717, 5);  // Площадь треугольника равна 10
	Triangle tr(20, 20, 100);        // ERROR

	try
	{
		cout << "Площадь треугольника: " << tr.funSquare() << endl;
	}
	catch (InvalidLength& error)
	{
		cout << "ОШИБКА ВХОДНЫХ ДАННЫХ: ";
		error.printMessage();
		return 1;   // завершение программы при ошибке
	}
	return 0;       // нормальное завершение программы
}