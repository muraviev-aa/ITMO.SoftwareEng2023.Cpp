// ITMO.SoftwareEng2023.C++
// ������������ ������� 1. ����������� �����-������ ������. 
// ���������� 3. ������ ������� ������������
//

#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	double perimetr, a; // ��������, �������
	cout << "������� �������� ���������\n";
	cin >> perimetr; // ���� � ���������� �������� ���������
	double s = sqrt(perimetr / 2 * pow((perimetr / 2 - perimetr / 3), 3)); // ���������� �������� ������� ������������
	a = perimetr / 3; // ���������� �������� ����� ������� ������������
	printf("%7s  %7s", "�������", "�������\n"); // ����� � ���� �������
	printf("%7.2lf  %7.2lf", a, s); // ����� � ���� �������
	return 0;
}