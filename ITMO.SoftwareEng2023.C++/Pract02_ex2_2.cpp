// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Реализация управляющих операторов
// Упражнение 2. Использование циклов при реализации алгоритмов
// Задание 2. Использование цикла с предусловием
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	system("chcp 1251");
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	while (a != b) // алгоритм Евклида
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	cout << "НОД = " << a << endl;
}