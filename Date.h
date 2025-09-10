#ifndef DATE_H
#define DATE_H
#include "String.h"
class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	bool isLeapYear(int year) const;
	bool isValidDate(int d, int m, int y) const;
	bool isValidDate() const;
	String getMonthName(int m)const;
	int getDaysOfMonth(int m, int y) const;
public:
	Date();
	Date(int d, int m, int y);
	void setDate(int d, int m, int y);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printFormat1();
	void printFormat2();
	void printFormat3();
	void incDay(int d = 1);
	void incMonth(int m = 1);
	void incYear(int y = 1);
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
};
#endif