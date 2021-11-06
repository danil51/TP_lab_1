#include "Sphere.h"

Sphere::Sphere() : Base("Шар"), radius(0), volume(0)
{
	cout << "Вызван конструктор Sphere" << endl;
}

Sphere::Sphere(double radius) :
	Base("Шар"), radius(radius)
{
	calcylateVolume();
	cout << "Вызван конструктор Sphere" << endl;
}

Sphere::Sphere(const Sphere& sphere) :
	Base(sphere), radius(sphere.radius), volume(sphere.volume)
{
	cout << "Вызван конструктор копирования Sphere" << endl;
}

void Sphere::inputFromConsole()
{
	cout << "Введите радиус: ";
	radius = safeInput(1.0, (double)INT32_MAX);
	calcylateVolume();
}

void Sphere::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	radius = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	calcylateVolume();
}

void Sphere::printToConsole()
{
	Base::printToConsole();
	cout << "Радиус: " << radius << endl;
	cout << "Объем: " << volume << endl;
}

void Sphere::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << radius << endl;
}

void Sphere::print() {
	cleardevice();
	circle(100, 100, radius);
}

void Sphere::change()
{
	cout << "Введите новый радиус: ";
	radius = safeInput(1.0, (double)INT32_MAX);
	calcylateVolume();
}

void Sphere::calcylateVolume() {
	volume = 4.0 / 3.0 * 3.1415 * pow(radius, 3.0);
}