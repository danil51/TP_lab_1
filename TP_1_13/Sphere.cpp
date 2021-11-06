#include "Sphere.h"

Sphere::Sphere() : Base("���"), radius(0), volume(0)
{
	cout << "������ ����������� Sphere" << endl;
}

Sphere::Sphere(double radius) :
	Base("���"), radius(radius)
{
	calcylateVolume();
	cout << "������ ����������� Sphere" << endl;
}

Sphere::Sphere(const Sphere& sphere) :
	Base(sphere), radius(sphere.radius), volume(sphere.volume)
{
	cout << "������ ����������� ����������� Sphere" << endl;
}

void Sphere::inputFromConsole()
{
	cout << "������� ������: ";
	radius = safeInput(1.0, (double)INT32_MAX);
	calcylateVolume();
}

void Sphere::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	radius = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	calcylateVolume();
}

void Sphere::printToConsole()
{
	Base::printToConsole();
	cout << "������: " << radius << endl;
	cout << "�����: " << volume << endl;
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
	cout << "������� ����� ������: ";
	radius = safeInput(1.0, (double)INT32_MAX);
	calcylateVolume();
}

void Sphere::calcylateVolume() {
	volume = 4.0 / 3.0 * 3.1415 * pow(radius, 3.0);
}