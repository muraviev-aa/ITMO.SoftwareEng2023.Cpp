// ITMO.SoftwareEng2023.C++
// Практическое занятие 10. Реализация отношений между классами
// Контрольные задания.
// Задание 1. Реализация класса Triangle, вариант 1
//

#pragma once
class Dot
{
private:
	double x;
	double y;
public:
	Dot();
	Dot(double x, double y);
	double distanceTo(Dot point);
};
