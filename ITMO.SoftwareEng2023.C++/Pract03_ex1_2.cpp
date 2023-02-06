// ITMO.SoftwareEng2023.C++
// Практическое занятие 3. Использование функций 
// Упражнение 1. Использование функции при организации программы
// Задание 2. Реализация возвращения значения функции
//

#include <iostream>
#include <string>

using namespace std;



string privet(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}

int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	string nameOut = privet(name);
	cout << nameOut << endl;
	return 0;
}

