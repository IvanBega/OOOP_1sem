#pragma once
#include <iostream>
#include <iomanip>
class Date
{
public:
	Date(unsigned short _year, unsigned short _month, unsigned short _day,
		unsigned short _hour, unsigned short _minute, unsigned short _second)
	{
		year = _year; month = _month; day = _day; hour = _hour; minute = _minute; second = _second;
	}
	Date()
	{

	}
	void print()
	{
		using namespace std;
		cout << year << " " << setfill('0') << setw(2) << month << " " << setfill('0') << setw(2) << day << " "
			<< setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;
	}
	bool isCorrect()
	{
		if ((year >= 0) && (month == 2) && (year % 4 == 0) && (day <= 29))
			return true;
		if (year < 0 || month > 12 || day > days_in_month[month - 1])
			return false;
		if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
			return false;
		return true;
	}

private:
	const unsigned short int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,  30, 31 };
	unsigned short int year = 0;
	unsigned short int day = 1;
	unsigned short int month = 1;
	unsigned short int hour = 0;
	unsigned short int minute = 0;
	unsigned short int second = 0;
};


