#pragma once
#include "Base.h"
class Rect :
	public Base
{
private:
	double lenght, width, square;
	void calcylateSquare();
public:
	Rect();
	Rect(double lenght, double width);
	Rect(const Rect& rectangle);
	~Rect() { cout << "Вызван деструктор Rectangle" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void print();
	virtual void printToFile(ostream& out);
	virtual void change();


	virtual double getSquareOrVolume() { return square; }

	double getLenght() { return lenght; }
	void setLenght(double lenght) { this->lenght = lenght; calcylateSquare(); }

	double getWidth() { return width; }
	void setWidth(double width) { this->width = width; calcylateSquare(); }
};

