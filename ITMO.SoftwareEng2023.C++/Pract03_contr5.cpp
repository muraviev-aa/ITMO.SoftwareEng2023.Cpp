// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Контрольные задания.
// Задание 5. Применение рекурсии для перевода целого числа в двоичный код
//

#include <iostream>
#include <string>

using namespace std;

int rec(int);

int main()
{
	system("chcp 1251");
	cout << "Введите число" << endl;
	int a;
	cin >> a;
	rec(a);
}

int rec(int a)
{
	if (a > 0)
	{
		rec(a / 2);
		cout << a % 2;
		return a;
	}
}