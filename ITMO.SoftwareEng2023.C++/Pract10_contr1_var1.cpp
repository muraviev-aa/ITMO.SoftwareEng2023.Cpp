// ITMO.SoftwareEng2023.C++
// Практическое занятие 10. Реализация отношений между классами
// Контрольные задания.
// Задание 1. Реализация класса Triangle, вариант 1
//

#include "dot_var1.h"
#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
public:
	Triangle(const Dot& dot1, const Dot& dot2, const Dot& dot3) :  // Композиция
		d1(new Dot(dot1)), d2(new Dot(dot2)), d3(new Dot(dot3))
		
	{
		double d1d2 = d1->distanceTo(*d2);
		double d2d3 = d2->distanceTo(*d3);
		double d3d1 = d3->distanceTo(*d1);
	}

	Triangle(Dot* dot1, Dot* dot2, Dot* dot3):                     // Агрегация
		d1(dot1), d2(dot2), d3(dot3)
	{
		double d1d2 = d1->distanceTo(*d2);
		double d2d3 = d2->distanceTo(*d3);
		double d3d1 = d3->distanceTo(*d1);
	}

	void printLengthSides()
	{
		cout << "Длина первой стороны: " << d1->distanceTo(*d2) << endl;
		cout << "Длина второй стороны: " << d2->distanceTo(*d3) << endl;
		cout << "Длина третьей стороны: " << d3->distanceTo(*d1) << endl;
	}


	double trianglePerim()
	{
		return  d1->distanceTo(*d2) + d2->distanceTo(*d3) + d3->distanceTo(*d1);
	}

	double triangleSquare()
	{
		double halfPerim = 0.5 * trianglePerim();
		return sqrt(halfPerim * (halfPerim - d1->distanceTo(*d2)) 
			* (halfPerim - d2->distanceTo(*d3)) * (halfPerim - d3->distanceTo(*d1)));
	}

private:
	Dot* d1, * d2, * d3;
};

int main()
{
	system("chcp 1251");
	Dot d1(1, 1), d2(2, 2), d3(6, 3), d4(6, 1), d5(3.5, 5), d6(1, 1);;
	Triangle* tr = new Triangle(d1, d2, d3);        // Композиция
	tr->printLengthSides();
	cout << "Периметр треугольника: " << tr->trianglePerim() << endl;
	cout << "Площадь треугольника: " << tr->triangleSquare() << endl;
	delete tr;  // Удаляю объект треугольник в куче, объекты точки в куче также удаляются т.к. это композиция
	cout << "----------------------" << endl;
	Triangle tr1(&d4, &d5, &d6);                    // Агрегация
	tr1.printLengthSides();
	cout << "Периметр треугольника: " << tr1.trianglePerim() << endl;
	cout << "Площадь треугольника: " << tr1.triangleSquare() << endl;
}
