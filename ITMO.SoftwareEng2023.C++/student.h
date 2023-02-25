// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Упражнение 2. Разделение реализации и представления
// Файл включает в себя пример Практическое занятие 10. Упражнение 1.
//

/* student.h */
#pragma once   /* Защита от двойного подключения заголовочного файла */
#include "IdCard.cpp"  // Практическое занятие 10. Упражнение 1.
//#include "IdCard.h"    // Практическое занятие 10. Упражнение 1.
//#include "student.cpp"
#include <string>
using namespace std;


class Student
{
public:
	IdCard* iCard;    // Практическое занятие 10. Упражнение 1.


	Student(string name, string last_name, IdCard* id);  // Практическое занятие 10. Упражнение 1.

	void setIdCard(IdCard* c); // Запись поля IdCard

	IdCard getIdCard();        // Получение значения поля IdCard

	// Установка имени студента
	void set_name(string);

	// Получение имени студента
	string get_name();

	// Установка фамилии студента
	void set_last_name(string);

	// Получение фамилии студента
	string get_last_name();

	// Установка промежуточных оценок
	void set_scores(int[]);

	// Установка среднего балла
	void set_average_score(double);

	// Получение среднего балла
	double get_average_score();

private:
	// Промежуточные оценки
	int scores[5];

	// Средний балл
	double average_score;

	// Имя
	string name;

	// Фамилия
	string last_name;
};