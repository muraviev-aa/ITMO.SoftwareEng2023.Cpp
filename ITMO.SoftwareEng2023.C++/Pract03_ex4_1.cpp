// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Упражнение 4. Применение рекурсивной функции
// Задание 1. Сумма чисел. Алгоритм вычисления суммы чисел от 1 до любого целого положительного числа n.
//

#include <iostream>
#include <string>

using namespace std;

int addNumders(int);
int addNumders(int, int);

int main()
{
	system("chcp 1251");
	int a;
	int b;
	int с; // второе число для задания интервала
	cout << "Введите число: " << endl;
	cin >> a;
	int addNumders(int);
	b = addNumders(a);
	cout << b << endl;
	cout << "Введите значение второго числа: " << endl;
	cin >> с;
	int addNumders(int, int);
	cout << "Перегруженный метод: " << addNumders(a, с) << endl;
	cout << "Перегруженный метод: " << a << " ; " << с << endl;
}

int addNumders(int n)
{
	if (n == 1) return 1; // выход из рекурсии
	else return (n + addNumders(n - 1));
}

int addNumders(int n, int c)
{
	if (n == 1) return 1; // выход из рекурсии
	else if (n - 1 >= c)
		return (n + addNumders((n - 1), c));
}