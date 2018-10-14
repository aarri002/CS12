#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    bool invalidDate = false;
    
    if (m > 0)
    {
        if(m <= 12)
        {
            month = m;
            monthName = name(m);
        }
        else
        {
            month = 12;
            m = 12;
            monthName = name(12);
            invalidDate = true;
        }
    }
    else
    {
        month = 1;
        m = 1;
        monthName = name(1);
        invalidDate = true;
    }
    
    if (d > 0)
    {
        if(d <= daysPerMonth(m, y))
        {
            day = d;
        }
        else
        {
            day = daysPerMonth(m, y);
            invalidDate = true;
        }
    }
    else
    {
        day = 1;
        invalidDate = true;
    }
    
    
    if(y > 0)
    {
        year = y;
    }
    else
    {
        year = 0;
        invalidDate = true;
    }
    if (invalidDate)
    {
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
    }
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
    bool invalidDate = false;
    
    if (number(mn) != 0)
    {
        monthName = mn;
        month = number(mn);
    }
    else
    {
        month = 1;
        monthName = name(1);
        invalidDate = true;
    }
    
    if (d > 0)
    {
        if(d <= daysPerMonth(number(monthName), y))
        {
            day = d;
        }
        else
        {
            day = daysPerMonth(number(monthName), y);
            invalidDate = true;
        }
    }
    else
    {
        day = 1;
        invalidDate = true;
    }
    

    
    if(y > 0)
    {
        year = y;
    }
    else
    {
        year = 0;
        invalidDate = true;
    }
    if (invalidDate)
    {
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
    }
}

void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned year) const
{
    bool isLeapYear =  false;
    
    if(year%4 == 0)
    {
        isLeapYear = true;
    }
    if(year%100 == 0)
    {
        isLeapYear = false;
    }
    if(year%400 == 0)
    {
        isLeapYear = true;
    }
    return isLeapYear;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    switch(m)
    {
        case 1:
                return 31;
        case 2:
                if (!(isLeap(y)))
                {
                    return 28;
                }
                else
                {
                    return 29;
                }
        case 3:
                return 31;
        case 4:
                return 30;
        case 5:
                return 31;
        case 6:
                return 30;
        case 7:
                return 31;
        case 8:
                return 31;
        case 9:
                return 30;
        case 10:
                return 31;
        case 11:
                return 30;
        case 12:
                return 31;
    }
    return 0;
}

string Date::name(unsigned m) const
{
    switch(m)
    {
        case 1:
                return "January";
        case 2:
                return "February";
        case 3:
                return "March";
        case 4:
                return "April";
        case 5:
                return "May";
        case 6:
                return "June";
        case 7:
                return "July";
        case 8:
                return "August";
        case 9:
                return "September";
        case 10:
                return "October";
        case 11:
                return "November";
        case 12:
                return "December";
    }
    return "0";
}

unsigned Date::number(const string &mn) const
{
    if (mn == "January" || mn == "january")
    {
        return 1;
    }
    else if (mn == "February" || mn == "february")
    {
        return 2;
    }
    else if (mn == "March" || mn == "march")
    {
        return 3;
    }else if (mn == "April" || mn == "april")
    {
        return 4;
    }
    else if (mn == "May" || mn == "may")
    {
        return 5;
    }
    else if (mn == "June" || mn == "june")
    {
        return 6;
    }
    else if (mn == "July" || mn == "july")
    {
        return 7;
    }
    else if (mn == "August" || mn == "august")
    {
        return 8;
    }
    else if (mn == "September" || mn == "september")
    {
        return 9;
    }
    else if (mn == "October" || mn == "october")
    {
        return 10;
    }
    else if (mn == "November" || mn == "november")
    {
        return 11;
    }
    else if (mn == "December" || mn == "december")
    {
        return 12;
    }
    else
    {
        return 0;
    }
}
























