#pragma once

template <typename T>
class Stack
{
private:

	T* mem; // Массив (стек)
	int size; // Длина массива (длина стека)
	int count; // Число элементов в стеке

public:

	// Конструктор с параметрами по умолчанию
	Stack(int _size = 20)
	{
		size = _size;
		count = 0;
		mem = new T[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = T(); // Инициализация каждого элемента массива значениями по умолчанию
		}
	}

	// Конструктор копирования
	Stack(const Stack& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	// Деструктор
	~Stack()
	{
		delete[]mem;
	}

	Stack& operator = (Stack<T> tmp)
	{
		// Проверка, если размер текущего стека не совпадает с размером стека tmp
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]mem;
			}
			size = tmp.size;
			mem = new T[size];
		}

		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}

		return *this;
	}

	// Положить в стек
	void pushback(T val)
	{
		// Если есть место - добавляем
		if (count < size)
		{
			mem[count++] = val;
		}
	}

	// Посмотреть перхушку стека
	T top()
	{
		if (count > 0)
		{
			return mem[count - 1];
		}

		else
		{
			T r(0);
			return r; // Возвращает элемент с значением по умолчанию
		}
	}

	// Взять из стека - извлечение элемента из стека
	T pop()
	{
		if (count > 0)
		{
			return mem[--count];
		}

		else
		{
			T r(0);
			return r; // Возвращает элемент с значением по умолчанию
		}
	}

	// Контроль полноты
	int is_full()
	{
		if (count == size)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	// Контроль пустоты
	int is_empty()
	{
		if (count == 0)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	// Просмотр числа элементов в стеке
	int Getcount()
	{
		return count;
	}
};
