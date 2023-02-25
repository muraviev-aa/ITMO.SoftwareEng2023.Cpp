// ITMO.SoftwareEng2023.C++
// Практическое занятие 10. Реализация отношений между классами 
// Упражнение 1. Отношение ассоциации
// дополняет файл main1.cpp

#pragma once
#include <string>
using namespace std;

class IdCard
{
private:
	int number;
	string category;
public:
	IdCard();
	IdCard(int);
	IdCard(int, string);
	void setNumber(int newNumber);
	int getNumber();
	void setCategory(string cat);
	string getCategory();
};