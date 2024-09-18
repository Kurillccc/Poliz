#pragma once

#include <string>
using namespace std;


class Zapis
{
private:

	string Name;
	double value;

public:

	// Конструктор с параметрами по умолчанию
	Zapis(string _Name = "", double _value = 0.0)
	{
		Name = _Name;
		value = _value;
	}

	// Метод получения поля Name
	string GetName()
	{
		return Name;
	}

	// Метод получения поля value
	double GetValue()
	{
		return value;
	}

	// Метод, который устанавливает новое значение для value
	void SetValue(double _value)
	{
		value = _value;
	}
};