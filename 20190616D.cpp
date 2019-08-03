#include <cstdio>
#include <string> 
#include <cstring>
#include <iostream>
using namespace std;

class student
{
public:
	student(int n, string m, int s);
	void print();
	static int get_count();
	static int get_avg();
private:
	int number;
	string name;
	int score;
	
	static int count;
	static int total_score;		
};

int student::count = 0;
int student::total_score = 0;

student::student(int n, string m, int s) : number(n), name(m), score(s)
{
	//m.copy(name, m.length());
	//name = m;
	++ count;
	total_score += score; 
}

void student::print()
{
	cout << number << " ";
	cout << name << " ";
	cout << score << endl;
}

int student::get_count()
{
	return count;
}

int student::get_avg()
{
	if(count == 0) return 0;
	return total_score / count;
}

int main() 
{ 
	student s1(201601,"john",85),s2(201602,"mike",90),s3(201603,"june",95);
	s1.print();
	s2.print();
	s3.print();
	cout<<"共有"<<student::get_count()<<"位学生，平均成绩为："<<student::get_avg()<<endl;
	return 0; 
}
