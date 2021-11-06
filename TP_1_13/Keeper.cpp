#include "Keeper.h"

Keeper::Keeper() : data(nullptr), size(0)
{
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(Base** data, int size)
{
	this->data = new Base * [size];
	this->size = size;
	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
	cout << "Вызван констукотр Keeper" << endl;
}

Keeper::Keeper(const Keeper& keeper)
{
	data = new Base * [keeper.size];
	size = keeper.size;
	for (int i = 0; i < size; i++)
		this->data[i] = keeper.data[i];
	cout << "Вызван констукотр копирования Keeper" << endl;
}

Keeper::~Keeper()
{
	size = 0;
	delete[] data;
	data = nullptr;
	cout << "Вызван деструктор Keeper" << endl;
}
//добавляем объект в кипер в конец
void Keeper::add(Base* base)
{
	Base** tmp = data; //бекап данных
	size++; //увеличиваем размер
	data = new Base * [size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i]; //переписываем из бекапа
	data[size - 1] = base; //новый добавляем в конец на свободную позицию
}
//удаяем по индексу
void Keeper::del(int index)
{
	if (index < 0 || index >= size)
		throw index;

	Base** tmp = new Base * [size - 1]; //новый размер меньше на 1, чем был
	int k = 0;
	//переписываем если индекс не равен удаляемому
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--; //уменьшаем размер
	data = tmp;
}

Base* Keeper::operator[](int index)
{
	if (index < 0 || index >= size)
		throw index;
	return data[index];
}

void Keeper::inputFromFile()
{
	ifstream input("keeper.txt");
	if (input.is_open())
	{
		string tmpS;
		int countRecord;
		if (!getline(input, tmpS)) //если мы не можем прочитать первую строчку, хотя она должна быть даже при нулевом размере, то ошибка
		{
			input.close();
			string err = "Файл не может быть прочитан";
			throw err;
		}
		countRecord = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
		try
		{
			for (int i = 0; i < countRecord; i++)
			{
				string err = "Файл не может быть корректно прочитан";
				if (!getline(input, tmpS)) //читаем тип объекта
					throw err;
				Base* obj = createObj(tmpS); //создаем объект нужного типа
				obj->inputFromFile(input, tmpS); //вводим его из файла
				this->add(obj); //добвляем в конец
			}
		}
		catch (string err)
		{
			input.close();
			throw err;
		}
		input.close();
	}
	else
	{
		//если файл не открылся, то ошибка
		string err = "Файл keeper.txt не найден";
		throw err;
	}
}

void Keeper::printToFile()
{
	ofstream output("keeper.txt");
	output << size << endl;
	for (int i = 0; i < size; i++)
		data[i]->printToFile(output); //вызываем метод вывода у хранимого класса
	output.close();
}

void Keeper::printToConsole()
{
	if (size == 0)
		cout << "Фигур нет" << endl;
	else
	{
		cout << "Фигуры: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			data[i]->printToConsole();
		}
	}
}