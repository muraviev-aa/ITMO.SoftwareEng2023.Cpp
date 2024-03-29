﻿// ITMO.SoftwareEng2023.C++
// Практическое занятие 6. Работа с файлами
// Упражнение 2. Работа с данными в формате json
//

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

int main()
{
	// создаём пустой JSON-объект
	json j;
	// добавляем строку, которая будет храниться как std::string
	j["name"] = "Test";
	// добавляем пустой вложенный объект
	j["nothing"] = nullptr;
	// число внутри вложенного объекта
	j["answer"]["everything"] = 2;
	// добавляем массив строк (будет храниться как std::vector<std::string>)
	// обратите внимание - используются списки инициализации
	j["companies"] = { "Info", "TM" };
	// добавляем ещё один объект - на этот раз используем список инициализации с парами "ключ"-"значение"
	j["user"] = { {"name", "solo"}, {"active", true} };
	// проверяем созданный объект, отправив его в консольный поток вывода
	std::cout << j << std::endl;
	// изменили формат вывода, добавив манипулятор std::setw(4) для вставки четырех форматируемых отступов
	std::cout << std::setw(4) << j << std::endl;
	// вывели в консоль отдельные поля объекта:
	std::cout << j.at("name") << std::endl;
	std::cout << j["answer"]["everything"] << std::endl;
	// извлекаем данные пользователя (имя), присваиваем их переменной и выводим ее на экран
	auto user = j["user"]["name"];
	std::cout << "User: " << user << std::endl;
	// проверяем текущее содержимое объекта с помощью перебора всех элементов в цикле
	for (auto element : j) {
		std::cout << element << '\n';
	}
	// меняем имя объекта с помощью списка инициализации с парами ключ-значение
	j["user"] = { {"name", "polo"}, {"active", false} };
	// записываем данные объекта в файл, для этого создаем файловый поток и передаем ему объект
	std::ofstream o("polo.json");
	o << std::setw(4) << j << std::endl;
	// проверяем выполнение записи данных – для этого считываем данные из файла в новый json-объект 
	// и выводим его содержимое на экран
	std::ifstream i("polo.json");
	json polo;
	i >> polo;
	std::cout << std::setw(4) << polo["user"] << std::endl;
}