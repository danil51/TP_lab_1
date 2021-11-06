#pragma once
#include <iostream>
//шаблонная функция для ввода числовых данных, если пользователь ввел некорректный символ, или вышел за гранцу, то просим его ввести снова
template <typename T>
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Неверный ввод.\nПовторите снова: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

bool checkStringToInt(std::string s);
bool checkStringToDouble(std::string s);