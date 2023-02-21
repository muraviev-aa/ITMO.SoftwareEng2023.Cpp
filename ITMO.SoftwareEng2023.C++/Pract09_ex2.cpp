// ITMO.SoftwareEng2023.C++
// Практическое занятие 9. Обработка исключительных операций
// Упражнение 2. Безопасное деление в цикле
//

#include <iostream> 
#include <string>

using namespace std;

class DivideByZeroError
{
public:
	DivideByZeroError() : message("Деление на нуль") { };
	void printMessage() const { cout << message << endl; };
private:
	string message;
};

float quotient(int num1, int num2)
{
	if (num2 == 0)
		throw DivideByZeroError();
	return (float)num1 / num2;
}

int main()
{
	system("chcp 1251");
	int number1, number2;
	cout << "Введите целое число:\n";
	cin >> number1;

	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "Частное равно " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
		}
	}
	return 0; 
}