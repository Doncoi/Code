#include <iostream>  

using namespace std;  

class Q  
{  

public:  
    void set_value();  
    int get_Max();  
	//此处声明需要的成员函数  

private:  
  int n;  
  int a[100];  
};  

void Q::set_value()
{
	cin >> n;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];	
	}	
} 

int Q::get_Max()
{
	int maxn = 0;
	for(int i = 1; i <= n; ++ i)
	{
		maxn = (maxn > a[i] ? maxn : a[i]);
	}
	return maxn;
}

int main()  
{  
  Q b1;  
  b1.set_value();  
  cout<<b1.get_Max()<<endl;  
  return 0;  
}  
