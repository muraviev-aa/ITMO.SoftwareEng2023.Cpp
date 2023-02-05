// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Контрольные задания. 
// Задание 3. Размен монет
//

#include <iostream> 
using namespace std;

int many[] = {1, 2, 5, 10}; // перечень номинальных значений монет

int main()
{
	system("chcp 1251");
	int s;   // сумма
	cout << "Введите сумму "; cin >> s;
	int res10 = s / many[3];
	cout << "Монеты номиналом 10 руб: " << res10 << " шт." << endl;

	if ((s - res10 * many[3]) > 0)
	{
		int res5 = ((s - res10 * many[3]) / many[2]);
		cout << "Монеты номиналом 5 руб: " << res5 << " шт." << endl;

		if ((s - res10 * many[3] - res5 * many[2]) > 0)
		{
			int res2 = ((s - res10 * many[3] - res5 * many[2]) / many[1]);
			cout << "Монеты номиналом 2 руб: " << res2 << " шт." << endl;

			if ((s - res10 * many[3] - res5 * many[2] - res2 * many[1]) > 0)
			{
				int res1 = ((s - res10 * many[3] - res5 * many[2] - res2 * many[1]) / many[0]);
				cout << "Монеты номиналом 1 руб: " << res1 << " шт." << endl;
				cout << "Расчёт закончен." << endl;
			}
			else
			{
				cout << "Расчёт закончен." << endl;
			}
		}
		else
		{
			cout << "Расчёт закончен." << endl;
		}
	}
	else
	{
		cout << "Расчёт закончен." << endl;
	}
	return 0;
}