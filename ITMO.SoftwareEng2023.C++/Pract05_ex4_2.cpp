// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Упражнение 4_2. Реализация динамического массива
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int n = 0;    // размер массива
	int min = 0;
	int buf = 0;

	cout << "Введите необходимый размер массива: " << n << endl;
	cin >> n;

	int* mas = new int[n];  // динамический массив
	cout << "Введите значения элементов:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	for (int i = 0; i < n; i++)
	{
		min = i;

		for (int j = i + 1; j < n; j++)
			min = (mas[j] < mas[min]) ? j : min;

		if (i != min)
		{
			buf = mas[i];
			mas[i] = mas[min];
			mas[min] = buf;
		}
	}

	for (int i = 0; i < n; i++)
		cout << mas[i] << '\t';

	delete[]mas; // освобождение динамической памяти
	return 0;
}