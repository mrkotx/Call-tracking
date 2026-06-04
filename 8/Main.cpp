#include <iostream>
#include <windows.h>
#include <conio.h>

#include "MyClass.h"
#include "MassA.h"
#include "MassB.h"
#include "SortVar.h"
#include "Operators.h"
#include "Structures.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	int n = 0;
	MassB child;
	while (true)
	{
		system("cls");
		child.menu();

		int choice;
		bool rightInput = false;

		while (!rightInput)
		{
			cout << "Введите число от 1-19: ";
			cin >> choice;
			if (cin.fail())
			{
				cout << "Ошибка. Нужно ввести число." << endl;
				cin.clear(); cin.ignore(32767, '\n');
			}
			else if (choice >= 0 && choice <= 19)
			{
				rightInput = true;
			}
			else
			{
				cout << "Нет такой опции." << endl;
				cin.clear(); cin.ignore(32767, '\n');
			}
		}
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			child.loadFromFile(child);
			break;
		case 2:
			cout << (MyClass&)child;
			_getch();
			break;
		case 3:
			child.addData();
			break;
		case 4:
			child.saveData(child);
			break;
		case 5:
			child.deleteData();
			break;
		case 6:
			child.sortAlphabet();
			break;
		case 7:
			child.sortDate();
			break;
		case 8:
			child.sortTime();
			break;
		case 9:
			child.clearMassive();
			break;
		case 10:
		{
			MassB test(child);
			cout << (MyClass&)test << (MyClass&)child;
			cout << (MassA&)test << (MassA&)child;
			cout << (MassB&)test << (MassB&)child;
			test.MyClass::sort(fioDown);
			test.MassA::sort(timeDown);
			test.MassB::sort(numDown);
			_getch();
			cout << "После сортировки\n";
			cout << (MyClass&)test << (MyClass&)child;
			cout << (MassA&)test << (MassA&)child;
			cout << (MassB&)test << (MassB&)child;
			_getch();
			break;
		}
		case 11:
		{
			MassB a, b;
			a = b = child;
			cout << (MyClass&)child << (MyClass&)b << (MyClass&)a;
			cout << (MassA&)child << (MassA&)b << (MassA&)a;
			cout << (MassB&)child << (MassB&)b << (MassB&)a;
			_getch();
			cout << "После сортировки\n";
			a.MyClass::sort(fioDown);
			a.MassA::sort(timeDown);
			a.MassB::sort(numDown);
			cout << (MyClass&)child << (MyClass&)b << (MyClass&)a;
			cout << (MassA&)child << (MassA&)b << (MassA&)a;
			cout << (MassB&)child << (MassB&)b << (MassB&)a;
			_getch();
			break;
		}
		case 12: // поиск
		{
			child.findNumber();
			cout << (MassA&)child;
			_getch();
			break;
		}
		case 13: // перечень
		{
			child.makePerech();
			cout << (MassB&)child;
			_getch();
			break;
		}
		case 14:
		{
			child.saveFind(child);
			break;
		}
		case 15:
		{
			child.savePerech(child);
			break;
		}
		case 16:
		{
			cout << (MassA&)child;
			_getch();
			break;
		}
		case 17:
		{
			cout << (MassB&)child;
			_getch();
			break;
		}
		case 18: // сортировка поиска
		{
			int choice = 0;
			bool passed = false;
			while (!passed)
			{
				choice = 0;
				cout << "1. Сортировка по дате\n"
					"2. Сортировка по длительности\n"
					"3. Выход\n"; cin >> choice;
				if (!cin.fail() and choice != 0 and choice != 3) { passed = true; }
				else if (choice == 3) { cout << "Отмена..."; break; }
				else { cout << "Неверная опция. Введите 1 или 2"; }
			}
			if (choice == 1)
			{
				passed = false;
				while (!passed)
				{
					choice = 0;
					cout << "1. Возрастающая\n"
						"2. Убывающая\n"
						"3. Выход\n"; cin >> choice;
					if (!cin.fail() and choice != 3) { passed = true; }
					else if (choice == 3) { cout << "Отмена..."; break; }
					else { cout << "Неверная опция. Введите 1 или 2"; }
				}
				if (choice == 1)
				{
					child.sort(dateUp);
					cout << (MassA&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
				else if (choice == 2)
				{
					child.sort(dateDown);
					cout << (MassA&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
			}
			else if (choice == 2)
			{
				passed = false;
				while (!passed)
				{
					choice = 0;
					cout << "1. Возрастающая\n"
						"2. Убывающая\n"
						"3. Выход\n"; cin >> choice;
					if (!cin.fail() and choice != 0 and choice != 3) { passed = true; }
					else if (choice == 3) { cout << "Отмена..."; break; }
					else { cout << "Неверная опция. Введите 1 или 2"; }
				}
				if (choice == 1)
				{
					child.sort(timeUp);
					cout << (MassA&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
				else if (choice == 2)
				{
					child.sort(timeDown);
					cout << (MassA&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
			}
			_getch();
			break;
		}
		case 19: // сортировка перечня
		{
			int choice = 0;
			bool passed = false;
			while (!passed)
			{
				choice = 0;
				cout << "1. Сортировка по ФИО\n"
					"2. Сортировка по количеству звонков\n"
					"3. Сортировка по номеру\n"
					"4. Выход\n"; cin >> choice;
				if (!cin.fail() and choice != 0 and choice != 4) { passed = true; }
				else if (choice == 4) { cout << "Отмена..."; break; }
				else { cout << "Неверная опция. Введите 1 или 2"; }
			}
			if (choice == 1)
			{
				passed = false;
				while (!passed)
				{
					choice = 0;
					cout << "1. Возрастающая\n"
						"2. Убывающая\n"
						"3. Выход\n"; cin >> choice;
					if (!cin.fail() and choice != 0 and choice != 3) { passed = true; }
					else if (choice == 3) { cout << "Отмена..."; break; }
					else { cout << "Неверная опция. Введите 1 или 2"; }
				}
				if (choice == 1)
				{
					child.sort(fioUp);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
				else if (choice == 2)
				{
					child.sort(fioDown);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
			}
			else if (choice == 2)
			{
				passed = false;
				while (!passed)
				{
					choice = 0;
					cout << "1. Возрастающая\n"
						"2. Убывающая\n"
						"3. Выход\n"; cin >> choice;
					if (!cin.fail() and choice != 0 and choice != 3) { passed = true; }
					else if (choice == 3) { cout << "Отмена..."; break; }
					else { cout << "Неверная опция. Введите 1 или 2"; }
				}
				if (choice == 1)
				{
					child.sort(callUp);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
				else if (choice == 2)
				{
					child.sort(callDown);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}

			}
			else if (choice == 3)
			{
				passed = false;
				while (!passed)
				{
					choice = 0;
					cout << "1. Возрастающая\n"
						"2. Убывающая\n"
						"3. Выход\n"; cin >> choice;
					if (!cin.fail() and choice != 0 and choice != 3) { passed = true; }
					else if (choice == 3) { cout << "Отмена..."; break; }
					else { cout << "Неверная опция. Введите 1 или 2"; }
				}
				if (choice == 1)
				{
					child.sort(numUp);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
				else if (choice == 2)
				{
					child.sort(numDown);
					cout << (MassB&)child;
					cout << "Успешно. Нажмите enter, чтобы продолжить...";
				}
			}
			_getch();
			break;
		}
		default:
			cout << "Нет такой команды." << endl;
			_getch();
			break;
		}
	}
}