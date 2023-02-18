﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Контрольные задания.
// Задание 1. Класс Time. Вариант с private методом timeCheck() с ссылками
//

#include <iostream>
using namespace std;

class Time
{
public:
	Time() : m_hours(0), m_minutes(0), m_seconds(0) {}

	Time(int hours, int minutes, int seconds)
		: m_hours(hours), m_minutes(minutes), m_seconds(seconds) {

		timeCheсk(hours, minutes, seconds);
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}

	friend void timeVisible(Time& t)
	{
		cout << "Результат сложения: " << t.m_hours << ":" << t.m_minutes << ":" << t.m_seconds << endl;
	}

	Time timeAdded(const Time& t)
	{
		Time time;
		time.m_hours = m_hours + t.m_hours;
		time.m_minutes = m_minutes + t.m_minutes;
		time.m_seconds = m_seconds + t.m_seconds;

		timeCheсk(time.m_hours, time.m_minutes, time.m_seconds);
		
		return time;
	}

private:
	int m_hours;
	int m_minutes;
	int m_seconds;

	void timeCheсk(int &hours, int &minutes, int &seconds) // Для устранения дублирования кода
	{
		if (seconds > 60)
		{
			minutes += seconds / 60;
			seconds = seconds - 60;

			if (minutes > 60)
			{
				hours += minutes / 60;
				minutes = minutes - 60;
			}
		}

		if (minutes > 60)
		{
			hours += minutes / 60;
			minutes = minutes - 60;
		}
	}
};

int main()
{
	system("chcp 1251");
	int hours, minutes, seconds;
	Time time1(1, 50, 55);                // Первый инициализированный объект в стеке
	cout << "Введите часы, минуты, секунды через пробел:\n";
	cin >> hours >> minutes >> seconds;
	Time time2(hours, minutes, seconds);  // Второй инициализированный объект в стеке
	Time time3 = time1.timeAdded(time2);  // Присвоение результата сложения третьему объекту в стеке
	timeVisible(time3);
}

