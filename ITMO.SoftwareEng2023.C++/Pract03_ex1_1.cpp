// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций 
// Упражнение 1. Использование функции при организации программы
// Задание 1. Реализация процедуры
//

#include <iostream>
#include <string>

using namespace std;

void privet(string);

int main()
{
	string name;
	privet(name);
	cin >> name;
	cout << name << ", " << "hello!" << endl;
	return 0;
}

void privet(string name)
{
	cout << "What is your name?" << endl;
}