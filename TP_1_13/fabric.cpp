#include "fabric.h"
//������� ���������� ������ �� ��� ��������
Base* createObj(string name)
{
	if (name == "�������������")
		return new Rect();
	if (name == "���")
		return new Sphere();
	string err = "��� ������� �� ���������";
	throw err;
}