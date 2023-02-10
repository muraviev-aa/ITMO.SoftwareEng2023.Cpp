// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Упражнение 4_3. Реализация динамического массива
//

#include <iostream> 
using namespace std;

void show_array(int mas[], int n);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);
void bubble_sort(int mas[], int n, bool (*compare)(int a, int b));

int main()
{
	system("chcp 1251");
	int n = 0;              // размер массива
	int my_choose = 0;

	cout << "Введите необходимый размер массива: " << n << endl;
	cin >> n;

	int* mas = new int[n];  // динамический массив
	cout << "Введите значения элементов:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	cout << "1. Сортировать по возрастанию\n";
	cout << "2. Сортировать по убыванию\n";
	cin >> my_choose;
	cout << "Исходные данные: ";
	show_array(mas, n);
	switch (my_choose)
	{
	case 1: bubble_sort(mas, n, from_min); break;
	case 2: bubble_sort(mas, n, from_max); break;
	default: cout << "\rНеизвестная операция ";
	}
	show_array(mas, n);
	return 0;
}

void show_array(int mas[], int n)
{
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << "\n";
}

bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int mas[], int n, bool (*compare)(int a, int b))
{
	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < n - 1;j++)
		{
			if ((*compare)(mas[j], mas[j + 1])) swap(mas[j], mas[j + 1]);
		}
	}
}






