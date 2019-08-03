#include <cstdio>
#include <iostream>
using namespace std;

class speople
{
protected:
	string name;
	string sex;
	int age;
public:
	speople(string nm, string sx, int ag) : name(nm), sex(sx), age(ag)
	{
		
	};
	void show()
	{
		cout << "姓名：" << name << "，";
		cout << "性别：" << sex << "，";
		cout << "年龄：" << age << "，"; 
	}
};

class cstudent : public speople
{
protected:
	string number;
	int score;
public:
	cstudent(string nm, string sx, int ag, string nb, int sc) : speople::speople(nm, sx, ag)
	{
		number = nb;
		score = sc;
	};
	void show()
	{
		speople::show();
		cout << "学号：" << number << "，";
		cout << "成绩：" << score << "。" << endl;
	}
};

class cteacher : public speople
{
protected:
	string position;
	string department;
public:
	cteacher(string nm, string sx, int ag, string ps, string dp) : speople::speople(nm, sx, ag)
	{
		position = ps;
		department = dp;
	};
	void show()
	{
		speople::show();
		cout << "职务：" << position << "，";
		cout << "部门：" << department << "。" << endl; 
	}
};

class cgraduate : public cstudent
{
protected:
	string research_direction;
	string tutor;
public:
	cgraduate(string nm, string sx, int ag, string rd, string tt, string nb, int sc)
	 : cstudent::cstudent(nm, sx, ag, nb, sc)
	{
	 	research_direction = rd;
	 	tutor = tt;
	};
	void show()
	{
		speople::show();
		cout << "学号：" << number << "，";
		cout << "成绩：" << score << "，";
		cout << "方向：" << research_direction << "，";
		cout << "导师：" << tutor << "。" << endl; 
	}
	void show_1()
	{
		speople::show();
		cout << "学号：" << number << "，";
		cout << "成绩：" << score << "，";
		cout << "方向：" << research_direction << "，";
		cout << "导师：" << tutor << "，"; 
	}
};

class cgraonwork : public cgraduate, public cteacher
{
public:
	cgraonwork(string nm, string sx, int ag, string rd, string tt, string nb, int sc, string ps, string dp)
	: cgraduate(nm, sx, ag, rd, tt, nb, sc), cteacher(nm, sx, ag, ps, dp)
	{
		
	};
	void show()
	{
		cgraduate::show_1();
		cout << "职务：" << position << "，";
		cout << "部门：" << department << "。" << endl; 
	}
};                                     

int main()

{

       cstudent c("李坤","男",20,"20188888",90);

         c.show();

         cteacher t("陈老师","男",40,"教研室主任","物联网");

         t.show();
		
         cgraduate g("小文","女",20,"物联网工程","陈导","20187777",98);

         g.show();

         cgraonwork w("小涵","男",20,"物联网工程","陈导","20189999",100,"经理","技术部");

         w.show();
		
         return 0;

}
