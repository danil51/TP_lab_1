#include "helper.h"
//проверяем, что строка является числом
bool checkStringToInt(std::string s)
{
	for (auto letter : s)
		if (letter < '0' || letter > '9')
			return false;
	return true;
}
//проверяем, что строка является числом с плавающей точкой
bool checkStringToDouble(std::string s)
{
	bool flagPoint = false;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] == '.' && i == 0 || flagPoint))
			return false;
		if (s[i] == '.')
			flagPoint = true;
	}
		
	return true;
}