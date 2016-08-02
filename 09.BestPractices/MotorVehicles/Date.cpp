#include "Date.h"

Date::Date(unsigned int dateYear, unsigned short dateMonth, unsigned short dateDay)
{
    this->setYear(dateYear);
    this->setMonth(dateMonth);
    this->setDay(dateDay);
}

void Date::setYear(unsigned int newYear)
{
    this->year = newYear;
}

void Date::setMonth(unsigned short newMonth)
{
    if (1 <= newMonth && newMonth <= 12)
    {
        this->month = newMonth;
    }
    else
    {
        throw "Month should be between 0 and 12.";
    }
}

void Date::setDay(unsigned short newDay)
{
    switch (this->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (newDay > 31)
        {
            throw "Day should be less than 32";
        }

        this->day = newDay;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (newDay > 30)
        {
            throw "Day should be less than 31";
        }

        this->day = newDay;
        break;
    case 2:
        // only non-leap years are supported
        if (newDay > 28)
        {
            throw "Day should be less than 29";
        }

        this->day = newDay;
        break;
    default:
        throw "Unsupported month!";
    }
}

Date::Date()
{
}

Date::Date(Date & date)
{
    this->setYear(date.year);
    this->setMonth(date.month);
    this->setDay(date.day);
}

Date::~Date()
{
}

std::string Date::toString()
{
    std::stringstream ss;
    char buffer[100];
    std::sprintf(buffer, "%02d.%02d.%04d", this->day, this->month, this->year);

    ss << buffer;
    return ss.str();
}
