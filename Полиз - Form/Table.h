#pragma once

#include <string>
#include "Zapis.h"

class Table
{
private:

	Zapis* mem;
	int size; // Размер массива
	int count; // Количество элементов в массиве

public:

	// Конструктор с параметрами по умолчанию
	Table(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new Zapis[size];

		// Инициализация каждого элемента массива объектов Zapis значениями по умолчанию
		for (int i = 0; i < size; i++)
		{
			mem[i] = Zapis("", 0);
		}
	}

	// Деструктор
	~Table()
	{
		delete[] mem;
	}

	// Перегрузка оператора присваивания
	Table& operator = (Table tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]mem;
			}
			size = tmp.size;
			mem = new Zapis[size];
		}

		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}

		return *this;
	}

	// Конструктор копирования
	Table(const Table& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new Zapis[size];

		// Копируем значения из другого объекта таблицы tmp
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	// Метод, осуществляющий поиск индекса нужного элемента по имени
	int serchN(string key)
	{
		int i = 0;
		int res = -1;

		while (res == -1 && i < count)
		{
			if (key == mem[i].GetName())
			{
				res = i;
			}
			i++;
		}

		return res;
	}

	// Метод, возвращающий количество элементов в таблице
	int getCount()
	{
		return count;
	}

	// Метод, добавляющий запись tmp в таблицу
	void add(Zapis tmp)
	{
		int l = serchN(tmp.GetName());

		if (l > -1)
		{
			// Если запись с таким именем уже существует, заменяет её
			mem[l] = tmp;
		}

		else
		{
			mem[count++] = tmp;
		}
	}

	void add(string key, int temp)
	{
		Zapis a(key, temp);

		add(a);
	}

	// Метод, удаляющий запись с заданным именем из таблицы
	void del(string key)
	{
		int c = serchN(key);

		if (c > -1)
		{
			mem[c] = mem[--count];
		}
	}

	// Проверка на пустоту
	int isEmpty()
	{
		if (count == 0)
		{
			return 1; // Пустая таблица
		}

		else
		{
			return 0; // Непустая таблица
		}
	}

	// Проверка на полноту
	int isFull()
	{
		if (count == size)
		{
			return 1; // Таблица заполнена
		}

		else
		{
			return 0; // Таблица не заполнена
		}
	}

	// Метод, осуществляющий поиск значения по имени
	double searchI(string key)
	{
		int l = -1, i = 0;
		double res = 0;

		// Пока не найден элемент с указанным именем и не достигнут конец массива
		while ((l == -1) && (i <= count))
		{
			if (key == mem[i].GetName())
			{
				// Сохраняем индекс элемента
				l = i;
			}
			i++;
		}

		// Если элемент с указанным именем найден
		if (l > -1)
		{
			// Возвращаем числовое значение найденной записи
			return mem[l].GetValue();
		}

		return -1;
	}

	// Перегрузка оператора [] (доступ к элементам таблицы по индексу)
	Zapis operator[](int key)
	{
		Zapis res;
		if (key > -1 && key <= count)
		{
			res = mem[key];
		}

		return res;
	}

	// Метод устанавливает новое числовое значение для записи с индексом n
	void setWar(int n, double k)
	{
		if (n >= size) return;


		mem[n].SetValue(k);
	}
};
