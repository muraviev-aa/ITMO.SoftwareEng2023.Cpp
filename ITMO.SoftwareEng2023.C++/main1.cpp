// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Упражнение 3. Создание и удаление объекта
// Файл включает в себя пример Практическое занятие 10. Упражнение 1.
//

/* main1.cpp */

#include <iostream>
#include <string>
#include "student.h"
using namespace std;


int main()
{
	IdCard idc(123, "Базовый"); // Объект класса IdCard с передачей двух значений для инициализации объекта

	// Выделение памяти для объекта Student
	

	string name;
	string last_name;
	Student* student02 = new Student(name, last_name, &idc);
	

	// Ввод имени с клавиатуры
	cout << "Name: ";
	getline(cin, name);

	// Ввод фамилии
	cout << "Last name: ";
	getline(cin, last_name);


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

	// Сохранение имени и фамилии в объект класса Students
	student02->set_name(name);            // память для объекта выделяется посредством указателя
	student02->set_last_name(last_name);  // оператор косвенного обращения ->

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

	cout << "IdCard:" << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	delete student02; // Освобождаем память, занимаемую объектом

	return 0;
}