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
	unsigned toSeconds()
	{
		if (year < 2001)
			year += 2001;

		int sec = 0;
		sec += (year - 2001) * sec_in_year; // years to seconds
		sec += (year - 2001) / 4 * sec_in_day; // leap days to seconds
		for (int i = 0; i < month - 1; i++)
		{
			sec += days_in_month[i] * sec_in_day; // month to sec
		}
		sec += day * sec_in_day;
		sec += hour * 3600 + minute * 60 + second;

		if (year % 4 == 0 && month < 3)
		{
			sec -= sec_in_day;
		}
		return sec;
	}
	static Date secondsToDate(unsigned sec)
	{
		Date temp(0,0, 0,0,0,0);
		temp.year += (sec / (sec_in_year + 0.25 * sec_in_day));
		sec -= temp.year * sec_in_year + sec_in_day * (temp.year) / 4;
		int i = 0;
		while (sec >= days_in_month[i] * sec_in_day)
		{
			if (i == 1 && temp.year % 4 == 0)
			{
				if (sec >= 29 * sec_in_day)
				{
					sec -= 29 * sec_in_day;
				}
				else
					break;
			}
			else
			{
				sec -= days_in_month[i] * sec_in_day;
			}
			temp.month++;
			i++;
		}
		temp.day += (sec / sec_in_day);
		sec -= (temp.day) * sec_in_day;
		temp.hour = sec / 3600;
		sec -= temp.hour * 3600;
		temp.minute = sec / 60;
		sec -= temp.minute * 60;
		temp.second = sec;
		return temp;
	}
	static Date dateDiff(Date date1, Date date2)
	{
		return Date::secondsToDate(date2.toSeconds() - date1.toSeconds());
	}
	static void addDate(Date source, Date& dest)
	{
		int sec = source.toSeconds() + dest.toSeconds();
		dest = secondsToDate(sec);
	}
	/*void add(short Year, short Month, short Day)
	{
		int days = Date::toDays(Year, Month, Day);
		while (days >= 365)
		{
			if (year % 4 == 3 && days >= 366)
			{
				days -= 366;
			}
			else
			{
				days -= 365;
			}
			year += 1;
		}
		while (days >= days_in_month[month - 1])
		{
			if (year % 4 == 0 && month == 2 && days >= 29)
			{
				days -= 29;
			}
			else
			{
				days -= days_in_month[month - 1];
			}
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
		if (days > days_in_month[month - 1] - day)
		{
			if (year % 4 == 0 && month == 2)
			{
				if (days > 29 - day)
				{

				}
			}
		}
	}*/
	void addDate(short Year, short Month, short Day)
	{
		if (day + Day > days_in_month[month - 1])
		{
			if (Year % 4 == 0 && month == 2 && (day + Day == 29))
			{
				day += Day;
			}
			else
			{
				day += Day - days_in_month[month - 1];
				Month++;
			}
		}
		else
		{
			day += Day;
		}
		
		if (month + Month > 12)
		{
			month = (month + Month) % 12;
			Year++;
		}
		else
		{
			month += Month;
		}

		year += Year;
	}
	static int toDays(short Year, short Month, short Day)
	{
		int days = 0;
		days += Year * 365 + Day; // years + days
		days += Year / 4; // leap days

		for (int i = 0; i < Month - 1; i++)
		{
			days += days_in_month[i];
		}
		if (Year % 4 == 3 && ((Month == 2 && Day == 29) || Month >= 3))
		{
			days += 1;
		}
		return days;
	}
private:
	static constexpr const unsigned short int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const int sec_in_year = 31536000;
	static const int sec_in_day = 86400;
	short year = 0;
	short day = 1;
	short month = 1;
	short hour = 0;
	short minute = 0;
	short second = 0;
	/*static Date dateFromDays(int days)
	{
		unsigned short int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,  30, 31 };
		Date temp(0, 0, 0, 0, 0, 0);
		temp.year = (days / 365.25);
		days -= temp.year * 365 + (temp.year - 1) / 4;
		if (temp.year % 4 == 0)
			days_in_month[1] = 29;

		int i = 0;
		while (days > days_in_month[i])
		{
			temp.month++;
			days -= days_in_month[i];
			i++;
		}
		temp.day = days;
		return temp;
	}*/
};


