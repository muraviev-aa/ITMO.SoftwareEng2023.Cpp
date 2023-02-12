// ITMO.SoftwareEng2023.C++
// Практическое занятие 5. Работа с массивами
// Контрольные задания.
// Задание 3. Реализация алгоритмов поиска методом транспозиции
//

#include <iostream> 
using namespace std;

int search(int* arr, int n, int key);

int main()
{
    system("chcp 1251");
    const int n = 10;   // Количество элементов в массиве
    int arr[n];         // Массив
    int point;          // Индекс искомого элемента
    int number;         // Искомый элемент
    int trial;          // Количество попыток поиска
    
    for (int i = 0; i < n; i++)
    {
        cout << "Введите цифру массива " << i << ": ";
        cin >> arr[i];
    }

    cout << "Введите значение искомого элемента: ";
    cin >> number;

    cout << "Введите количество попыток поиска: ";
    cin >> trial;

    for (int j = 0; j < trial; j++)
    {
        point = search(arr, n, number); // Функция поиска
       
        if (point == -1)
            cout << "Элементов равных " << number << " в массиве нет!\n" << endl;
        else
            cout << "Элемент с индексом " << point << " равен " << number << endl;
    }
    return 0;
}

int search(int* arr, int n, int key)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            if (i == 0)
            {
                return i;
            }

            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            return i;
        }
    }
    return -1;
}