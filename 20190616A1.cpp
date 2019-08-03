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
		cout << "������" << name << "��";
		cout << "�Ա�" << sex << "��";
		cout << "���䣺" << age << "��"; 
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
		cout << "ѧ�ţ�" << number << "��";
		cout << "�ɼ���" << score << "��" << endl;
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
		cout << "ְ��" << position << "��";
		cout << "���ţ�" << department << "��" << endl; 
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
		cout << "ѧ�ţ�" << number << "��";
		cout << "�ɼ���" << score << "��";
		cout << "����" << research_direction << "��";
		cout << "��ʦ��" << tutor << "��" << endl; 
	}
	void show_1()
	{
		speople::show();
		cout << "ѧ�ţ�" << number << "��";
		cout << "�ɼ���" << score << "��";
		cout << "����" << research_direction << "��";
		cout << "��ʦ��" << tutor << "��"; 
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
		cout << "ְ��" << position << "��";
		cout << "���ţ�" << department << "��" << endl; 
	}
};                                     

int main()

{

       cstudent c("����","��",20,"20188888",90);

         c.show();

         cteacher t("����ʦ","��",40,"����������","������");

         t.show();
		
         cgraduate g("С��","Ů",20,"����������","�µ�","20187777",98);

         g.show();

         cgraonwork w("С��","��",20,"����������","�µ�","20189999",100,"����","������");

         w.show();
		
         return 0;

}
