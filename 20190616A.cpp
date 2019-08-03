#include <iostream>
using namespace std;

class student
{
private: 
int num; //学号
char name[20]; //姓名
int score; //成绩
static int count; //记录对象个数
static int sum; //记录总成绩
public:
student(); //构造函数
void input() //学生信息输入
{
cin>>num>>name>>score;
}
int getsum(); //计算总成绩
static int average(); //获取成绩平均值
static int getcount(); //获取对象个数 
};

//将程序需要的其他成份写在下面，只提交begin到end部分的代码
//******************** begin ********************
int student::count = 0;
int student::sum = 0;

student::student()
{
	num = 0, score = 0;
	//cout << "construct" << endl;
}

int student::getsum()
{
	sum += score;
	count ++;
	//cout << "getnum" << endl;
	return sum;
}

int student::getcount()
{
	//cout << "getcount" << endl;
	return count;
}

int student::average()
{
	//cout << "getaverage" << endl;
	if(count == 0) return count;
	else return sum / count;
}

//********************* end ********************

int main()
{
int n;
cin>>n;
student *p=new student[n];
while(n--)
{ 
p->input();
p->getsum();
p++;
} 
cout<<"student count="<<student::getcount()<<endl;
cout<<"average score="<<student::average()<<endl;
return 0;
}
