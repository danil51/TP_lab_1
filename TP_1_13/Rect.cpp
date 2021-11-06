#include "Rect.h"

Rect::Rect() : Base("�������������"), lenght(0), width(0), square(0)
{
	cout << "������ ����������� Rectangle" << endl;
}

Rect::Rect(double lenght, double width) :
	Base("�������������"), lenght(lenght), width(width)
{
	calcylateSquare();
	cout << "������ ����������� Rectangle" << endl;
}

Rect::Rect(const Rect& rect) :
	Base(rect), lenght(rect.lenght), width(rect.width), square(rect.square)
{
	cout << "������ ����������� ����������� Rectangle" << endl;
}
//���������� �������� �� ������������ ����
void Rect::inputFromConsole()
{
	cout << "������� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}
//���������� ������ ���� �� �����, ���� �� ������ ��������� �����, ������ ���� ���������� ������ �������
void Rect::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	lenght = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	width = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	calcylateSquare();
}

void Rect::printToConsole()
{
	Base::printToConsole();
	cout << "�����: " << lenght << endl;
	cout << "������: " << width << endl;
	cout << "�������: " << square << endl;
}

void Rect::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << lenght << endl;
	out << width << endl;
}

void Rect::print() {
	cleardevice();
	rectangle(100, 100, 100 + lenght, 100 + width);
}

void Rect::change()
{
	cout << "������� ����� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}

void Rect::calcylateSquare() { square = lenght * width; }
