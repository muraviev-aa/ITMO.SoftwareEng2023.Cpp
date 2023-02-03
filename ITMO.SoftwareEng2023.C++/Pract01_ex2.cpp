// ITMO.SoftwareEng2023.C++
// Практическое занятие 1. Организация ввода-вывода данных. 
// Упражнение 2. Преобразование типов данных
//

#include <iostream>

using namespace std;

int main() 
{
	system("chcp 1251");
	string name;
	cout << "Введите свое имя\n";
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a
	cin >> name;
	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << "Привет, " << name << "!\n";
	cout.precision(3);
	cout << sizeof(a / b) << ends << sizeof(x) << endl;
	return 0;
}