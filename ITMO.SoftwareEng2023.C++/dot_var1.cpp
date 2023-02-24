// ITMO.SoftwareEng2023.C++
// Практическое занятие 10. Реализация отношений между классами
// Контрольные задания.
// Задание 1. Реализация класса Triangle, вариант 1
//


#include "dot_var1.h"
#include <cmath>

Dot::Dot()
{
	x = 0; y = 0;
}
Dot::Dot(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Dot::distanceTo(Dot point)
{
	return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
}