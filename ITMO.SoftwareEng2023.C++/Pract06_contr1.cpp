// ITMO.SoftwareEng2023.C++
// Практическое занятие 6. Работа с файлами
// Контрольные задания.
// Задание 1. Запись текста в файл
//

#include <iostream>
#include <fstream>
using namespace std;


void Example1(const char* filename);

void main()
{
    system("chcp 1251");
    Example1("6_1.txt");
}

void Example1(const char* filename) // Чтение строк из клавиатуры и запись их в файл
{
    ofstream os(filename); 
    char str[100];
    cout << "Введите строки стихотворения. Для завершения ввода введите ТОЧКУ." << endl;

    do
    {
        cin.getline(str, 100);
        os << str << endl;
    } 
    while (*str != '.'); // ТОЧКА - окончание ввода

    os.close();
}