// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Упражнение 5. Применение структур данных для хранения элементов
// Задание 2. Сохранение набора результатов неизвестного размера
//

#include <iostream> 
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));
	vector<int> v1; 
	vector<int> v2;
	int a, b, c;
	int k = 0, n = 10;

	for (int i = 1;i <= n;i++)
	{
		// инициализация операндов случайными числами от 1 до 101
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		if (a * b != c)
		{
			v2.push_back(c);
			k++; // операция «инкремент», аналогично: k = k + 1
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
		else 
		{ 
			v1.push_back(c); 
		}
	}
	cout << "\nGood: "; 
	for (int i = 0; i < v1.size(); i++) 
	{ 
		cout << v1[i] << ends; 
	} 
	
	cout << "\nBad: "; 
	for (int i = 0; i < v2.size(); i++) 
	{ 
		cout << v2[i] << ends; 
	}

	cout << "Count error: " << k << endl;
	return 0;
}