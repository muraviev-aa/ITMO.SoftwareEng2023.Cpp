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

	Time(double t) 
	{
		m_hours = (int)t;            // Количество часов после перевода
		double _m_minutes = (t - m_hours) * 60;
		m_minutes = (int)_m_minutes; // Количество минут после перевода
		double _m_seconds = (_m_minutes - m_minutes) * 60;
		m_seconds = (int)_m_seconds; // Количество минут после перевода
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

	double timeInSeconds() const
	{
		return 3600 * m_hours + 60 * m_minutes + m_seconds;
	}

	Time operator+ (const Time&);
	Time operator- (const Time&);
	bool operator> (const Time&);

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

bool Time::operator> (const Time& t)
{
	bool comparison;
	if (timeInSeconds() > t.timeInSeconds())
		comparison = 1;
	else
		comparison = 0;
	return comparison;
}

int main()
{
	system("chcp 1251");
	int hours, minutes, seconds;
	double timeInDouble;   // Время в формате double
	Time time1(1, 50, 55); 
	cout << "\nВведите часы, минуты, секунды через пробел:\n";
	cin >> hours >> minutes >> seconds;
	
	try
	{
		Time time2(hours, minutes, seconds);   
		Time time3 = time1.timeAdded(time2);   // Сложение объектов Time с помощью функции
		cout << "\nСложение с помощью функции\n";
		timeVisible(time3);
		Time time4 = time1 + time2;            // Cложение объектов Time
		cout << "\nСложение с помощью перегрузки оператора\n";
		timeVisible(time4);
		if (time1 > time2)
		{
			Time time5 = time1 - time2;        // Вычитание объектов Time
			cout << "\nВычитание с помощью перегрузки оператора\n";
			timeVisible(time5);
		}
		else
		{
			cout << "\nОперацию вычитания выполнить невозможно ввиду малого значения уменьшаемого.\n";
		}
	}
	catch (IncorrectData& error)
	{
		cout << "ОШИБКА: ";
		error.printMessage();
	}

	cout << "\nВведите время в формате double:\n";
	cin >> timeInDouble;
	Time time6(timeInDouble);
	cout << "\nПеревод значения времени из double в объект Time\n";
	timeVisible(time6);  
	Time time7 = time1 + time6;
	cout << "\nСложение обьекта Time и переменной в double\n";
	timeVisible(time7);
}