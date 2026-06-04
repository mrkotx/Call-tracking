#include <iomanip>
#include <sstream>
#include <fstream>
#include <windows.h>

#include "Operators.h"
#include "MyClass.h"
#include "MassA.h"
#include "MassB.h"

using namespace std;

ostream& operator<<(ostream& op, const TALK& a)
{
	op << " | " << setw(19) << a.data.fio << " | " << setw(13) << a.data.number << " | " << setw(6) << a.dateDay << "." << setw(2) << a.dateMonth << "." << setw(4) << a.dateYear << " | " << setw(15) << a.money << " | " << setw(9) << a.startTimeHours << ":" << setw(2) << a.startTimeMinutes << " | " << setw(12) << a.stopTimeHours << ":" << setw(2) << a.stopTimeMinutes << " |" << endl;
	return op;
}
stringstream& operator>>(stringstream& inp, TALK& a)
{
	string init;
	inp >> a.data.fio >> init >> a.data.number >> a.dateDay >> a.dateMonth >> a.dateYear >> a.money >> a.startTimeHours >> a.startTimeMinutes >> a.stopTimeHours >> a.stopTimeMinutes;
	return inp;
}
istream& operator>>(istream& is, TALK& a)
{
	string init;
	string name;
	int dotCount = 0;
	//ФИО
	while (init.length() != 4 || dotCount != 2)
	{
		cout << "Введите фамилию и инициалы (Иванов И.И. / Иванов ИИ): "; is >> a.data.fio >> init;
		for (int i = 0; i < init.length(); i++)
		{
			if (init[i] == '.')
			{
				dotCount += 1;
			}
		}
		if (init.length() == 2)
		{
			stringstream ss;
			ss << init[0] << '.' << init[1] << '.';
			init = ss.str();
			dotCount = 2;
		}
	}
	a.data.fio = a.data.fio + " " + init;

	//Номер
	cout << "Введите номер: "; is >> a.data.number;
	if (a.data.number[0] != '+')
		a.data.number = '+' + a.data.number;

	while (a.data.number.length() != 12)
	{
		cout << "Номер должен содержать 12 символов, считая '+' " << endl;
		cout << "Введите номер: "; is >> a.data.number;
		if (a.data.number[0] != '+')
			a.data.number = '+' + a.data.number;
	}
	//Дата
	cout << "Введите дату разговора (31 12 2026): "; is >> a.dateDay >> a.dateMonth >> a.dateYear;
	while (is.fail() || (a.dateDay < 1) || (a.dateDay > 31) || (a.dateMonth < 1) || (a.dateMonth > 12) || (a.dateYear < 1900) || (a.dateYear > 2026))
	{
		cout << "Вы ввели некорректную дату." << endl; is.clear(); is.ignore(32767, '\n');
		cout << "Введите дату разговора (31 12 2026): "; is >> a.dateDay >> a.dateMonth >> a.dateYear;
	}
	//Тариф
	cout << "Введите тариф за минуту разговора: "; is >> a.money;
	while (is.fail() || a.money < 0)
	{
		cout << "Вы ввели некорректные данные." << endl; is.clear(); is.ignore(32767, '\n');
		cout << "Введите тариф за минуту разговора: "; is >> a.money;
	}
	//Время начала
	cout << "Введите время начала разговора (23:59): "; is >> a.startTimeHours >> a.startTimeMinutes;
	while (is.fail() || (a.startTimeHours < 0) || (a.startTimeHours > 23) || (a.startTimeMinutes < 0) || (a.startTimeMinutes > 59))
	{
		cout << "Вы ввели некорректные данные." << endl; is.clear(); is.ignore(32767, '\n');
		cout << "Введите время начала разговора (23:59): "; is >> a.startTimeHours >> a.startTimeMinutes;
	}
	//Время конца
	cout << "Введите время конца разговора (23:59): "; is >> a.stopTimeHours >> a.stopTimeMinutes;
	while (is.fail() || (a.stopTimeHours < 0) || (a.stopTimeHours > 23) || (a.stopTimeMinutes < 0) || (a.stopTimeMinutes > 59))
	{
		cout << "Вы ввели некорректные данные." << endl; is.clear(); is.ignore(32767, '\n');
		cout << "Введите время конца разговора (23:59): "; is >> a.stopTimeHours >> a.stopTimeMinutes;
	}
	return is;
}

ostream& operator<<(ostream& op, MassA& af)
{
	op << "________________________________________________________________________________________________________________\n"
		"|    |                     |               |                |                 |              |                 |\n"
		"|  N |        ФИО          |     Номер     | Дата разговора | Тариф за минуту | Время начала | Время окончания |\n"
		"|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	for (int i = 0; i < af.k; i++)
		op << "| " << setw(2) << i + 1 << " | " << setw(19) << af.c[i].data.fio << " | " << setw(13) << af.c[i].data.number << " | " << setw(6) << af.c[i].dateDay << "." << setw(2) << af.c[i].dateMonth << "." << setw(4) << af.c[i].dateYear << " | " << setw(15) << af.c[i].money << " | " << setw(9) << af.c[i].startTimeHours << ":" << setw(2) << af.c[i].startTimeMinutes << " | " << setw(12) << af.c[i].stopTimeHours << ":" << setw(2) << af.c[i].stopTimeMinutes << " |" << endl;
	op << "|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	return op;
}
ostream& operator<<(ostream& op, MassB& bf)
{
	op << "_________________________________________________________________\n"
		"|    |                     |               |                    |\n"
		"|  N |        ФИО          |     Номер     | Количество звонков |\n"
		"|____|_____________________|_______________|____________________|" << endl;
	for (int i = 0; i < bf.k; i++)
		op << "| " << setw(2) << i + 1 << " | " << setw(19) << bf.b[i].data.fio << " | " << setw(13) << bf.b[i].data.number << " | " << setw(18) << bf.b[i].callCount << " |" << endl;
	op << "|____|_____________________|_______________|____________________|" << endl;
	return op;
}
ostream& operator<<(ostream& op, MyClass& f)
{
	op << "________________________________________________________________________________________________________________\n"
		"|    |                     |               |                |                 |              |                 |\n"
		"|  N |        ФИО          |     Номер     | Дата разговора | Тариф за минуту | Время начала | Время окончания |\n"
		"|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	for (int i = 0; i < f.n; i++)
		op << "| " << setw(2) << i + 1 << f.a[i];
	op << "|____|_____________________|_______________|________________|_________________|______________|_________________|" << endl;
	return op;
}