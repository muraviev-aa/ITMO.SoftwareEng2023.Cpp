// ITMO.SoftwareEng2023.C++
// Практическое занятие 4. Использование указателей и ссылок
// Упражнение 2. Реализация функции обмена значений
//

#include <iostream> 
using namespace std;

void swap(int*, int*);
void swap(int&, int&);
void print(int x, int y);

int main()
{
	int x = 5, y = 10;
	print(x, y);

	swap(&x, &y);  // Передача в функцию параметра указателя
	print(x, y);

	swap(x, y);    // Передача в функцию параметра ссылки
	print(x, y);
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void print(int x, int y)
{
	cout << "x = " << x << "; y = " << y << endl;
}