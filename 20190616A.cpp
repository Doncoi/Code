#include <iostream>
using namespace std;

class student
{
private: 
int num; //ѧ��
char name[20]; //����
int score; //�ɼ�
static int count; //��¼�������
static int sum; //��¼�ܳɼ�
public:
student(); //���캯��
void input() //ѧ����Ϣ����
{
cin>>num>>name>>score;
}
int getsum(); //�����ܳɼ�
static int average(); //��ȡ�ɼ�ƽ��ֵ
static int getcount(); //��ȡ������� 
};

//��������Ҫ�������ɷ�д�����棬ֻ�ύbegin��end���ֵĴ���
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
