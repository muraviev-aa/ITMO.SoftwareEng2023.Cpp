// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Контрольные задания. 
// Задание 1. Определение простого числа
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int a;
	cout << "Введите a = "; cin >> a;
	
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0)
		{
			cout << "Введенное число не простое." << endl;
			return 0;
		}
	}
	cout << "Введенное число простое." << endl;
	return 0;
}