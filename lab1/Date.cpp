#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
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
		std::string days_of_week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
		int day_of_week = getDayByDate();
		cout << days_of_week[day_of_week] << ", ";
		/*cout << year << " " << setfill('0') << setw(2) << month << " " << setfill('0') << setw(2) << day << " "
			<< setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;*/
		cout << setfill('0') << setw(2) << day << " " << setfill('0') << setw(2) << month << " " << year << " "
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
		// 0 - Monday, ..., 6 - Sunday
		int corrected_month;
		int corrected_year = year;
		if (month < 3)
		{
			corrected_year = year - 1;
			corrected_month = 10 + month;
		}
		else
		{
			corrected_month = month - 2;
		}
		return (day + 31 * corrected_month / 12 + corrected_year + corrected_year / 4 - corrected_year / 100 + corrected_year / 400 - 1) % 7;
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
		date1.subtractDate(date2.year, date2.month, date2.day);
		return date1;
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
	void addDate(Date date)
	{
		addDate(date.year, date.month, date.day, date.hour, date.minute, date.second);
	}
	void addDate(short Year, short Month, short Day)
	{
		if (day + Day > days_in_month[month - 1])
		{
			if (year % 4 == 0 && month == 2 && (day + Day == 29))
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
	void addDate(short Year, short Month, short Day, short Hour, short Minute, short Second)
	{
		addDate(Year, Month, Day);
		int time = Hour * 3600 + Minute * 60 + Second + hour * 3600 + minute * 60 + second;
		if (time >= sec_in_day)
		{
			addDate(0, 0, 1);
			time = time % sec_in_day;
		}
		hour = time / 3600;
		time = time - 3600 * hour;
		minute = time / 60;
		time = time - 60 * minute;
		second = time;
	}
	void subtractDate(short Year, short Month, short Day)
	{
		if (day - Day <= 0)
		{
			if (year % 4 == 0 && month == 3)
			{
				day = 29 - (Day - day);
				month -= 1;
			}
			else
			{
				if (month == 1)
				{
					month = 12;
					Year += 1;
				}
				else
				{
					month -= 1;
				}
				day = days_in_month[month - 1] - (Day - day);
			}
		}
		else
		{
			day -= Day;
		}

		if (month - Month <= 0)
		{
			month = 12 - (Month - month);
			Year += 1;
		}
		else
		{
			month -= Month;
		}

		year -= Year;
	}
	void subtractDate(short Year, short Month, short Day, short Hour, short Minute, short Second)
	{
		subtractDate(Year, Month, Day);
		int time = (hour * 3600 + minute * 60 + second) - (Hour * 3600 + Minute * 60 + Second);
		if (time < 0)
		{
			subtractDate(0, 0, 1);
			time = sec_in_day + time;
		}
		hour = time / 3600;
		time = time - 3600 * hour;
		minute = time / 60;
		time = time - 60 * minute;
		second = time;
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


