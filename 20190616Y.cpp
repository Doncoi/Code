#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class building
{
protected:
    string name;
    int floors;
    int areas;
public:
    building(string nm, int fl, int ar) : name(nm), floors(fl), areas(ar)
    {
    };
    void show()
    {
        cout << "建筑物名称：" << name << "，";
        cout << "层数：" << floors << "，";
        cout << "总面积：" << areas << "平方米，";
    }
};

class house : public building
{
protected:
    int bedrooms;
    int bathrooms;
public:
    house(string nm, int fl, int ar, int bdr, int bsr) : building::building(nm, fl, ar)
    {
        bedrooms = bdr;
        bathrooms = bsr;
    };
    void print()
    {
        building::show();
        cout << "卧室数：" << bedrooms << "，";
        cout << "浴室数" << bathrooms << "。" << endl;
    }
};

class office : public building
{
protected:
    int offices;
    int meetingrooms;
public:
    office(string nm, int fl, int ar, int off, int mtr) : building::building(nm, fl, ar)
    {
        offices = off;
        meetingrooms = mtr;
    };
    void print()
    {
        building::show();
        cout << "办公室数：" << offices << "，";
        cout << "会议室数" << meetingrooms << "。" << endl;
    }
};

int main()

{  

        house  myhouse("物联楼",3,200,5,2); 

             office  myoffice("胜院大厦",20,10000,2000,100);

         myhouse.print();myoffice.print(); 

         return 0;

}