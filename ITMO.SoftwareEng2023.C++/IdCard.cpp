// ITMO.SoftwareEng2023.C++
// Практическое занятие 10. Реализация отношений между классами 
// Упражнение 1. Отношение ассоциации
// дополняет файл main1.cpp

#include "IdCard.h"
#include <string>
using namespace std;


IdCard::IdCard()
{
	number = 0;
	category = "Не установлена";
}

IdCard::IdCard(int n)
{
	number = n;
	category = "Не установлена";
}

IdCard::IdCard(int n, string cat)
{
	number = n;
	category = cat;
}

void IdCard::setNumber(int newNumber)
{
	number = newNumber;
}
int IdCard::getNumber()
{
	return number;
}
void IdCard::setCategory(string cat)
{
	category = cat;
}
string IdCard::getCategory()
{
	return category;
}