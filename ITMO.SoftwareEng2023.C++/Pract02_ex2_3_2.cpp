﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Реализация управляющих операторов
// Упражнение 2. Использование циклов при реализации алгоритмов
// Задание 3. Сравнение типов цикла
// Подзадание 2. Реализуйте задачу второго задания с помощью цикла с постусловием.
// 

#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	do
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	} while (a != b);

	cout << "НОД = " << a << endl;
}