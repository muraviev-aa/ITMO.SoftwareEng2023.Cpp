// ITMO.SoftwareEng2023.C++
// Зачетное задание "Адресная книга". 
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	virtual ~Person() {}
	virtual string Action() const = 0;
};

class Professor : public Person
{
public:
	Professor(string fn, string ln, string pn, string c):
		firstName(fn), lastName(ln), phonNumber(pn), career(c)
	{}
	string Action() const override
	{
		return "Я профессор ИТМО\n";
	}
	friend ostream& operator<< (ostream&, const Professor&);
	
private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

class YoungMan : public Person
{
public:
	YoungMan(string fn, string ln, string pn, string c) :
		firstName(fn), lastName(ln), phonNumber(pn), career(c)
	{}
	string Action() const override
	{
		return "Я молодой человек\n";
	}
	friend ostream& operator<< (ostream&, const YoungMan&);

private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

class Dean : public Person
{
public:
	Dean(Dean& other) = delete;
	void operator=(const Dean&) = delete;
	string Action() const override
	{
		return "Я декан ИТМО\n";
	}
	friend ostream& operator<< (ostream&, const Dean&);
	static Dean* GetInstance(string fn, string ln, string pn, string c);
	//static Dean* GetInstance(const std::string& value);
protected:
	Dean(string fn, string ln, string pn, string c) : 
		firstName(fn), lastName(ln), phonNumber(pn), career(c) {}
	static Dean* dean_;
private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

Dean* Dean::dean_ = nullptr;
Dean* Dean::GetInstance(string fn, string ln, string pn, string c)
{
	if (dean_ == nullptr) {
		dean_ = new Dean(fn, ln, pn, c);
	}
	return dean_;
}

class Decorator : public Person // Шаблон Decorator
{
protected:
	Person* person_;

public:
	Decorator(Person* person) : person_(person)
	{ 	}
	string Action() const override
	{
		return this->person_->Action();
	}
};

class StudentA : public Decorator
{
public:
	StudentA(Person* person) : Decorator(person)
	{ 	}
	string Action() const override
	{
		return "Я учусь очно в ИТМО " + Decorator::Action();
	}
private:
	string firstName;
	string lastName;
	string phonNamber;
	string career;
};

class StudentB : public Decorator
{
public:
	StudentB(Person* person) : Decorator(person)
	{ 	}
	string Action() const override
	{
		return "Я учусь заочно в СПбГАСУ " + Decorator::Action();
	}
private:
	string firstName;
	string lastName;
	string phonNamber;
	string career;
};

ostream& operator<< (ostream& out, const Professor& prof)
{
	out << prof.firstName << " " << prof.lastName
		<< " " << prof.phonNumber << " " << prof.career << "\n"<< endl;
		return out;
}

ostream& operator<< (ostream& out, const YoungMan& ym)
{
	out << ym.firstName << " " << ym.lastName
		<< " " << ym.phonNumber << " " << ym.career << "\n" << endl;
	return out;
}

ostream& operator<< (ostream& out, const Dean& d)
{
	out << d.firstName << " " << d.lastName
		<< " " << d.phonNumber << " " << d.career << "\n" << endl;
	return out;
}

void ClientCode(Person* person)
{
	std::cout << "Что делаю: " << person->Action();
}

int main()
{
	system("chcp 1251");
	Person* professor = new Professor("Ivan", "Petrov", "88888888888", "professor");
	Person* professor1 = new Professor("Sidor", "Sidorov", "22222222222", "professor");
	ClientCode(professor);
	ClientCode(professor1);

	// Может быть только ОДИН декан благодаря шаблону Singleton
	Person* dean = Dean::GetInstance("Petr", "Ivanov", "99999999999", "dean"); 
	// Попытка создать еще один объект Dean вызывает ошибку
	//Person* dean1 = new Dean("Сreate impossible", "Сreate impossible", "00000000000", "dean"); 
	ClientCode(dean);

	Person* youngMan = new YoungMan("Fedor", "Kukuev", "77777777777", "youngMan");
	ClientCode(youngMan);
	Person* studentA = new StudentA(youngMan); // Декорация объекта youngMan
	ClientCode(studentA);
	Person* studentB = new StudentB(studentA);  // Декорация объекта studentA
	ClientCode(studentB);

	string fileName = "testTask.txt";
	ofstream book(fileName);
	book << "Адресная книга:\n" << endl;
	vector<Professor> v;
	v.push_back(Professor("Ivan", "Petrov", "88888888888", "professor"));
	v.push_back(Professor("Sidor", "Sidorov", "22222222222", "professor"));
	for (auto& professor : v)
		//cout << professor;
		book << professor;
	vector<YoungMan> v1;
	v1.push_back(YoungMan("Fedor", "Kukuev", "77777777777", "youngMan"));
	for (auto& youngMan : v1)
		//cout << youngMan;
		book << youngMan;
	book.close();
	delete professor;
	delete professor1;
	delete dean;
	delete youngMan;
	delete studentA;
	delete studentB;
	return 0;
}