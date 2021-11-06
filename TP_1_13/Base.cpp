#include "Base.h"
//используем конструктор со списком инициализации
Base::Base(string typeObj) : typeObj(typeObj)
{
	cout << "Вызван конструктор Base" << endl;
}

Base::Base(const Base& base) : typeObj(base.typeObj)
{
	cout << "Вызван конструктор копирования Base" << endl;
}

void Base::printToConsole()
{
	cout << typeObj << endl;
}

void Base::printToFile(ostream& out)
{
	out << typeObj << endl;
}