// ITMO.SoftwareEng2023.C++
// Практическое занятие 4. Использование указателей и ссылок
// Упражнение 2. Реализация функции обмена значений
//

#include <iostream> 
using namespace std;

void swap(int*, int*);
void swap(int&, int&);

int main()
{
	system("chcp 1251");
	int x = 5, y = 10;
	swap(&x, &y);
	swap(x, y);
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}