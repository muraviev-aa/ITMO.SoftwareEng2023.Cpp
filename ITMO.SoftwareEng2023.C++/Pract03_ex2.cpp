// ITMO.SoftwareEng2023.C++
// ������������ ������� 3. ������������� ������� 
// ���������� 2. ���������� �������
//

#include <iostream>
#include <string>

using namespace std;

void privet(string);
void privet(string, int);

int main()
{
	int k = 0;
	string name;
	privet(name);
	cin >> name;
	cout << "Input number:" << endl;
	cin >> k;
	cout << name << ", " << "hello! " << endl;
	privet(name, k);
	return 0;
}

void privet(string name)
{
	cout << "What is your name?" << endl;
}

void privet(string name, int k)
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}