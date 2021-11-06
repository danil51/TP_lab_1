#pragma once
#include "Base.h"
class Rectangle :
    public Base
{
private:
	double lenght, width, square;
	void calcylateSquare();
public:
	Rectangle();
	Rectangle(double lenght, double width);
	Rectangle(const Rectangle& rectangle);
	~Rectangle() { cout << "Вызван деструктор Rectangle" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();


	virtual double getSquareOrVolume() { return square; }

	double getLenght() { return lenght; }
	void setLenght(double lenght) { this->lenght = lenght; calcylateSquare();  }

	double getWidth() { return width; }
	void setWidth(double width) { this->width = width; calcylateSquare(); }
};

