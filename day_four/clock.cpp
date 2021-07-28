// clock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include<iostream>
using namespace std;

bool leap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}
class Clock {
public:
	Clock() {}
	Clock(int h, int m, int s)
	{
		hour = (h > 23 ? 0 : h);
		minute = (m > 59 ? 0 : m);
		second = (s > 59 ? 0 : s);
	}
	virtual void run()
	{
		second = second + 1;
		if (second > 59)
		{
			second = 0;
			minute += 1;
		}
		if (minute > 59)
		{
			minute = 0;
			hour += 1;
		}
		if (hour > 23)
		{
			hour = 0;
		}
	}
	virtual void showTime()
	{
		cout << "Now:" << hour << ":" << minute << ":" << second << endl;
	}
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }


protected:
	int hour;
	int minute;
	int second;
};


class Date {
public:
	Date(int y = 1996, int m = 1, int d = 1)
	{
		if (m > 12 || m < 1)
		{
			m = 1;
		}
		if (d > days(y, m))
		{
			d = 1;
		}
		day = d;
		year = y;
		month = m;
	};
	int days(int year, int month);
	void NewDay();
	void showTime()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
protected:
	int year;
	int month;
	int day;
};

int Date::days(int year, int month) {
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap(year))
	{
		a[1] = a[1] + 1;
	}
	return a[month - 1];
}

void Date::NewDay() {
	this->day++;
}

class ClockWithDate :public Clock, public Date {
public:
	ClockWithDate(int h, int m, int s, int day, int month, int year) {
		this->hour = h;
		this->minute = m;
		this->second = s;
		this->day = day;
		this->month = month;
		this->year = year;
	}

	virtual void run()
	{
		second = second + 1;
		if (second > 59)
		{
			second = 0;
			minute += 1;
		}
		if (minute > 59)
		{
			minute = 0;
			hour += 1;
		}
		if (hour > 23)
		{
			hour = 0;
			NewDay();
		}
		if (day > days(year, month)) {
			day = 1;
			month += 1;
		}
		if (month > 12) {
			month = 1;
			year += 1;
		}
	}
	virtual void showTime()
	{
		cout << "Now: " << second << ":" << minute << ":" << hour << " " << year << "-" << month << "-" << day << " ";
	}
};

int main()
{
	int h, m, s, day, month, year;
	cin >> h >> m >> s >> day >> month >> year;
	ClockWithDate* cd1 = new ClockWithDate(h, m, s, day, month, year);
	cd1->showTime();
	cout << "现在运行x秒:";
	int x;
	cin >> x;
	for (int i = 0; i < x; ++i)
		cd1->run();
	cd1->showTime();
	delete cd1;
	return 0;
}