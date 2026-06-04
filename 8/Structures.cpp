#include "Structures.h"

int TALK::duration() const
{
    return (stopTimeHours * 60 + stopTimeMinutes) - (startTimeHours * 60 + startTimeMinutes);
}

bool TALK::operator>(const TALK& other) const
{
    if (dateYear != other.dateYear)
        return dateYear > other.dateYear;
    if (dateMonth != other.dateMonth)
        return dateMonth > other.dateMonth;
    if (dateDay != other.dateDay)
        return dateDay > other.dateDay;
    return duration() > other.duration();
}

bool TALK::operator<(const TALK& other) const
{
    return other > *this;
}