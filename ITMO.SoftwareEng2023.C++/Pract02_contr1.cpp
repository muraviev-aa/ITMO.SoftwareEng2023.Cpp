// ITMO.SoftwareEng2023.C++
// ������������ ������� 2. ����������� �������. 
// ������� 1. ����������� �������� �����
//

#include <iostream> 
using namespace std;

int main()
{
	system("chcp 1251");
	int a;
	cout << "������� a = "; cin >> a;
	
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0)
		{
			cout << "��������� ����� �� �������." << endl;
			return 0;
		}
	}
	cout << "��������� ����� �������." << endl;
	return 0;
}