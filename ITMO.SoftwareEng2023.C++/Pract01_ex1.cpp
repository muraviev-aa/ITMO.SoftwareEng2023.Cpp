// ITMO.SoftwareEng2023.C++
// Практическое занятие 1. Организация ввода-вывода данных
// Упражнение 1. Ввод-вывод данных

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string name;
	cout << "What is your name? \n";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}