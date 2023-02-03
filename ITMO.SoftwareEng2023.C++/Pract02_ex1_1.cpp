// ITMO.SoftwareEng2023.C++
// Практическое занятие 2. Реализация управляющих операторов
// Упражнение 1. Реализация операторов выбора
//


#include <iostream>

using namespace std;

int main() 
{
    system("chcp 1251");
	double x, y;
	cout << "Введите координаты x и y точки через пробел\n";
	cin >> x >> y;
    if (x * x + y * y < 9 && y > 0)
        cout << "внутри" << endl;
    else if (x * x + y * y > 9 || y < 0)
        cout << "снаружи" << endl;
    else
        cout << "на границе" << endl;


    return 0;
}