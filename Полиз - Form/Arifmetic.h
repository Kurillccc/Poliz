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

	// ����������� � ����������� �� ���������
	arifmetic(string str = "")
	{
		poli = Poliz(str);
	}

	// ����������
	~arifmetic() {}

	// ����������� �����������
	arifmetic(const arifmetic& tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
	}

	// �������� ������������
	arifmetic& operator=(arifmetic tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
		return *this;
	}

	// ����� ��������� ���������� ��������������� ���������, ��������������� � ���� ������
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

	// ����� ��������� ������ �������� �� �����
	void SetVar(string key, float k)
	{
		int n = poli.GetOperand()->serchN(key);
		if (n > -1)
		{
			poli.setVar(n, k);
		}
	}

	// ����� ��������� ������ �������� �� �������
	void SetVar(int n, float k)
	{
		if (n > -1)
		{
			poli.setVar(n, k);
		}
	}
	// ����� ���������� ������� ���������
	Table* GetTableevarials()
	{
		return poli.GetOperand();
	}

	// ����� ���������� ������ ������ Poliz, ������� �������� �����
	Poliz GetA()
	{
		return poli;
	}
};