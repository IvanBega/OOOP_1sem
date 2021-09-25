#pragma once
#include <iostream>
#include <iomanip>
class Date
{
public:
	Date(unsigned short _year, unsigned short _month, unsigned short _day,
		unsigned short _hour, unsigned short _minute, unsigned short _second) :
		year(_year), month(_month), day(_day), hour(_hour), minute(_minute), second(_second)
	{

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
			corrected_year = year % 100;
		}
		else
		{
			corrected_month = month + 10;
			corrected_year = year % 100 - 1;
			if (corrected_year < 0)
				corrected_year = 99;
		}

		double d1 = 2.6 * corrected_month - 0.2;
		double d1_floor;
		int century = year / 100;
		std::modf(d1, &d1_floor);
		int result = day + ((13 * corrected_month - 1) / 5) + corrected_year + corrected_year / 4 + century / 4 - 2 * century;
		return (result - 1) % 7;
	}
	long long dateToSec()
	{
		long long sec = 0;
		sec = static_cast<int64_t>(year) * sec_in_year + (static_cast<int64_t>(day) - 1) * sec_in_day; // years + days

		sec += static_cast<int64_t>(year / 4) * sec_in_day; // leap days

		for (int i = 0; i < month; i++)
		{
			sec += days_in_month[i] * static_cast<int64_t>(sec_in_day); // month
		}
		if (year % 4 == 0 && month < 3)
		{
			sec -= sec_in_day;
		}

		sec += hour * 3600 + minute * 60 + sec;
		return (long long) sec;
	}
	int dateToDays()
	{
		int days = 0;
		days += year * 365 + day; // years + days
		days += year / 4; // leap days

		for (int i = 0; i < month; i++)
		{
			days += days_in_month[i];
		}
		if (year % 4 == 0 && month < 3 && days != 29)
		{
			days -= 1;
		}
		return days;
	}

private:
	Date dateFromSec(long long sec)
	{
		Date temp(0,0,0,0,0,0);
	}
	const unsigned short int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,  30, 31 };
	const int sec_in_year = 31536000;
	const int sec_in_day = 86400;
	short year = 0;
	short day = 1;
	short month = 1;
	short hour = 0;
	short minute = 0;
	short second = 0;
};


