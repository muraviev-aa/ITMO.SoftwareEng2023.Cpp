// ITMO.SoftwareEng2023.C++
// Практическое занятие 4. Использование указателей и ссылок
// Контрольные задания.
// Задание 2. Реализация ввода данных
//

#include <iostream> 
using namespace std;

bool Input(int, int);

int main()
{
	system("chcp 1251");
	int a, b;
	cout << "Введите значения чисел a и b через пробел: " << endl;
	cin >> a >> b;

	if (!Input(a, b))
	{
		cerr << "error";
		return 1;
	}

	int s = a + b;
	cout << s << endl;
	return 0;
}

bool Input(int a, int b)
{
	return a == b;
}