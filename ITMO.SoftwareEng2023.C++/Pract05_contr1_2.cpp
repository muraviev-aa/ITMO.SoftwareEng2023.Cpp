// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Контрольные задания.
// Задание 1_2. Передача массива в функцию
//

#include <iostream> 
using namespace std;

int* funcSort(int a[], int N);


int main()
{
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

	funcSort(a, N);
}

int* funcSort(int a[], int N)
{
	int min = 0;
	int buf = 0;
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

	for (int i = 0; i < N; i++)
		cout << a[i] << '\t';

	return a;
}