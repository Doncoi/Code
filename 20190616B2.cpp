#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Time
{
public:
	Time(int h, int m, int s) : hour(h), minute(m), second(s)
	{

	};
	void display()
	{
		cout << hour << "ʱ" << minute << "��" << second << "��" << endl; 
	} 
private:
	int hour;
	int minute;
	int second;		
};

class Date
{
public:
	Date(int y, int m, int d) : year(y), month(m), date(d)
	{	
	}
	void display()
	{
		cout << year << "��" << month << "��" << date << "��" << endl; 	
	}
private:
	int year;
	int month;
	int date;
};

class Birthtime : public Time, public Date
{
public:
	Birthtime(int y, int mt, int d, int h, int mi, int s, string n) : Date::Date(y, mt, d), Time::Time(h, mi, s)
	{
		name = n;
	};
	void display()
	{
		cout << "������" << name << endl; 
		cout << "�������£�";
		Date::display(); 
		cout << "����ʱ�䣺";
		Time::display();
	}
private:
	string name;
};

int main() 
{ 
    Birthtime boy(2019,6,1,10,15,25,"����");
    boy.display();
    return 0;
} 
