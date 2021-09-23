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
	int getDayByDate()
	{
		int corrected_month;
		int corrected_year;
		if (month >= 3 && month <= 12)
		{
			corrected_month = month - 2;
			corrected_year = year / 100;
		}
		else
		{
			corrected_month = month + 10;
			corrected_year = year / 100 - 1;
		}

		double d1 = 2.6 * corrected_month - 0.2;
		double d1_floor;
		std::modf(d1, &d1_floor);
		int century = year / 100;
		int result = day + d1_floor - 2 * century + corrected_year + corrected_year / 4 + century / 4;
		return result % 7;
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


