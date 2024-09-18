#pragma once

#include <string>
using namespace std;


class Zapis
{
private:

	string Name;
	double value;

public:

	// ����������� � ����������� �� ���������
	Zapis(string _Name = "", double _value = 0.0)
	{
		Name = _Name;
		value = _value;
	}

	// ����� ��������� ���� Name
	string GetName()
	{
		return Name;
	}

	// ����� ��������� ���� value
	double GetValue()
	{
		return value;
	}

	// �����, ������� ������������� ����� �������� ��� value
	void SetValue(double _value)
	{
		value = _value;
	}
};