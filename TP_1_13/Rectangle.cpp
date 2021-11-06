#include "Rectangle.h"

Rectangle::Rectangle() : Base("Прямоугольник"), lenght(0), width(0), square(0)
{
	cout << "Вызван конструктор Rectangle" << endl;
}

Rectangle::Rectangle(double lenght, double width) :
	Base("Прямоугольник"), lenght(lenght), width(width)
{
	calcylateSquare();
	cout << "Вызван конструктор Rectangle" << endl;
}

Rectangle::Rectangle(const Rectangle& rectangle) :
	Base(rectangle), lenght(rectangle.lenght), width(rectangle.width), square(rectangle.square)
{
	cout << "Вызван конструктор копирования Rectangle" << endl;
}
//поочередно получаем от пользователя поля
void Rectangle::inputFromConsole()
{
	cout << "Введите длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}
//поочередно вводим поля из файла, если не смогли прочитать сроку, занчит файл закончился раньше времени
void Rectangle::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
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
	cout << "Длина: " << lenght << endl;
	cout << "Ширина: " << width << endl;
	cout << "Площадь: " << square << endl;
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
	cout << "Введите новую длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	calcylateSquare();
}

void Rectangle::calcylateSquare() { square = lenght * width; }