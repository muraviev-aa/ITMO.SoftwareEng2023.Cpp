// ITMO.SoftwareEng2023.C++
// Практическое занятие 11. Перегрузка операций
// Контрольные задания.
// Задание 1. Перегрузка операторов в классе Time
//

#include <iostream>
using namespace std;

class IncorrectData
{
public:
	IncorrectData() : message("Введенные данные некорректны") { };
	void printMessage() const { cout << message << endl; };
private:
	string message;
};

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
		cout << "Результат: " << t.m_hours << ":" << t.m_minutes << ":" << t.m_seconds << endl;
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

	Time operator+ (const Time&);
	Time operator- (const Time&);

private:
	int m_hours;
	int m_minutes;
	int m_seconds;

	void timeCheсk(int& hours, int& minutes, int& seconds) // Для устранения дублирования кода
	{
		if (hours < 0 || minutes < 0 || seconds < 0)
			throw IncorrectData();

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

Time Time::operator+ (const Time& t) 
{
	Time time;
	time.m_hours = m_hours + t.m_hours;
	time.m_minutes = m_minutes + t.m_minutes;
	time.m_seconds = m_seconds + t.m_seconds;

	timeCheсk(time.m_hours, time.m_minutes, time.m_seconds);

	return time;
}

Time Time::operator- (const Time& t)
{
	Time time;
	time.m_hours = m_hours - t.m_hours;
	time.m_minutes = m_minutes - t.m_minutes;
	time.m_seconds = m_seconds - t.m_seconds;

	timeCheсk(time.m_hours, time.m_minutes, time.m_seconds);

	return time;
}

int main()
{
	system("chcp 1251");
	int hours, minutes, seconds;
	Time time1(1, 50, 55);                // Первый инициализированный объект в стеке
	cout << "Введите часы, минуты, секунды через пробел:\n";
	cin >> hours >> minutes >> seconds;

	try
	{
		Time time2(hours, minutes, seconds);   // Второй инициализированный объект в стеке
		Time time3 = time1.timeAdded(time2);   // Сложение объектов Time с помощью функции
		cout << "\nСложение с помощью функции\n";
		timeVisible(time3);
		Time time4 = time1 + time2;            // Cложение объектов Time
		cout << "\nСложение с помощью перегрузки оператора\n";
		timeVisible(time4);
		Time time5 = time1 - time2;            // Вычитание объектов Time
		cout << "\nВычитание с помощью перегрузки оператора\n";
		timeVisible(time5);
	}
	catch (IncorrectData& error)
	{
		cout << "ОШИБКА: ";
		error.printMessage();
	}

}