#include<iostream>
using namespace std;
int main() {
	int n,m,i,j,a[256]={0};
	cout << "请输入您要转化的数字：" << endl;	 
	cin >> n;
	cout << "请输入转化的目标进制" << endl;
	cin >> m; 
	for (i = 0; ; i ++){           //储存余数，即转为m进制
		a[i] = n % m;         //储存余数
		n = n / m;            //更新n
		if(n == 0) break;   //n=0时不再进行取余操作，可直接跳出
	}
    j = i;                     //记录转换结果的位数
	for (i=j;i>=0;i--){       //转换格式后输出
		if(a[i]==15) cout<<"F";
		  else if(a[i]==14) cout<<"E";
		         else if(a[i]==13) cout<<"D";
		                else if(a[i]==12) cout<<"C";
		                       else if(a[i]==11) cout<<"B";
		                              else if(a[i]==10) cout<<"A";
                                             else cout<<a[i];  //十进制及以下无需转换为字母
	}
	return 0;
}
