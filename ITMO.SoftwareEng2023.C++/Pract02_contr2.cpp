// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Контрольные задания. 
// Задание 2. Проверка номера СНИЛС
//

#include <iostream> 
using namespace std;

const unsigned int ARRSIZE = 11;
int ary[ARRSIZE];

int main()
{
	system("chcp 1251");
	int result = 0;          // сумма
	int rsl;                 // контрольное число
	double ost;              // остаток

	for (unsigned int i = 0; i < ARRSIZE; i++) {
		cout << "Введите цифру номера СНИЛС " << i << ": ";
		cin >> ary[i];
	}

	for (unsigned int i = 0; i < ARRSIZE; i++) {
		result += (ARRSIZE - i) * ary[i];
	}

	if (result == 100 || result == 101)
	{
		rsl = 00;
	}
	else if (result > 101) 
	{
		ost = result / 101;
		if (ost < 100)
		{
			rsl = ost;
		}
		else if (ost == 100)
		{
			rsl = 00;
		}
	}
	else
	{
		rsl = result;
	}
	
	
	if (rsl == ary[9] * 10 + ary[10])
	{
		cout << "Номер валидный" << endl;
	}
	else
	{
		cout << "Номер не валидный" << endl;
	}

	
	
}