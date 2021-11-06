#include "Rectangle.h"

Rectangle::Rectangle() : Base("�������������"), lenght(0), width(0), square(0)
{
	cout << "������ ����������� Rectangle" << endl;
}

Rectangle::Rectangle(double lenght, double width) :
	Base("�������������"), lenght(lenght), width(width)
{
	calcylateSquare();
	cout << "������ ����������� Rectangle" << endl;
}

Rectangle::Rectangle(const Rectangle& rectangle) :
	Base(rectangle), lenght(rectangle.lenght), width(rectangle.width), square(rectangle.square)
{
	cout << "������ ����������� ����������� Rectangle" << endl;
}
//���������� �������� �� ������������ ����
void Rectangle::inputFromConsole()
{
	cout << "������� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}
//���������� ������ ���� �� �����, ���� �� ������ ��������� �����, ������ ���� ���������� ������ �������
void Rectangle::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	lenght = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	width = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	calcylateSquare();
}

void Rectangle::printToConsole()
{
	Base::printToConsole();
	cout << "�����: " << lenght << endl;
	cout << "������: " << width << endl;
	cout << "�������: " << square << endl;
	cleardevice();
	rectangle(100, 100, 100 + lenght, 100 + width);
}

void Rectangle::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << lenght << endl;
	out << width << endl;
}

void Rectangle::change()
{
	cout << "������� ����� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}

void Rectangle::calcylateSquare() { square = lenght * width; }