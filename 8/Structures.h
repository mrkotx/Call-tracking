#pragma once
#include <string>
using namespace std;
struct MOBILE
{
	string fio;
	string number;

};
struct TALK
{
	MOBILE data;

	int dateDay;
	int dateMonth;
	int dateYear;

	int callCount = 1;

	int money;

	int startTimeHours;
	int startTimeMinutes;

	int stopTimeHours;
	int stopTimeMinutes;

	// Время разговора
	int duration() const;
	// Сортировка по дате
	bool operator>(const TALK& other) const;
	bool operator<(const TALK& other) const;
};