#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>

#include "MassB.h"
#include "MyClass.h"

using namespace std;

MassB::MassB() : b(NULL), k(0) {}
MassB::~MassB() // деструктор
{
	if (b != nullptr)
	{
		delete[] b;
	}
}
MassB::MassB(MassB& z) : MassA(z) //конструктор копирования
{
	k = z.k;
	if (z.b == nullptr)
	{
		b = nullptr;
	}
	else
	{
		b = new TALK[k];
		if (b == nullptr)
		{
			cout << "Нет памяти.\n";
			cout << "Конструктор копирования.\n";
			_getch(); exit(1);
		}
		for (int i = 0; i < k; i++)
		{
			b[i] = z.b[i];
		}
	}
}
MassB& MassB::operator=(MassB& z)
{
	if (this == &z) return *this;
	MassA::operator=(z);
	if (b != NULL) delete[] b;
	k = z.k;
	if (z.b == NULL) b = NULL;
	else
	{
		b = new TALK[k];
		if (b == NULL)
		{
			cout << "Нет памяти.\n";
			cout << "Конструктор присваивания.\n";
			_getch(); return z;
		}
		for (int i = 0; i < k; i++)
		{
			b[i] = z.b[i];
		}
	}
	return *this;
}
void MassB::sort(bool(*compare)(const TALK& a, const TALK& b))
{
	TALK prop;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (compare(b[i], b[j]))
			{
				prop = b[i];
				b[i] = b[j];
				b[j] = prop;
			}
		}
	}
}
void MassB::makePerech()
{
	int uniqueNum = 0;

	if (n <= 0)
	{
		cout << "Нет данных.\n"; _getch();
		return;
	}
	TALK* prop = new TALK[n];

	for (int i = 0; i < n; i++)
	{
		bool found = false;
		for (int j = 0; j < uniqueNum; j++)
		{
			if (a[i].data.number == prop[j].data.number)
			{
				prop[j].callCount++;
				found = true;
			}
		}
		if (!found)
		{
			prop[uniqueNum].data.fio = a[i].data.fio;
			prop[uniqueNum].data.number = a[i].data.number;
			prop[uniqueNum].callCount = 1;
			uniqueNum++;
		}
	}
	delete[] b; b = nullptr; // удаление старого массива
	k = uniqueNum;
	b = new TALK[k];
	for (int j = 0; j < k; j++)
	{
		b[j] = prop[j];
	}
	delete[] prop;
	cout << "Перечень сформирован.\n";
}
void MassB::savePerech(MassB& target)
{
	string filename;
	cout << "Введите название файла: "; cin >> filename;
	ofstream file(filename);
	file << target;
	file.close();
	cout << "Нажмите enter, чтобы продолжить...";
	_getch();
}
ofstream& operator<<(ofstream& file, MassB& bfile)
{
	file << "_________________________________________________________________\n"
		"|    |                     |               |                    |\n"
		"|  N |        ФИО          |     Номер     | Количество звонков |\n"
		"|____|_____________________|_______________|____________________|" << endl;
	for (int i = 0; i < bfile.k; i++)
		file << "| " << setw(2) << i + 1 << " | " << setw(19) << bfile.b[i].data.fio << " | " << setw(13) << bfile.b[i].data.number << " | " << setw(18) << bfile.b[i].callCount << " |" << endl;
	file << "|____|_____________________|_______________|____________________|" << endl;
	return file;
}