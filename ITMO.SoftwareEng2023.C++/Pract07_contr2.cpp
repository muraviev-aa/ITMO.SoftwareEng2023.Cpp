// ITMO.SoftwareEng2023.C++
// Практическое занятие 7. Применение структур и кортежей
// Контрольные задания.
// Задание 2. Решение квадратного уравнения
//

#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

struct Solution
{
	double x1;
	double x2;
	int result;
};

Solution funcSolution(int a, int b, int c)
{
	Solution s;
	int d = pow(b, 2) - 4 * a * c;
	if (d > 0)
	{
		s.x1 = (-b + sqrt(d)) / (2 * a);
		s.x2 = (-b - sqrt(d)) / (2 * a);
		s.result = 2;
	}
	else if (d == 0)
	{
		s.x1 = -b / (2 * a);
		s.result = 1;
	}
	else
	{
		s.result = 0;
	}
	return s;
}

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
	Solution s = funcSolution(a, b, c);

	if (s.result == 2)
	{
		cout << "Решение уравнения имеет два корня: " << s.x1 << " и " << s.x2 << endl;
	}
	else if (s.result == 1)
	{
		cout << "Решение уравнения имеет один корень: " << s.x1 << endl;
	}
	else
	{
		cout << "Уравнение не имеет решения." << endl;
	}
}