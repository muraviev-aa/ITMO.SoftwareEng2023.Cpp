// ITMO.SoftwareEng2023.C++
// Практическое занятие 6. Работа с файлами
// Задание 4. Передача параметров в программу
// Упражнение 1. Запись и чтение данных из бинарного файла
//

#include <iostream> 
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	double sum = 0;
	int const n = 100;
	double nums[n];

	for (int i = 0; i < n; i++)
	{
		nums[i] = (rand() % 100);
	}

	ofstream out ("test.txt", ios::out | ios::binary); // Создание объекта ofstream и связывание его с определенным файлом на диске
	if (!out)
	{
		cout << "Файл открыть невозможно\n";
		return 1;
	}

	out.write((char*)nums, sizeof(nums));  // Вызов функции write(), которая записывает в поток из буфера
	out.close();  // Закрытие потока

	ifstream in("test.txt", ios::in | ios::binary);  // Объект ifstream для открытия файла
	if (!in) {
		cout << "Файл открыть невозможно";
		return 1;
	}

	in.read((char*)&nums, sizeof(nums)); // Считывание из вызывающего потока и передача в буфер

	int k = sizeof(nums) / sizeof(double); // Реализация обработки полученных данных
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
		cout << nums[i] << ' ';
	}
	cout << "\nsum = " << sum << endl;

	in.close(); // Закрываем поток
}