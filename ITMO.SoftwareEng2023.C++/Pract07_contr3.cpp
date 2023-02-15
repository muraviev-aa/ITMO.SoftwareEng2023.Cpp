// ITMO.SoftwareEng2023.C++
// Практическое занятие 7. Применение структур и кортежей
// Контрольные задания.
// Задание 3. Решение квадратного уравнения
//

#include <iostream>
#include <windows.h>
#include <tuple>
#include <cmath>
using namespace std;
using Tuple = tuple<double, double, int>;


Tuple funcTuple(int a, int b, int c);

int main()
{
	system("chcp 1251");
	int a, b, c;
	cout << "Введите значение a: " << endl;
	cin >> a;
	cout << "Введите значение b: " << endl;
	cin >> b;
	cout << "Введите значение c: " << endl;
	cin >> c;

	auto tp = funcTuple(a, b, c);             // Возвращение из функции нескольких параметров

	if (get<2>(tp) == 2)
	{
		cout << "Решение уравнения имеет два корня: " << get<0>(tp) << " и " << get<1>(tp) << endl;
	}
	else if (get<2>(tp) == 1)
	{
		cout << "Решение уравнения имеет один корень: " << get<0>(tp) << endl;
	}
	else
	{
		cout << "Уравнение не имеет решения." << endl;
	}
}

Tuple funcTuple(int a, int b, int c)
{
	double x1, x2;
	int d = pow(b, 2) - 4 * a * c;

	if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		return make_tuple(x1, x2, 2);
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		return make_tuple(x1, 0, 1);
	}
	else
	{
		return make_tuple(0, 0, 0);
	}
}
