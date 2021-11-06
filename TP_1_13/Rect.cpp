#include "Rect.h"

Rect::Rect() : Base("Прямоугольник"), lenght(0), width(0), square(0)
{
	cout << "Вызван конструктор Rectangle" << endl;
}

Rect::Rect(double lenght, double width) :
	Base("Прямоугольник"), lenght(lenght), width(width)
{
	calcylateSquare();
	cout << "Вызван конструктор Rectangle" << endl;
}

Rect::Rect(const Rect& rect) :
	Base(rect), lenght(rect.lenght), width(rect.width), square(rect.square)
{
	cout << "Вызван конструктор копирования Rectangle" << endl;
}
//поочередно получаем от пользователя поля
void Rect::inputFromConsole()
{
	cout << "Введите длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}
//поочередно вводим поля из файла, если не смогли прочитать сроку, занчит файл закончился раньше времени
void Rect::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
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
	cout << "Длина: " << lenght << endl;
	cout << "Ширина: " << width << endl;
	cout << "Площадь: " << square << endl;
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
	cout << "Введите новую длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}

void Rect::calcylateSquare() { square = lenght * width; }
