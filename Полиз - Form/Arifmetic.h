#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Poliz.h"

class arifmetic
{
private:

	Poliz poli;
	Stack <double> st;

public:

	// Конструктор с параметрами по умолчанию
	arifmetic(string str = "")
	{
		poli = Poliz(str);
	}

	// Деструктор
	~arifmetic() {}

	// Конструктор копирования
	arifmetic(const arifmetic& tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
	}

	// Оператор присваивания
	arifmetic& operator=(arifmetic tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
		return *this;
	}

	// Метод выполняет вычисление арифметического выражения, представленного в виде ПОЛИЗа
	double calculate()
	{
		double right, res, left;
		Table* Table = poli.GetOperand();
		Stack <double> st(poli.getcount());

		for (int i = 0; i < poli.getcount(); i++)
		{
			res = Table->searchI(poli[i]);
			if (res != -1)
			{
				st.pushback(res);
			}

			else
			{
				right = st.pop();
				left = st.pop();
				if (poli[i] == "+")
				{
					st.pushback(left + right);
				}
				if (poli[i] == "-")
				{
					st.pushback(left - right);
				}
				if (poli[i] == "*")
				{
					st.pushback(left * right);
				}
				if (poli[i] == "/")
				{
					st.pushback(left / right);
				}
				if (poli[i] == "^")
				{
					st.pushback(pow(left, right));
				}
			}
		}

		return st.pop();
	}

	// Метод установки нового значения по ключу
	void SetVar(string key, float k)
	{
		int n = poli.GetOperand()->serchN(key);
		if (n > -1)
		{
			poli.setVar(n, k);
		}
	}

	// Метод установки нового значения по индексу
	void SetVar(int n, float k)
	{
		if (n > -1)
		{
			poli.setVar(n, k);
		}
	}
	// Метод возвращает таблицу операндов
	Table* GetTableevarials()
	{
		return poli.GetOperand();
	}

	// Метод возвращает объект класса Poliz, который содержит ПОЛИЗ
	Poliz GetA()
	{
		return poli;
	}
};