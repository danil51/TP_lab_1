#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Keeper& keeper);
void changeObject(Keeper& keeper);
void deleteObject(Keeper& keeper);
void printObject(Keeper& keeper);

int main()
{
	//инициализация графического окна
	int gm, gd = DETECT;
	char a[2] = " ";
	initgraph(&gd, &gm, a);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper keeper;

	cout << "Ввести изначальные данные из файла?(1/0)" << endl;
	int method = safeInput(0, 1);
	try
	{
		if (method == 1)
			keeper.inputFromFile();
	}
	catch (string err)
	{
		cout << err << endl;
	}


	bool isExit = false;
	while (!isExit) {
		printMenu();
		method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(keeper);
			break;
		case 2:
			changeObject(keeper);
			break;
		case 3:
			deleteObject(keeper);
			break;
		case 4:
			keeper.printToConsole();
			break;
		case 5:
			printObject(keeper);
			break;
		case 6:
			keeper.printToFile();
			break;
		case 0:
			isExit = true;
			break;
		}
	}

	//закрытие графического окна
	closegraph();
}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные на экран" << endl;
	cout << "5. Отрисовать фигуру на экране" << endl;
	cout << "6. Сохранить в файл" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Keeper& keeper)
{
	cout << "Выберете объект для добавления" << endl;
	cout << "1. Прямоугольник" << endl;
	cout << "2. Шар" << endl;
	int typeInt = safeInput(1, 2);
	string typeS;
	if (typeInt == 1)
		typeS = "Прямоугольник";
	if (typeInt == 2)
		typeS = "Шар";
	Base* object = createObj(typeS);
	object->inputFromConsole();
	keeper.add(object);
}

void changeObject(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "Фигур нет. Нечего изменять" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер объекта для изменения: ";
		int number = safeInput(1, keeper.getSize());
		keeper[number - 1]->change();
	}
}

void deleteObject(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "Фигур нет. Нечего удалять" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер объекта для удаления: ";
		int number = safeInput(1, keeper.getSize());
		keeper.del(number - 1);
	}
}

void printObject(Keeper& keeper) {
	if (keeper.getSize() == 0)
		cout << "Фигур нет. Нечего рисовать" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер объекта для рисования: ";
		int number = safeInput(1, keeper.getSize());
		keeper[number - 1]->print();
	}
}