#include "date.h"

Date::Date(u_int d, u_int m, u_int y, u_int s):day(d > getMaxDayForMonth() ? 1 : d),
    month(m > 12? 1 : m),
    year(y != 2021? 2021 : y),
    start(s > 23? 9 : s){}

void Date::setDay(u_int day)
{
    if(day > getMaxDayForMonth())
        throw std::logic_error("giorno non presente nel mese");
    this->day = day;
}

void Date::setMonth(u_int month)
{
    if(month > 12)
        throw std::logic_error("mese non esistente");
    this->month = month;
}

void Date::setYear(u_int year)
{
    if(year != 2021)
        throw std::logic_error("gli eventi sono riguardanti unicamente il 2021");
    this->year = year;
}

void Date::setStart(u_int start)
{
    if(start > 23)
        throw std::logic_error("orario non esitente");
    this->start = start;
}

u_int Date::getDay() const
{
    return day;
}

u_int Date::getMonth() const
{
    return month;
}

u_int Date::getYear() const
{
    return year;
}

u_int Date::getStart() const
{
    return start;
}

u_int Date::getMaxDayForMonth() const
{
    switch (month) {
    case 4:
        return 30;
    case 6:
        return 30;
    case 9:
        return 30;
    case 11:
        return 30;
    case 2:
        return 28;
    default:
        return 31;
    }
}

bool Date::operator<(const Date &d) const
{
    if(getMonth() < d.getMonth())
        return true;
    if(getMonth() == d.getMonth()){//stesso mese
        if(getDay() < d.getDay())
            return true;
        if(getDay() == d.getDay())//stesso giorno
            return getStart() < d.getStart();
        else
            return false;
    }
    else
        return false;
}

bool Date::operator>(const Date &d) const
{
    if(getMonth() > d.getMonth())
        return true;
    if(getMonth() == d.getMonth()){//stesso mese
        if(getDay() > d.getDay())
            return true;
        if(getDay() == d.getDay())//stesso giorno
            return getStart() > d.getStart();
        else
            return false;
    }
    else
        return false;
}

bool Date::operator==(const Date &d) const
{
    return getDay() == d.getDay() && getMonth() == d.getMonth() && getStart() == d.getStart();
}

std::string Date::toString() const
{
    return std::to_string(getDay()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getYear()) + ", all'orario " + std::to_string(getStart()) + ":00";
}

