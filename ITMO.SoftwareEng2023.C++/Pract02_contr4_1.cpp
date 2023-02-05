// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Контрольные задания. 
// Задание 4. Стрельба по мишени. Часть 1.
// Мишень - вариант 2.
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int s;           // количество выстрелов
	int summa = 0;   // сумма очков
	int max;         // максимально возможное количество очков
	int middle;      // среднее количество очков
	double x, y;     // координаты выстрела
	double r;        // радиус сектора

	cout << "Введите количество выстрелов "; cin >> s;
	max = s * 10;
	middle = s * 5;

	while (s > 0)
	{
		cout << "Введите координаты x и y выстрела по мишени через пробел\n";
		cin >> x >> y;
		r = sqrt(pow(x, 2) + pow(y, 2));

		if (r <= 3 && r > 2)
		{
			summa += 1;
			s--;
		}
		else if(r <= 2 && r > 1)
		{
			summa += 5;
			s--;
		}
		else if (r <= 1)
		{
			summa += 10;
			s--;
		}
		else
		{
			summa = 0;
			s--;
		}
	}

	cout << "Количество очков: " << summa << endl;

	if (summa < middle)
	{
		cout << "Уровень: новичок." << endl;
	}
	else if (summa >= middle && summa < max)
	{
		cout << "Уровень: просто стрелок." << endl;
	}
	else if (summa >= max)
	{
		cout << "Уровень: снайпер." << endl;
	}
	return 0;
	

	
}