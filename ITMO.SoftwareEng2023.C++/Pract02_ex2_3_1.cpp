﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Реализация управляющих операторов
// Упражнение 2. Использование циклов при реализации алгоритмов
// Задание 3. Сравнение типов цикла
// Подзадание 1. Реализуйте задачу первого задания с помощью цикла с предусловием.
// 

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	while (x <= x2)
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	}
}