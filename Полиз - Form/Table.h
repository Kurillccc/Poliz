#pragma once

#include <string>
#include "Zapis.h"

class Table
{
private:

	Zapis* mem;
	int size; // ������ �������
	int count; // ���������� ��������� � �������

public:

	// ����������� � ����������� �� ���������
	Table(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new Zapis[size];

		// ������������� ������� �������� ������� �������� Zapis ���������� �� ���������
		for (int i = 0; i < size; i++)
		{
			mem[i] = Zapis("", 0);
		}
	}

	// ����������
	~Table()
	{
		delete[] mem;
	}

	// ���������� ��������� ������������
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

	// ����������� �����������
	Table(const Table& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new Zapis[size];

		// �������� �������� �� ������� ������� ������� tmp
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	// �����, �������������� ����� ������� ������� �������� �� �����
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

	// �����, ������������ ���������� ��������� � �������
	int getCount()
	{
		return count;
	}

	// �����, ����������� ������ tmp � �������
	void add(Zapis tmp)
	{
		int l = serchN(tmp.GetName());

		if (l > -1)
		{
			// ���� ������ � ����� ������ ��� ����������, �������� �
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

	// �����, ��������� ������ � �������� ������ �� �������
	void del(string key)
	{
		int c = serchN(key);

		if (c > -1)
		{
			mem[c] = mem[--count];
		}
	}

	// �������� �� �������
	int isEmpty()
	{
		if (count == 0)
		{
			return 1; // ������ �������
		}

		else
		{
			return 0; // �������� �������
		}
	}

	// �������� �� �������
	int isFull()
	{
		if (count == size)
		{
			return 1; // ������� ���������
		}

		else
		{
			return 0; // ������� �� ���������
		}
	}

	// �����, �������������� ����� �������� �� �����
	double searchI(string key)
	{
		int l = -1, i = 0;
		double res = 0;

		// ���� �� ������ ������� � ��������� ������ � �� ��������� ����� �������
		while ((l == -1) && (i <= count))
		{
			if (key == mem[i].GetName())
			{
				// ��������� ������ ��������
				l = i;
			}
			i++;
		}

		// ���� ������� � ��������� ������ ������
		if (l > -1)
		{
			// ���������� �������� �������� ��������� ������
			return mem[l].GetValue();
		}

		return -1;
	}

	// ���������� ��������� [] (������ � ��������� ������� �� �������)
	Zapis operator[](int key)
	{
		Zapis res;
		if (key > -1 && key <= count)
		{
			res = mem[key];
		}

		return res;
	}

	// ����� ������������� ����� �������� �������� ��� ������ � �������� n
	void setWar(int n, double k)
	{
		if (n >= size) return;


		mem[n].SetValue(k);
	}
};
