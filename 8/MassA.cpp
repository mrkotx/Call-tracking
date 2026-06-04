#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>

#include "MassA.h"
#include "MyClass.h"

using namespace std;

MassA::MassA() : c(NULL), k(0) {}
MassA::~MassA()
{
	if (c != nullptr)
	{
		delete[] c;
	}
}
MassA::MassA(MassA& z) : MyClass(z)
{
	k = z.k;
	if (z.c == nullptr)
	{
		c = nullptr;
	}
	else
	{
		c = new TALK[k];
		if (c == nullptr)
		{
			cout << "Нет памяти.\n";
			cout << "Конструктор копирования.\n";
			_getch(); exit(1);
		}
		for (int i = 0; i < k; i++)
		{
			c[i] = z.c[i];
		}
	}
}
MassA& MassA::operator=(MassA& z)
{
	if (this == &z) return *this;
	MyClass::operator=(z);
	if (c != NULL) delete[] c;
	k = z.k;
	if (z.c == NULL) c = NULL;
	else
	{
		c = new TALK[k];
		if (c == NULL)
		{
			cout << "Нет памяти.\n";
			cout << "Конструктор присваивания.\n";
			_getch(); return z;
		}
		for (int i = 0; i < k; i++)
		{
			c[i] = z.c[i];
		}
		return *this;
	}
}
void MassA::sort(bool (*compare) (const TALK& a, const TALK& b))
{
	TALK prop;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (compare(c[i], c[j]))
			{
				prop = c[i];
				c[i] = c[j];
				c[j] = prop;
			}
		}
	}
}
void MassA::findNumber()
{
	delete[] c; c = nullptr;
	int countNumbers = 0;
	TALK* prop = new TALK[n];
	string number;
	cout << "Введите номер: "; cin >> number;

	for (int i = 0; i < n; i++)
	{
		if (a[i].data.number == number)
		{
			prop[countNumbers] = a[i];
			countNumbers++;
		}
	}

	if (countNumbers > 0)
	{
		if (c != nullptr) delete[] c;
		c = prop;
		k = countNumbers;
		cout << "Найдено " << countNumbers << " записей.\n";
	}
	else
	{
		delete[] prop;
		delete[] c;
		c = nullptr;
		k = 0;
		cout << "Не найдено. Нажмите enter, чтобы продолжить...\n"; _getch();
	}
}
void MassA::saveFind(MassA& target)
{
	string filename;
	cout << "Введите название файла: "; cin >> filename;
	ofstream file(filename);
	file << target;
	file.close();
	cout << "Нажмите enter, чтобы продолжить...";
	_getch();
}
ofstream& operator<<(ofstream& file, MassA& afile)
{
	file << "________________________________________________________________________________________________________________\n"
		"|    |                     |               |                |                 |              |                 |\n"
		"|  N |        ФИО          |     Номер     | Дата разговора | Тариф за минуту | Время начала | Время окончания |\n"
		"|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	for (int i = 0; i < afile.k; i++)
		file << "| " << setw(2) << i + 1 << " | " << setw(19) << afile.c[i].data.fio << " | " << setw(13) << afile.c[i].data.number << " | " << setw(6) << afile.c[i].dateDay << "." << setw(2) << afile.c[i].dateMonth << "." << setw(4) << afile.c[i].dateYear << " | " << setw(15) << afile.c[i].money << " | " << setw(9) << afile.c[i].startTimeHours << ":" << setw(2) << afile.c[i].startTimeMinutes << " | " << setw(12) << afile.c[i].stopTimeHours << ":" << setw(2) << afile.c[i].stopTimeMinutes << " |" << endl;
	file << "|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	return file;
}