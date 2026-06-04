#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#include "MyClass.h"
#include "SortVar.h"
#include "Operators.h"

using namespace std;
string ofilename;
MyClass::MyClass() : a(NULL), n(0) {}
MyClass::~MyClass() {
	if (a != NULL) {
		delete[] a;
	}
}
MyClass::MyClass(MyClass& z) {
	n = z.n;
	if (n == 0) {
		a = NULL;
		cout << "test" << endl;
	}
	else {
		a = new TALK[n];
		if (a == nullptr) {
			cout << "Нет памяти" << endl;
			exit(1);
		}
		for (int i = 0; i < n; i++) {
			a[i] = z.a[i];
		}
	}
}
MyClass& MyClass::operator=(MyClass& z) {
	if (this == &z) {
		return *this;
	}
	if (a != NULL) {
		delete[] a;
	}
	n = z.n;
	if (z.a == NULL) {
		a = NULL;
	}
	else {
		a = new TALK[n];
		if (a == NULL) {
			cout << "Нет памяти" << endl;
			_getch();
			exit(1);
		}
		for (int i = 0; i < n; i++) {
			a[i] = z.a[i];
		}
		return *this;
	}
}
void MyClass::menu()
{
	cout << "Главное меню" << endl;
	cout << "1. Загрузить из файла" << endl;
	cout << "2. Вывести данные" << endl;
	cout << "3. Внести данные" << endl;
	cout << "4. Сохранить данные" << endl;
	cout << "5. Удалить данные" << endl;
	cout << "6. Сортировка ФИО по алфавиту" << endl;
	cout << "7. Сортировка по дате разговора" << endl;
	cout << "8. Сортировка по длительности разговора" << endl;
	cout << "9. Очистить массив" << endl;
	cout << "10. Проверка копирования" << endl;
	cout << "11. Проверка присваивания" << endl;
	cout << "12. Поиск по номеру" << endl;
	cout << "13. Перечень номеров" << endl;
	cout << "14. Сохранить поиск номеров" << endl;
	cout << "15. Сохранить перечень номеров" << endl;
	cout << "16. Показать поиск номеров" << endl;
	cout << "17. Показать перечень номеров" << endl;
	cout << "18. Сортировка поиска" << endl;
	cout << "19. Сортировка перечня" << endl;
	cout << "0. Выйти" << endl;
}
void MyClass::getTable()
{
	cout << *this;
}
void MyClass::loadFromFile(MyClass& a)
{
	ifstream fin;
	fin >> a;
	_getch();
}
void MyClass::saveInFile()
{
	ofstream file(ofilename);
	for (int i = 0; i < n; i++)
	{
		file << a[i].data.fio << " " << a[i].data.number << " " << a[i].dateDay << "." << a[i].dateMonth << "." << a[i].dateYear << " " << a[i].money << " " << a[i].startTimeHours << ":" << a[i].startTimeMinutes << " " << a[i].stopTimeHours << ":" << a[i].stopTimeMinutes << "\n";
	}
}
void MyClass::addData()
{
	TALK* newArr = new TALK[n + 1];
	for (int i = 0; i < n; i++)
	{
		newArr[i] = a[i];
	}
	if (a != nullptr)
	{
		delete[] a;
	}
	a = newArr;

	cin >> a[n]; //Ввод данных
	//Новая строка
	n += 1;

	cout << "Вы закончили ввод. Нажмите enter, чтобы продолжить...";
	saveInFile();
	_getch();

}
void MyClass::showData()
{
	getTable();
	cout << "Нажмите enter, чтобы продолжить...";
	_getch();
}
void MyClass::saveData(MyClass& target)
{
	string filename; cout << "Введите название файла (отмена - 0): "; cin >> filename;
	if (filename != "0")
	{
		ofstream out(filename);
		out << target;
		out.close();
		cout << "Нажмите enter, чтобы продолжить...";
		_getch();
	}
	else
	{
		cout << "Отмена действия. Нажмите enter, чтобы продолжить..." << endl;
		_getch();
	}
}
void MyClass::deleteData()
{
	if (n != 0)
	{
		getTable();
		int stroka;
		cout << "Введите индекс строки: ";
		do
		{
			cin >> stroka;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Индекс должен быть числовой. Введите индекс строки: ";
			}
			else if (stroka > 0 && stroka <= n)
			{
				break;
			}
			else
			{
				cout << "Неверный индекс. Введите число от 1 до " << n << ": ";
			}
		} while (true);
		string choice;
		bool confirmed = false;

		cout << "Строка, которую вы хотите удалить: " << endl;
		cout << "| " << setw(2) << stroka << " | " << setw(19) << a[stroka - 1].data.fio << " | " << setw(13) << a[stroka - 1].data.number << " | " << setw(6) << a[stroka - 1].dateDay << "." << setw(2) << a[stroka - 1].dateMonth << "." << setw(4) << a[stroka - 1].dateYear << " | " << setw(15) << a[stroka - 1].money << " | " << setw(9) << a[stroka - 1].startTimeHours << ":" << setw(2) << a[stroka - 1].startTimeMinutes << " | " << setw(12) << a[stroka - 1].stopTimeHours << ":" << setw(2) << a[stroka - 1].stopTimeMinutes << " |" << endl;
		cout << "Вы уверены? (y/n): ";
		do
		{
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				confirmed = true;
				break;
			}
			else if (choice == "n" || choice == "N")
			{
				cout << "Действие отменено. Нажмите enter, чтобы продолжить...";
				_getch();
				return;
			}
			else
			{
				cout << "Неверный ввод. Введите 'y' либо 'n': ";
			}
		} while (true);

		if (confirmed)
		{
			//новый дин массив
			TALK* newArr = new TALK[n - 1];
			//удаление
			for (int i = stroka - 1; i < n - 1; i++)
				a[i] = a[i + 1];
			n -= 1;
			//перезапись
			for (int i = 0; i < n; i++)
				newArr[i] = a[i];
			//очищаем
			delete[] a;
			//присваиваем
			a = newArr;

			saveInFile();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
		}
	}
	else
	{
		cout << "Таблица пуста. Нажмите enter, чтобы продолжить...";
		_getch();
	}
}
void MyClass::sort(bool(*compare)(const TALK&, const TALK&))
	{
		TALK prop;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (compare(a[i], a[j]))
				{
					prop = a[i];
					a[i] = a[j];
					a[j] = prop;
				}
			}
		}
	}
void MyClass::sortAlphabet()
{
	TALK prop;
	int choice;
	do
	{
		cout << "1. Сортировка А-Я\n" "2. Сортировка Я-А\n" "0. Отмена действия\n"; cin >> choice;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(32767, '\n');
			cout << "Неверный ввод. Введите 1 или 2." << endl;
		}
		else if (choice == 1)
		{
			sort(fioUp);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 2)
		{
			sort(fioDown);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 0)
		{
			cout << "Отмена действия. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else
		{
			cout << "Неверный ввод. Введите 1 или 2." << endl;
		}
	} while (true);
}
void MyClass::sortTime()
{
	TALK prop;
	int choice;
	do
	{
		cout << "1. Сортировка возрастающая \n" "2. Сортировка убывающая \n" "0. Отмена действия\n"; cin >> choice;
		if (cin.fail())
		{
			cout << "Неверный ввод. Введите 1 или 2." << endl;
			cin.clear(); cin.ignore(32767, '\n');
		}
		else if (choice == 1)
		{
			sort(timeUp);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 2)
		{
			sort(timeDown);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 0)
		{
			cout << "Отмена действия. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else
		{
			cout << "Неверный ввод. Введите 1 или 2." << endl;
		}
	} while (true);
}
void MyClass::sortDate()
{
	TALK prop;
	int choice;
	do
	{
		cout << "1. Сортировка убывающая \n" "2. Сортировка возрастающая \n" "0. Отмена действия \n"; cin >> choice;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(32767, '\n');
			cout << "Неверный ввод. Введите 1 или 2." << endl;
		}
		else if (choice == 1)
		{
			sort(dateDown);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 2)
		{
			sort(dateUp);
			getTable();
			cout << "Успешно. Нажмите enter, чтобы продолжить...";
			_getch();
			break;
		}
		else if (choice == 0)
		{
			cout << "Отмена действия. Нажмите enter, чтобы продолжить..." << endl;
			_getch();
			break;
		}
		else
		{
			cout << "Неверный ввод. Введите 1 или 2." << endl;
		}
	} while (true);
}
void MyClass::clearMassive()
{
	string choice;
	bool confirmed = false;
	if (a != nullptr)
	{
		cout << "Очищение массива, вы уверены? (y/n): ";
		do
		{
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				confirmed = true;
				break;
			}
			else if (choice == "n" || choice == "N")
			{
				cout << "Отмена очищения массива. Нажите enter, чтобы продолжить...";
				_getch();
				break;
			}
			else
			{
				cout << "Неверный ввод. Введите 'y' либо 'n'." << endl;
			}
		} while (true);
		if (confirmed)
		{
			TALK* newArr = new TALK[0];
			delete[] a;
			a = newArr;
			n = 0;
			cout << "Массив очищен. Нажите enter, чтобы продолжить...";
			_getch();
		}
	}
	else
	{
		cout << "Массив пустой. Нажите enter, чтобы продолжить...";
		_getch();
	}
}
ofstream& operator<<(ofstream& file, MyClass& ffile)
{
	file << "________________________________________________________________________________________________________________\n"
		"|    |                     |               |                |                 |              |                 |\n"
		"|  N |        ФИО          |     Номер     | Дата разговора | Тариф за минуту | Время начала | Время окончания |\n"
		"|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	for (int i = 0; i < ffile.n; i++)
		file << "| " << setw(2) << i + 1 << " | " << setw(19) << ffile.a[i].data.fio << " | " << setw(13) << ffile.a[i].data.number << " | " << setw(6) << ffile.a[i].dateDay << "." << setw(2) << ffile.a[i].dateMonth << "." << setw(4) << ffile.a[i].dateYear << " | " << setw(15) << ffile.a[i].money << " | " << setw(9) << ffile.a[i].startTimeHours << ":" << setw(2) << ffile.a[i].startTimeMinutes << " | " << setw(12) << ffile.a[i].stopTimeHours << ":" << setw(2) << ffile.a[i].stopTimeMinutes << " |" << endl;
	file << "|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	return file;
}
ifstream& operator>>(ifstream& ifile, MyClass& ffile)
{
	cout << "Введите название файла: "; cin >> ofilename;
	ifstream file(ofilename);
	ffile.n = 0;
	if (!file.is_open())
	{
		cout << "Файл не найден." << endl;
	}
	else
	{
		if (ffile.a != nullptr)
		{
			delete[] ffile.a;
			ffile.a = nullptr;
			ffile.n = 0;
		}
		string line;
		while (getline(file, line))
		{
			string init; // инициалы
			TALK prop;
			char symbol;
			stringstream x(line);
			x >> prop.data.fio >> init >> prop.data.number >> prop.dateDay >> symbol >> prop.dateMonth >> symbol >> prop.dateYear >> prop.money >> prop.startTimeHours >> symbol >> prop.startTimeMinutes >> prop.stopTimeHours >> symbol >> prop.stopTimeMinutes;
			prop.data.fio = prop.data.fio + " " + init;

			//Добавление в динамический массив
			TALK* newArr = new TALK[ffile.n + 1];
			for (int i = 0; i < ffile.n; i++)
			{
				newArr[i] = ffile.a[i];
			}
			if (ffile.a != nullptr)
			{
				delete[] ffile.a;
			}
			ffile.a = newArr;
			ffile.a[ffile.n] = prop;
			ffile.n++;
		}
		cout << "Успешно. Нажмите enter, чтобы продолжить..." << endl;
	}
	file.close();
	return ifile;
}
