#pragma once

#include "Table.h"
#include "Stack.h"

class Poliz
{
private:

	// ����� ��� ���������� ������ �� ��������� ������� (������� �����������)
	void Algoritm10(string str, int& k, string* w)
	{
		string zn = "+-/^()";

		k = 0; // ������������� �������� �������
		str += " ";
		for (int i = 0; i < str.length(); i++)
		{
			int l = zn.find(str[i]); // ����� �������� ������� � ������ `zn`
			if (l >= 0 && l < zn.length())
			{
				if (w[k].length() > 0)
				{
					k++; // ���� ������� ����� �� ������, ����������� ������� �������
				}

				w[k] = str[i]; // ����������� �������� ������ �������� �������� �������
				w[++k] = ""; // ������������� ������ ������
			}

			else
			{
				// ���� ������� ������ - ������ � ������� ����� �� ������, �������������� ����� �����
				if (str[i] == ' ')
				{
					if (w[k].length() > 0)
					{
						w[++k] = "";
					}
				}

				// ���� ������� ������ �� �������� ������ �������� ��� ��������, ��������� ��� � �������� ������
				else
				{
					w[k] = w[k] + str[i];
				}
			}
		}
	}

	string* Pol; // ��� �������� �������
	int sizePol, countPol;

	string* Lex; // ��� �������� ������ �� ������� ������
	int sizeLex, countLex;

	Stack <Zapis> ST; // ��� ��������� ������
	Table operand, prior;

	// ����� �������� ������� ����������� ���������� � ���������� �������
	void madeTableprior()
	{
		prior = Table(20);
		prior.add(Zapis("+", 1.0));
		prior.add(Zapis("-", 1.0));

		prior.add(Zapis("*", 2.0));
		prior.add(Zapis("/", 2.0));

		prior.add(Zapis("^", 3.0));
	}

	// ��������� ����������� ������ � ����
	void Vecleft()
	{
		ST.pushback(Zapis("(", -1.0));
	}

	// ����������� ��������� �� ����� � ������ ������ �� ��� ���, ���� �� �������� ����������� ������
	void Vecrigth()
	{
		while ((ST.is_empty() == 0) && (ST.top().GetName() != "("))
		{
			Pol[countPol++] = ST.pop().GetName();
		}

		if (ST.top().GetName() == "(")
		{
			ST.pop();
		}
	}

	// ��������� ������� � ������ ������ � ������� ���������
	void Vecoperand(string tmp)
	{
		Pol[countPol++] = tmp;

		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			operand.add(Zapis(tmp, stof(tmp)));
		}

		else
		{
			operand.add(Zapis(tmp, 0.0));
		}
	}

	// ������������ ��������� � ��������� �� � ������ ������ � ������������ � �� ������������
	void Vecoperaci(string tmp, int p)
	{
		while (ST.is_empty() == 0 && ST.top().GetValue() >= p)
		{
			Pol[countPol++] = ST.pop().GetName();
		}

		ST.pushback(Zapis(tmp, p));
	}

	// ��������� ������������ ������, ���������� ��� ��������� �� ����� � ������ ������
	void VecKonecStr()
	{
		while (ST.is_empty() == 0)
		{
			Pol[countPol++] = ST.pop().GetName();
		}
	}

	// ����� ������ ������
	void madePoliz()
	{
		countPol = 0;

		for (int i = 0; i < countLex; i++)
		{
			if (Lex[i] == "(")
			{
				Vecleft();
			}

			else
			{
				if (Lex[i] == ")") {
					Vecrigth();
				}

				else
				{
					int p = prior.searchI(Lex[i]);
					if (p > -1)
					{
						Vecoperaci(Lex[i], p);
					}

					else
					{
						Vecoperand(Lex[i]);
					}
				}
			}
		}

		VecKonecStr();
	}

public:

	// �����������
	Poliz(string str = "")
	{
		countPol = 0;
		sizePol = str.length() + 1;
		operand = Table(sizePol);
		Pol = new string[sizePol];

		countLex = 0;
		sizeLex = sizePol + 1;
		Lex = new string[sizeLex];

		Algoritm10(str, countLex, Lex);
		madeTableprior();

		ST = Stack<Zapis>(20);
		madePoliz();
	}

	// ����������� �����������
	Poliz(const Poliz& tmp)
	{
		sizePol = tmp.sizePol;
		countPol = tmp.countPol;
		Pol = new string[sizePol];

		for (int i = 0; i < sizePol; i++)
		{
			Pol[i] = tmp.Pol[i];
		}

		ST = tmp.ST;
		operand = tmp.operand;
		prior = tmp.prior;
	}

	// ����������
	~Poliz()
	{
		delete[]Pol;
	}

	// ��������������� �������� ������������
	Poliz& operator = (Poliz tmp)
	{
		if (sizePol != tmp.sizePol)
		{
			if (sizePol != 0)
			{
				delete[]Pol;
			}

			sizePol = tmp.sizePol;
			Pol = new string[sizePol];
		}

		countPol = tmp.countPol;
		for (int i = 0; i < sizePol; i++)
		{
			Pol[i] = tmp.Pol[i];
		}

		ST = tmp.ST;
		operand = tmp.operand;
		prior = tmp.prior;

		return *this;
	}

	// ����� ��� ������� � ��������� ������
	string operator[](int R)
	{
		string str = "";

		if (R <= countPol && R >= 0)
		{
			str = Pol[R];
		}

		return str;
	}

	// ����� ��� ������� � ������� ���������
	Table* GetOperand()
	{
		return &operand;
	}

	// ����� �������� ������, �������������� �����
	string GetStringPoliz()
	{
		string str = "";
		str += Pol[0];

		for (int i = 1; i < countPol; i++)
		{
			str += " " + Pol[i];
		}

		return str;
	}

	// ���� ����� ���������� ���������� ��������� � ������
	int getcount()
	{
		return countPol;
	}

	// ���� ����� ���������� ������ ������� ������
	int getSIZE()
	{
		return sizePol;
	}

	// ����� ������������� ����� �������� �������� ��� ������ � �������� n � ������� ���������
	void setVar(int n, float k)
	{
		operand.setWar(n, k);
	}
};