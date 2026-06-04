#include <string>
#include "SortVar.h"

using namespace std;

bool fioUp(const TALK& a, const TALK& b)
{
	return a.data.fio < b.data.fio;
}
bool fioDown(const TALK& a, const TALK& b)
{
	return a.data.fio > b.data.fio;
}

bool timeUp(const TALK& a, const TALK& b)
{
	return a.duration() < b.duration();
}
bool timeDown(const TALK& a, const TALK& b)
{
	return a.duration() > b.duration();
}

bool dateUp(const TALK& a, const TALK& b)
{
	return a < b;
}
bool dateDown(const TALK& a, const TALK& b)
{
	return a > b;
}

bool callUp(const TALK& a, const TALK& b)
{
	return a.callCount < b.callCount;
}
bool callDown(const TALK& a, const TALK& b)
{
	return a.callCount > b.callCount;
}

bool numUp(const TALK& a, const TALK& b)
{
	long long a1 = stoll(a.data.number.substr(1));
	long long a2 = stoll(b.data.number.substr(1));
	return a1 < a2;
}
bool numDown(const TALK& a, const TALK& b)
{
	long long a1 = stoll(a.data.number.substr(1));
	long long a2 = stoll(b.data.number.substr(1));
	return a1 > a2;
}