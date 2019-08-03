#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
public:
	Student();
	void input();
	double getscore();
	int getnumber();
private:
	int number;
	double score;
};

Student::Student()
{
	number = 0;
	score = 0.0;
}

void Student::input()
{
	cin >> number >> score; 
}

double Student::getscore()
{
	return score;
}

int Student::getnumber()
{
	return number;
}

void max(Student *x, int n)
{
	double maxn = 0;
	int ans = 0;
	for( ; x->getscore() != 0; x ++)
	{
		if(x->getscore() > maxn) 
		{
			maxn = x->getscore();
			ans = x->getnumber();
		}
	}
	cout << ans << " " << maxn << endl;
}

int main()

{

    void max(Student* ,int);

    const int NUM=10;

    Student stud[NUM];

    int n,i;

    cin>>n;

    for(i=0; i<n; i++)

        stud[i].input();

    cout<<setiosflags(ios::fixed);

    cout<<setprecision(2); //设置输出数字精度为2

    Student *p=&stud[0];

    max(p,n);

    return 0;

}
