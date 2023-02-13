// ITMO.SoftwareEng2023.C++
// Практическое занятие 6. Работа с файлами
// Контрольные задания.
// Задание 3. Сохранение данных в json-файл
//

#include <iostream> 
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;

int main()
{
	json js;
	string fileName = "6_3.json";

	js = json::array({ 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 }); // Массив.Cоздание и запись массива в json
	ofstream in(fileName);
	in << js << endl;
	in.close();

	ifstream out(fileName);  // Чтение массива из json
	out >> js;
	const int N = 10;
	int a[N] = { 0 };
	int i = 0;
	for (auto it = js.begin(); it != js.end(); ++it)
	{
		a[i] = *it;
		i++;
	}
	out.close();
	
	int min = 0;
	int buf = 0;

	for (int i = 0; i < N; i++)
	{
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;

		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	string fileName1 = "6_3sort.json";   // Массив запись в другой json
	ofstream sort(fileName1);
	for (int i = 0; i < N; i++) {
		sort << a[i] << '\t';
	}
	sort.close();

	for (int i : a)  // для вывода в консоль
		cout << i << '\t';
}