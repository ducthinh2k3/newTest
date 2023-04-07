#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date();
    ~Date();
    void Input();
    void Output();
    Date &increaseOneDay();
    Date &increaseNDays(int n);
    Date &decreaseOneDay();
    Date &decreaseNDays(int n);
    int compare(Date d);
};

bool isNamNhuan(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
            (year % 400 == 0));
}

Date::Date()
{
    day = month = year = 1;
}

Date::~Date()
{
    day = month = year = 0;
}

int maxDayOfMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (isNamNhuan(year))
            return 29;
        else
            return 28;
        break;
    default:
        return 0;
    }
}

void Date::Input()
{
    do
    {
        cout << "Input day: ";
        cin >> day;
        do
        {
            cout << "Input month: ";
            cin >> month;
        } while (month < 1 || month > 12);

        do
        {
            cout << "Input year: ";
            cin >> year;
        } while (year < 1);

    } while (day > maxDayOfMonth(month, year) || day < 1);
}

void Date::Output()
{
    string strDay = to_string(day);
    strDay = string(2 - strDay.size(), '0') + strDay;

    string strMonth = to_string(month);
    strMonth = string(2 - strMonth.size(), '0') + strMonth;

    string strYear = to_string(year);
    strYear = string(4 - strYear.size(), '0') + strYear;

    cout << strDay << "/" << strMonth << "/" << strYear << endl;
}

// Date &Date::increaseOneDay()
// {
//     switch (month)
//     {
//     case 1:
//     case 3:
//     case 5:
//     case 7:
//     case 8:
//     case 10:
//     case 12:
//         if (day != 31)
//         {
//             day += 1;
//         }
//         else
//         {
//             if (month != 12)
//             {
//                 day = 1;
//                 month += 1;
//             }
//             else
//             {
//                 day = 1;
//                 month = 1;
//                 year += 1;
//             }
//         }
//         break;
//     case 4:
//     case 6:
//     case 9:
//     case 11:
//         if (day != 30)
//         {
//             day += 1;
//         }
//         else
//         {
//             day = 1;
//             month += 1;
//         }
//         break;
//     case 2:
//         if (isNamNhuan(year))
//         {
//             if (day != 28)
//             {
//                 day += 1;
//             }
//             else
//             {
//                 day = 1;
//                 month += 1;
//             }
//         }
//         else
//         {
//             if (day != 29)
//             {
//                 day += 1;
//             }
//             else
//             {
//                 day = 1;
//                 month += 1;
//             }
//         }
//         break;
//     }
//     return *this;
// }

Date &Date::increaseOneDay()
{
    if (day < maxDayOfMonth(month, year))
    {
        day += 1;
    }
    else
    {
        if (month != 12)
        {
            day = 1;
            month += 1;
        }
        else
        {
            day = month = 1;
            year += 1;
        }
    }
    return *this;
}

Date &Date::increaseNDays(int n)
{
    day = day + n;
    while (day > maxDayOfMonth(month, year))
    {
        day = day - maxDayOfMonth(month, year);
        if (month != 12)
        {
            month += 1;
        }
        else
        {
            month = 1;
            year += 1;
        }
    }
    return *this;
}

Date &Date::decreaseOneDay()
{
    if (day != 1)
    {
        day = day - 1;
    }
    else
    {
        if (month != 1)
        {
            month -= 1;
            day = maxDayOfMonth(month, year);
        }
        else
        {
            month = 12;
            year -= 1;
            day = maxDayOfMonth(month, year);
        }
    }
    return *this;
}

Date &Date::decreaseNDays(int n)
{
    day = day - n;
    while (day <= 0)
    {
        if (month != 1)
        {
            month -= 1;
        }
        else
        {
            month = 12;
            year -= 1;
        }
        day = day + maxDayOfMonth(month, year);
    }
    return *this;
}

int Date::compare(Date d)
{
    int num1 = this->day + this->month * 100 + this->year * 10000;
    int num2 = d.day + d.month * 100 + d.year * 10000;
    cout << num1 << "-" << num2 << endl;
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

int main()
{
    Date d;
    Date s;
    s.Input();
    d.Input();
    cout << d.compare(s);
}