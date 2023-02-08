// ITMO.SoftwareEng2023.C++
// Практическое занятие 4. Использование указателей и ссылок
// Контрольные задания.
// Задание 1. Вычисление корней квадратного уравнения
//

#include <iostream> 
#include <cmath> 
using namespace std;

int Myroot(double, double, double, double&, double&);

int main()
{
	system("chcp 1251");
	double a, b, c;
	double x1;
	double x2;
	int rsl;
	cout << "Введите значения чисел a, b и c через пробел: " << endl;
	cin >> a >> b >> c;
	Myroot(a, b, c, x1, x2);
	rsl = Myroot(a, b, c, x1, x2);

	if (rsl == 2)
	{
		cout << "Корни уравнения: " << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}
	else if (rsl == 1)
	{
		cout << "Корень уравнения один: " << "x1 = x2 = " << x1 << endl; 
	}
	else
	{
		cout << "Корней уравнения нет." << endl;
	}
}

int Myroot(double a, double b, double c, double &x1, double &x2)
{
	double d = pow(b, 2) - 4 * a * c;

	if (d > 0)
	{
		x1 = (- b + sqrt(d)) / (2 * a);
		x2 = (- b - sqrt(d)) / (2 * a);
		return 2;
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		return 1;
	}
	else
	{
		return 0;
	}
}

