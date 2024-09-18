#pragma once

#include "Table.h"
#include "Stack.h"

class Poliz
{
private:

	// Метод для разделения строки на отдельные лексемы (процесс токенизации)
	void Algoritm10(string str, int& k, string* w)
	{
		string zn = "+-/^()";

		k = 0; // Инициализация счетчика токенов
		str += " ";
		for (int i = 0; i < str.length(); i++)
		{
			int l = zn.find(str[i]); // Поиск текущего символа в строке `zn`
			if (l >= 0 && l < zn.length())
			{
				if (w[k].length() > 0)
				{
					k++; // Если текущий токен не пустой, увеличиваем счетчик токенов
				}

				w[k] = str[i]; // Присваиваем текущему токену значение текущего символа
				w[++k] = ""; // Инициализация нового токена
			}

			else
			{
				// Если текущий символ - пробел и текущий токен не пустой, инициализируем новый токен
				if (str[i] == ' ')
				{
					if (w[k].length() > 0)
					{
						w[++k] = "";
					}
				}

				// Если текущий символ не является знаком операции или пробелом, добавляем его к текущему токену
				else
				{
					w[k] = w[k] + str[i];
				}
			}
		}
	}

	string* Pol; // Для хранения токенов
	int sizePol, countPol;

	string* Lex; // Для хранения лексем из входной строки
	int sizeLex, countLex;

	Stack <Zapis> ST; // Для обработки скобок
	Table operand, prior;

	// Метод создания таблицы приоритетов операторов и добавления записей
	void madeTableprior()
	{
		prior = Table(20);
		prior.add(Zapis("+", 1.0));
		prior.add(Zapis("-", 1.0));

		prior.add(Zapis("*", 2.0));
		prior.add(Zapis("/", 2.0));

		prior.add(Zapis("^", 3.0));
	}

	// Добавляет открывающую скобку в стек
	void Vecleft()
	{
		ST.pushback(Zapis("(", -1.0));
	}

	// Выталкивает операторы из стека в массив ПОЛИЗа до тех пор, пока не встретит открывающую скобку
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

	// Добавляет операнд в массив ПОЛИЗа и таблицу операндов
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

	// Обрабатывает операторы и добавляет их в массив ПОЛИЗа в соответствии с их приоритетами
	void Vecoperaci(string tmp, int p)
	{
		while (ST.is_empty() == 0 && ST.top().GetValue() >= p)
		{
			Pol[countPol++] = ST.pop().GetName();
		}

		ST.pushback(Zapis(tmp, p));
	}

	// Завершает формирование ПОЛИЗа, выталкивая все операторы из стека в массив ПОЛИЗа
	void VecKonecStr()
	{
		while (ST.is_empty() == 0)
		{
			Pol[countPol++] = ST.pop().GetName();
		}
	}

	// Метод сборки полиза
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

	// Конструктор
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

	// Конструктор копирования
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

	// Деструктор
	~Poliz()
	{
		delete[]Pol;
	}

	// Переопределение операции присваивания
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

	// Метод для доступа к элементам ПОЛИЗа
	string operator[](int R)
	{
		string str = "";

		if (R <= countPol && R >= 0)
		{
			str = Pol[R];
		}

		return str;
	}

	// Метод для доступа к таблице операндов
	Table* GetOperand()
	{
		return &operand;
	}

	// Можно получить строку, представляющую ПОЛИЗ
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

	// Этот метод возвращает количество элементов в ПОЛИЗе
	int getcount()
	{
		return countPol;
	}

	// Этот метод возвращает размер массива ПОЛИЗа
	int getSIZE()
	{
		return sizePol;
	}

	// Метод устанавливает новое числовое значение для записи с индексом n в таблице операндов
	void setVar(int n, float k)
	{
		operand.setWar(n, k);
	}
};