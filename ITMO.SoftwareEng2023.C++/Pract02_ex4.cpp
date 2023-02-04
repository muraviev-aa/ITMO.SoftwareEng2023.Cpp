// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Реализация управляющих операторов
// Упражнение 4. Расчет суммы чисел на заданном интервале
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int k, m;
	int s = 0;
	cout << "Введите k = "; cin >> k;
	cout << "Введите m = "; cin >> m;

	for (int i = 1;i <= 100;i++)
	{
		if ((i > k) && (i < m))
			continue;
		s += i;
	}

	cout << "Сумма чисел в диапазоне от 1 до k и от m до 100 равна: " << s << endl;
	return 0;
}