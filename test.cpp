#include <iostream>
#include <string>
using namespace std;
class Student
{ 
protected:
	string name;
	char sex;
	int age;
	int number;
	string dep;
public:
	Student(string n,char s, int a, int num,string d)
	{name = n; sex = s; age = a; number = num; dep = d;}
	void display()
	{
		cout << " name " << name << " " << "sex" << sex << " " << "age " << age << " " << "number" << number << " " << "department" << dep << endl;
	}
};
class Gradstudent : public Student
{
	string teacher;
public:
	Gradstudent(string n, char s, int a, int num, string d, string t) :Student(n, s, a, num, d)
	{teacher = t;}
		void display()
		{
			cout << " name " << name << " " << "sex" << sex << " " << "age " << age << " " << "number" << number << " " << "department" << dep <<"teacher"<<teacher<< endl;
		}
};
int main()
{
	Student s("Ann"," F", 18, 001, "computer");
	Gradstudent g("Mike", "M", 22, 003, "math", "John");
	s.display();
	g.display();
	return 0;


}
