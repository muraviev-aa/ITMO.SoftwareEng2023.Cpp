// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций
// Упражнение 4. Применение рекурсивной функции
// Задание 2. Алгоритм Евклида
//

#include <iostream>
#include <string>

using namespace std;

int addNumders(int);
int addNumders(int, int);
int gcd(int, int);

int main()
{
	system("chcp 1251");
	int a;
	int b;
	int с; // второе число для задания интервала
	int m; // для задания 2
	int n; // для задания 2
	cout << "Введите число: " << endl;
	cin >> a;
	int addNumders(int);
	b = addNumders(a);
	cout << b << endl;
	cout << "Введите значение второго числа: " << endl;
	cin >> с;
	int addNumders(int, int);
	cout << "Перегруженный метод: " << addNumders(a, с) << endl;
	cout << "Введите число m: " << endl;
	cin >> m;
	cout << "Введите число n: " << endl;
	cin >> n;
	int gcd(int, int);
	cout << "Алгоритм Евклида: " << gcd(m, n) << endl;
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
		return n + addNumders((n - 1), c);
}

int gcd(int m, int n) // алгоритм Евклида
{
	if (n == 0) return m;
	return gcd(n, m % n);
}