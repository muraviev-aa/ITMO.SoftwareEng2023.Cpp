// ITMO.SoftwareEng2023.C++
// Практическое занятие 6. Работа с файлами
// Контрольные задания.
// Задание 2. Сохранение данных в текстовый файл
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	system("chcp 1251");
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0;
	int buf = 0;

	string fileName = "6_2.txt";
	ofstream before(fileName);
	before << "Массив до сортировки:" << endl;
	for (int i = 0; i < N; i++) {
		before << "a[" << i << "]=" << a[i] << '\t' << endl;
	}
	before.close();

	for (int i = 0; i < N; i++)
	{
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;

		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	ofstream after(fileName, ios::app);
	after << "Массив после сортировки: \n";
	for (int i = 0; i < N; i++) {
		after << "a[" << i << "]=" << a[i] << '\t' << endl;
	}
	after.close();

	for (int i : a)  // для вывода в консоли
		cout << i << '\t';
}