// ITMO.SoftwareEng2023.C++
// ����������� �������. 
// ������� 1. ������ ������� ��������������
//

#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, s;
	cout << "-----------------------------------------------\n";
	cout << "������ ������� �������������� �� ������� ������\n";
	cout << "-----------------------------------------------\n";
	cout << "������� ���������� x1 � y1 ������ ����� ����� ������\n";
	cin >> x1 >> y1;
	cout << "������� ���������� x2 � y2 ������ ����� ����� ������\n";
	cin >> x2 >> y2;
	cout << "������� ���������� x3 � y3 ������� ����� ����� ������\n";
	cin >> x3 >> y3;
	cout << "������� ���������� x4 � y4 ��������� ����� ����� ������\n";
	cin >> x4 >> y4;
	cout << "������� ���������� x5 � y5 ����� ����� ����� ������\n";
	cin >> x5 >> y5;
	s = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - 
		x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5);
	cout << "������� �������������: " << s << endl;
	return 0;
}