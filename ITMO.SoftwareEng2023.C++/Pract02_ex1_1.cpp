// ITMO.SoftwareEng2023.C++
// ������������ ������� 2. ���������� ����������� ����������
// ���������� 1. ���������� ���������� ������
//


#include <iostream>

using namespace std;

int main() 
{
    system("chcp 1251");
	double x, y;
	cout << "������� ���������� x � y ����� ����� ������\n";
	cin >> x >> y;
    if (x * x + y * y < 9 && y > 0)
        cout << "������" << endl;
    else if (x * x + y * y > 9 || y < 0)
        cout << "�������" << endl;
    else
        cout << "�� �������" << endl;


    return 0;
}