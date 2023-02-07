// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Контрольные задания.
// Задание 4. Рекурсивная функция суммы ряда
//

#include <iostream>
#include <string>

using namespace std;

int func(int);

int main()
{
	system("chcp 1251");
	int n;
	cout << "Введите значение n: " << endl;
	cin >> n;
	cout << "Сумма ряда равна: " << func(n) << endl;
}

int func(int n)
{
	if (n == 0) return 5;
	else 5 + func(n - 1);
}