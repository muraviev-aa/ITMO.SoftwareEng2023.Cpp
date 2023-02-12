// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Контрольные задания.
// Задание 4. Передача параметров в программу
//

#include <iostream> 
#include <vector>
#include <cstring>
using namespace std;

int funcOperations(string operation1, int num1, int num2);

int main()
{
    system("chcp 1251");
    vector<int> myVector;                      // Вектор          
    string str;
    string operation;
    int num1;          
    int num2;

    cout << "Введите название программы: ";
    cin >> str;
    int strNumber = atoi(str.c_str());         // Конвертация названия программы в число

    cout << "Сложить числа - a; Умножить числа - m: ";
    cin >> operation;

    if (operation != "a" && operation != "m")  // Проверка на введение a или m
        return -1;

    string operation1 = operation;
    int operNumber = atoi(operation.c_str());  // Конвертация операции в число
    cout << "Введите числа через пробел: ";
    cin >> num1 >> num2;
    myVector.push_back(strNumber);
    myVector.push_back(operNumber);
    myVector.push_back(num1);
    myVector.push_back(num2);

    if (myVector.size() < 4)                   // Проверка размера вектора
        return -1;

    cout << "Результат: " << funcOperations(operation1, num1, num2);
}

int funcOperations(string operation1, int num1, int num2)
{
    if (operation1 == "a")
        return num1 + num2;
    else if (operation1 == "m")
        return num1 * num2;
    else return -1;
}