#include"Date.h"
#include"String.h"
#include<iostream>
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date()
{
	day = 1;
	month = 1;
	year = 1501;
}
Date::Date(int d, int m, int y) :Date()
{
	if (isValidDate(d, m, y))
	{
		day = d;
		month = m;
		year = y;
	}
}
void Date::setDate(int d, int m, int y)
{
	if (isValidDate(d, m, y))
	{
		setDay(d);
		setMonth(m);
		setYear(y);
	}
}
void Date::setDay(int d)
{
	if (d >= 1 && d < daysInMonth[month])
		day = d;
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
}
void Date::setYear(int y)
{
	if (y >= 1500 && y < 3000)
		year = y;
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::printFormat1()
{
	getDateInFormat1().display();
}
void Date::printFormat2()
{
	getDateInFormat1().display();
}
void Date::printFormat3()
{
	getDateInFormat1().display();
}
void Date::incDay(int d)
{
	day = day + d;
	if (day > getDaysOfMonth(month, year))
	{
		day = day - getDaysOfMonth(month, year);
		incMonth();
	}
	if (month > 12)
	{
		setMonth(month % 12 + 1);
	}
}
void Date::incMonth(int m)
{
	month = month + m;
	if (month > 12)
	{
		incYear(month / 12);
		month = ((month - 1) % 12 + 1);
	}
}
void Date::incYear(int y)
{
	year = year + y;
}
String Date::getDateInFormat1() const
{
	String date1, temp;
	date1.setNumber(day);
	date1.concatEqual("/");
	temp.setNumber(month);
	date1.concatEqual(temp);
	date1.concatEqual("/");
	temp.setNumber(year);
	date1.concatEqual(temp);
	return date1;
}

String Date::getDateInFormat2() const
{
	String date2, temp;
	String  months[12] = { "January", "February", "March", "April", "May","June", "July",			"August","September","October","November","December" };
	date2.concatEqual(months[month - 1]);
	date2.concatEqual(" ");
	temp.setNumber(day);
	date2.concatEqual(temp);
	date2.concatEqual(", ");
	temp.setNumber(year);
	date2.concatEqual(temp);
	return date2;
}
String Date::getDateInFormat3() const
{
	String date3, temp;
	date3.setNumber(day);
	date3.concatEqual("-");
	String months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
	date3.concatEqual(months[month - 1]);
	date3.concatEqual("-");
	temp.setNumber(year);
	date3.concatEqual(temp);
	return date3;
}
bool Date::isLeapYear(int y) const
{
	if (y % 4 == 0 && y % 100 != 0)
	{
		return true;
	}
	else if (y % 100 == 0 && y % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::isValidDate(int d, int m, int y) const
{
	if (d > 0 && d <= getDaysOfMonth(m, y) && m >= 1 && m <= 12 && y >= 1500 && y <= 3000)
	{
		return true;
	}
	return false;
}
bool Date::isValidDate() const
{
	return isValidDate(day, month, year);
}
String Date::getMonthName(int m) const
{
	if (m > 12 || m <= 0)
		exit(0);
	const char* months[12] = { "January", "February", "March", "April", "May","June", "July",			"August","September","October","November","December" };

	return months[m - 1];
}
int Date::getDaysOfMonth(int m, int y) const
{
	if (isLeapYear(y) && m == 2)
	{
		return 29;
	}
	return daysInMonth[m];
}