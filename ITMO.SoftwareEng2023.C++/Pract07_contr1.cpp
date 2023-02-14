// ITMO.SoftwareEng2023.C++
// Практическое занятие 7. Применение структур и кортежей
// Контрольные задания.
// Задание 1. Структура Time
//

#include <iostream>
#include <windows.h>
using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

Time InputTime();
Time OutputSeconds(Time t1);
Time AddTime(Time t1, Time t2);
Time SubtractionTime(Time t1, Time t2);
void ShowSeconds(Time t);
void ShowTimeResult(Time t);

int main()
{
	system("chcp 1251");
	Time t1 = InputTime();
	Time t2 = { 3, 50 , 1 };              // Существующее время для выполнения операций
	Time t3 = OutputSeconds(t1);
	ShowSeconds(t3);                      // Вывод введенного времени в секундах
	Time t4 = AddTime(t1, t2);            // Сложение с сущ. временем
	ShowTimeResult(t4);                   // Результат сложения
	Time t5 = SubtractionTime(t2, t1);    // Вычитание сущ. времени
	ShowTimeResult(t5);                   // Результат вычитания
	return 0;
}

Time InputTime()
{
	Time t;
	cout << "\nВведите число часов: ";
	cin >> t.hours;
	cout << "Введите число минут: ";
	cin >> t.minutes;
	cout << "Введите число секунд: ";
	cin >> t.seconds;
	return t;
}

Time OutputSeconds(Time t1)
{
	Time t;
	t.seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	return t;
}

Time AddTime(Time t1, Time t2)
{
	Time t;
	t.hours = t1.hours + t2.hours;

	t.minutes = t1.minutes + t2.minutes;
	if (t.minutes >= 60)
	{
		t.minutes -= 60;
		t.hours++;
	}

	t.seconds = t1.seconds + t2.seconds;
	if (t.seconds >= 60)
	{
		t.seconds -= 60;
		t.minutes++;
	}

	return t;
}

Time SubtractionTime(Time t1, Time t2)
{
	Time t;
	t.hours = t2.hours - t1.hours;

	t.minutes = t2.minutes - t1.minutes;
	if (t.minutes < 0)
	{
		t.hours -= 1;
		t.minutes = (t2.minutes + 60) - t1.minutes;
	}

	t.seconds = t2.seconds - t1.seconds;
	if (t.seconds < 0)
	{
		t.minutes -= 1;
		t.seconds = (t2.seconds + 60) - t1.seconds;
	}

	return t;
}

void ShowSeconds(Time t)
{
	cout << "Введенное время составляет: " << t.seconds << " секунд.\n";
}

void ShowTimeResult(Time t)
{
	cout << t.hours << ":" << t.minutes << ":" << t.seconds << "\n";
}
