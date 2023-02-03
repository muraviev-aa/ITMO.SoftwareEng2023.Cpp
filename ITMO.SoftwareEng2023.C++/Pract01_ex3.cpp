// ITMO.SoftwareEng2023.C++
// Практическое занятие 1. Организация ввода-вывода данных. 
// Упражнение 3. Расчет площади треугольника
//

#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	double perimetr, a; // периметр, сторона
	cout << "Введите значение периметра\n";
	cin >> perimetr; // ввод с клавиатуры значения периметра
	double s = sqrt(perimetr / 2 * pow((perimetr / 2 - perimetr / 3), 3)); // вычисление значения площади треугольника
	a = perimetr / 3; // вычисление значения длины стороны треугольника
	printf("%7s  %7s", "Сторона", "Площадь\n"); // вывод в виде таблицы
	printf("%7.2lf  %7.2lf", a, s); // вывод в виде таблицы
	return 0;
}