﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 4. Использование указателей и ссылок
// Контрольные задания.
// Задание 2. Реализация ввода данных
//

#include <iostream> 
using namespace std;

bool Input(int&, int&);

int main()
{
	system("chcp 1251");
	int av = 0;
	int bv = 0;
	//cout << "Введите значения чисел a и b через пробел: " << endl;
	//cin >> a >> b;

	if (!Input(av, bv))
	{
		cerr << "error";
		return 1;
	}

	int s = av + bv;
	cout << s << endl;
	return 0;
}

bool Input(int &a, int &b)
{
	cout << "Введите значения чисел a и b через пробел: " << endl;
	cin >> a >> b;
	return a == b;
}