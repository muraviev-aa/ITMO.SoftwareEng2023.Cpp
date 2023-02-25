// ITMO.SoftwareEng2023.C++
// Практическое занятие 11. Перегрузка операций
// Контрольные задания.
// Задание 2. Реализация сортировки точек в векторе
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm> // для алгоритма сортировки

using namespace std;

class Point
{
public:
	Point(int x, int y): p_x(x), p_y(y) {};

	friend bool operator< (const Point&, const Point&);
	friend ostream& operator<< (ostream&, const Point&);

private:
	int p_x;
	int p_y;

	double distanсe() const
	{
		return sqrt(pow(p_x, 2) + pow(p_y, 2));
	}
		

};

bool operator< (const Point& pointFirst, const Point& pointLast) // Перегрузка оператора <
{
	if (pointFirst.distanсe() < pointLast.distanсe())
		return true;
	else
		return false;
}

ostream& operator<< (ostream& value, const Point& pointСurrent) // Перегрузка оператора <<
{
	value << "\nКоордината x точки: " << pointСurrent.p_x << "\n"
		<< "\nКоордината y точки: " << pointСurrent.p_y << "\n" << endl;
	return value;
}

int main()
{
	system("chcp 1251");
	vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	sort(v.begin(), v.end());    // требуется перегрузка оператора < для // класса Point
	for (auto& point : v)
		cout << point << '\n';   // требуется перегрузка оператора << для // класса Point
	return 0;
}