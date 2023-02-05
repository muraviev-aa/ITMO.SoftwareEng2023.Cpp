// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Контрольные задания. 
// Задание 4. Стрельба по мишени. Часть 2. Обязательные задания.
// Мишень - вариант 2.
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int v;           // количество очков
	int s = 0;       // количество выстрелов
	int summa = 0;   // сумма очков
	int max;         // максимально возможное количество очков
	int middle;      // среднее количество очков
	double x, y;     // координаты выстрела
	double r;        // радиус сектора

	cout << "Введите необходимое количество очков "; cin >> v;
	

	while (v > 0)
	{
		cout << "Введите координаты x и y выстрела по мишени через пробел\n";
		cin >> x >> y;
		r = sqrt(pow(x, 2) + pow(y, 2));
		s++;

		if (r <= 3 && r > 2)
		{
			summa += 1;
			v -= 1;
		}
		else if (r <= 2 && r > 1)
		{
			summa += 5;
			v -= 5;
		}
		else if (r <= 1)
		{
			summa += 10;
			v -= 10;
		}
		else
		{
			summa = 0;
			v = 0;
		}
	}

	cout << "Количество выстрелов: " << s << endl;
	max = s * 10;
	middle = s * 5;

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