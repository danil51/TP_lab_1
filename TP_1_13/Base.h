#pragma once
#include "helper.h"
#include <fstream>
#include <string>
#include <iostream>
#include "graphics.h"

using namespace std;

class Base
{
private:
	string typeObj;
public:
	Base(string typeObj);
	Base(const Base& base);
	~Base() { cout << "Вызван деструктор Base" << endl; }
	//объявлеяем виртуальные функции которые будут перегружены в наследниках
	virtual void inputFromConsole() = 0; //абстрактрая функция, требует реализацию в наследнике
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change() = 0;
	virtual double getSquareOrVolume() = 0;

	string getTypeObj() { return typeObj; }
	void setTypeObj(string typeObj) { this->typeObj = typeObj; }
};

