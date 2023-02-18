// ITMO.SoftwareEng2023.C++
// Практическое занятие 8. Объявление и реализация класса. 
// Реализация инкапсуляции. Конструкторы и деструкторы.
// Контрольные задания.
// Задание 1. Класс Time. Вариант с private методом timeCheck() и Tuple
//

#include <iostream>
#include <tuple>
using namespace std;
using Tuple = tuple<int, int, int>;

class Time
{
public:
	Time() : m_hours(0), m_minutes(0), m_seconds(0) {}

	Time(int hours, int minutes, int seconds)
		: m_hours(hours), m_minutes(minutes), m_seconds(seconds)
	{
		auto tp = timeCheсk(hours, minutes, seconds);
		m_hours = get<0>(tp);
		m_minutes = get<1>(tp);
		m_seconds = get<2>(tp);
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

		auto tp = timeCheсk(time.m_hours, time.m_minutes, time.m_seconds);
		time.m_hours = get<0>(tp);
		time.m_minutes = get<1>(tp);
		time.m_seconds = get<2>(tp);

		return time;
	}

private:
	int m_hours;
	int m_minutes;
	int m_seconds;

	Tuple timeCheсk(int hours, int minutes, int seconds) // Для устранения дублирования кода
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
		return make_tuple(hours, minutes, seconds);
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

