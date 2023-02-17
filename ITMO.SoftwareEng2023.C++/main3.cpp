// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Упражнение 5. Сохранение данных в файл
//

/* main3.cpp */

#include <iostream>
#include <string>
#include "student2.h"
using namespace std;


int main()
{
	system("chcp 1251");
	string name;
	string last_name;

	// Ввод имени с клавиатуры
	cout << "Name: ";
	getline(cin, name);

	// Ввод фамилии
	cout << "Last name: ";
	getline(cin, last_name);

	// Передача параметров конструктору
	Student* student02 = new Student(name, last_name);

	// Оценки
	int scores[5] = { 0 };

	// Сумма всех оценок
	int sum = 0;

	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}

	// Сохраняем промежуточные оценки в объект класса Student
	student02->set_scores(scores);

	// Считаем средний балл
	double average_score = sum / 5.0;

	// Сохраняем средний балл в объект класса Student
	student02->set_average_score(average_score);
	// Выводим данные по студенту
	cout << "Average ball for " << student02->get_name() << " "
		<< student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;

	delete student02; // Освобождаем память, занимаемую объектом

	return 0;
}