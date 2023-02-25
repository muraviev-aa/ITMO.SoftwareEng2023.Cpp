// ITMO.SoftwareEng2023.C++
// Практическое занятие 11. Перегрузка операций
// Упражнение 1. Перегрузка бинарных операций
//

#include <iostream> 
#include <string>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0) { }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in) { }
	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\' - " << inches << "\"\n";
	}
	Distance operator+ (const Distance&) const;
	Distance operator- (const Distance&) const;
	friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
};

Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

Distance Distance::operator- (const Distance& d2) const
{
	int f = feet - d2.feet;
	float i = inches - d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f--;
	}
	return Distance(f, i);
}

ostream& operator<< (ostream& out, const Distance& dist)
{
	out << dist.feet << "\' - " << dist.inches << "\"\n";
	return out;
}

int main()
{
	system("chcp 1251");
	Distance dist1, dist2, dist3, dist4;
	dist1.getdist();  // Введение первого значения
	dist2.getdist();  // Введение второго значения
	dist3 = dist1 + dist2;
	dist4 = dist1 + dist2 + dist3;

	cout << "\ndist1 = " << dist1;
	//dist1.showdist();
	cout << "\ndist2 = " << dist2;
	//dist2.showdist();
	cout << "\ndist3 = " << dist3;
	//dist3.showdist();
	cout << "\ndist4 = " << dist4;
	//dist4.showdist();

	dist3 = dist1 - dist2;
	cout << "\nВычитание: \n" << "\ndist3 = " << dist3;
	//dist3.showdist();
}