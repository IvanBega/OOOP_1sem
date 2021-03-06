#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
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
		int day_of_week = getDayByDate();
		cout << days_of_week[day_of_week] << ", ";
		cout << year << " " << setfill('0') << setw(2) << month << " " << setfill('0') << setw(2) << day << " "
				<< setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;
	}
	void print2()
	{
		using namespace std;
		cout << year << " years, " << month << " month, " << day << " days, " <<
			hour << " hours, " << minute << " minutes, " << second << " seconds";
	}
	void print3()
	{
		using namespace std;
		cout << year << " " << setfill('0') << setw(2) << month << " " << setfill('0') << setw(2) << day << " " << setfill('0') << setw(2) <<
			hour << ":" << setfill('0') << setw(2)  << minute << ":" << setfill('0') << setw(2)  << second;
	}
	bool isCorrect()
	{
		if ((year >= 0) && (month == 2) && (year % 4 == 0) && (day <= 29))
			return true;
		if (year < 0 || month <= 0 || month > 12 || day > days_in_month[month - 1])
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
	static int dateDiff(Date date1, Date date2)
	{
		if (date2 > date1)
			std::swap(date1, date2);
		return Date::toDays(date1.year, date1.month, date1.day) - Date::toDays(date2.year, date2.month, date2.day);
	}
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
	void subtractDate(Date date)
	{
		subtractDate(date.year, date.month, date.day, date.hour, date.minute, date.second);
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
	bool operator >(const Date& date) const
	{
		if (this->year > date.year)
			return true;
		if (this->year < date.year)
			return false;

		if (this->month > date.month)
			return true;
		if (this->month < date.month)
			return false;

		if (this->day > date.day)
			return true;
		if (this->day < date.day)
			return false;

		int this_sec = this->hour * 3600 + this->minute * 60 + this->second;
		int date_sec = date.hour * 3600 + date.minute * 60 + date.second;
		return this_sec > date_sec;
	}
	void fillWithRandom()
	{
		std::srand(std::rand());
		year = std::rand() % 22 + 2000;
		month = std::rand() % 12 + 1;
		day = std::rand() % days_in_month[month - 1] + 1;
		hour = std::rand() % 24;
		minute = std::rand() % 60;
		second = std::rand() % 60;
	}
	void fillFromConsole()
	{
		using namespace std;
		short Year, Month, Day, Hour, Minute, Second;
		while (true)
		{
			cout << "Enter Year, Month and Day: \n";
			cin >> Year >> Month >> Day;
			cout << "Enter Hours, Minutes, and Seconds: \n";
			cin >> Hour >> Minute >> Second;
			year = Year; month = Month; day = Day; hour = Hour; minute = Minute; second = Second;
			if (!isCorrect())
			{
				cout << "Date is incorrect! Try again...\n";
			}
			else
			{
				cout << "You entered ";
				print();
				break;
			}
		}
	}
	void subtractYear(short Year)
	{
		year -= Year;
	}
private:
	static constexpr const char* days_of_week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	static constexpr const short days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const int sec_in_day = 86400;
	short year = 0;
	short day = 1;
	short month = 1;
	short hour = 0;
	short minute = 0;
	short second = 0;
};


