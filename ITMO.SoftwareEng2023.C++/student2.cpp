﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Упражнение 5. Сохранение данных в файл
//

/* student2.cpp */
#include <string>
#include <fstream>
#include "student2.h"

// Конструктор Student
Student::Student(string name, string last_name)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
}

// Деструктор Student
Student::~Student()
{
	Student::save();
}

// Запись данных о студенте в файл
void Student::save()
{
	ofstream fout("students08_5.txt", ios::app);
	fout << Student::get_name() << " "
		<< Student::get_last_name() << " ";
	for (int i = 0; i < 5; ++i) {
		fout << Student::scores[i] << " ";
	}
	fout << endl;
	fout.close();
}

// Установка имени студента
void Student::set_name(std::string student_name)
{
	Student::name = student_name;
}

// Получение имени студента
std::string Student::get_name()
{
	return Student::name;
}

// Установка фамилии студента
void Student::set_last_name(std::string student_last_name)
{
	Student::last_name = student_last_name;
}

// Получение фамилии студента
std::string Student::get_last_name()
{
	return Student::last_name;
}

// Установка промежуточных оценок
void Student::set_scores(int scores[])
{
	for (int i = 0; i < 5; ++i) {
		Student::scores[i] = scores[i];
	}
}

// Установка среднего балла
void Student::set_average_score(double ball)
{
	Student::average_score = ball;
}

// Получение среднего балла
double Student::get_average_score()
{
	return Student::average_score;
}