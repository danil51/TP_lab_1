#include "fabric.h"
//создаем конкретный объект по его названию
Base* createObj(string name)
{
	if (name == "Прямоугольник")
		return new Rect();
	if (name == "Шар")
		return new Sphere();
	string err = "Тип объекта не распознан";
	throw err;
}