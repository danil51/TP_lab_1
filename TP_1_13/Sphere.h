#pragma once
#include "Base.h"

class Sphere :
    public Base
{
private:
	double radius, volume;
	void calcylateVolume();
public:
	Sphere();
	Sphere(double radius);
	Sphere(const Sphere& sphere);
	~Sphere() { cout << "Вызван деструктор Sphere" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void print();
	virtual void printToFile(ostream& out);
	virtual void change();


	virtual double getSquareOrVolume() { return volume; }

	double getRadius() { return radius; }
	void setRadius(double radius) { this->radius = radius; }
};

