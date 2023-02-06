// ITMO.SoftwareEng2023.C++
// Дополнительное задание, было дано на втором занятии по C++
// Вычисление квадратного корня
//

#include <iostream>
#include <string>

using namespace std;

double sqrtFunc(double);

int main()
{
	system("chcp 1251");
	double target;        // исходные данные  
	double b;             // выходные данные 
	cout << "Введите число для извлечения из него квадратного корня: " << endl; 
	cin >> target;
	double sqrtFunc(double);
	b = sqrtFunc(target);
	cout << "Корень квадратный из указанного числа: " << b << endl;
}

double sqrtFunc(double target)
{
	double x = 1;
	double oldx;
	do
	{
		oldx = x;
		x = (x + target / x) / 2;

	} while (oldx != x);
		return x;
}