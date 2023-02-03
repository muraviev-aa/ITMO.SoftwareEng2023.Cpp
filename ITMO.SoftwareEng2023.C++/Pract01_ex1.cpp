// ITMO.SoftwareEng2023.C++
// Практическое занятие 1. Организация ввода-вывода данных. 
// Упражнение 1. Ввод-вывод данных
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cout << "What is your name? \n";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}