// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Упражнение 2. Разделение реализации и представления
//

/* student.h */
#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
using namespace std;
class Student
{
public:
	void set_name(string);          // Установка имени студента
	string get_name();              // Получение имени студента
	void set_last_name(string);     // Установка фамилии студента
	string get_last_name();         // Получение фамилии студента
	void set_scores(int[]);         // Установка промежуточных оценок
	void set_average_score(double); // Установка среднего балла
	double get_average_score();     // Получение среднего балла
private:
	int scores[5];          // Промежуточные оценки
	double average_score;   // Средний балл
	string name;            // Имя
	string last_name;       // Фамилия
};