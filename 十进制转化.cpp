#include<iostream>
using namespace std;
int main() {
	int n,m,i,j,a[256]={0};
	cout << "��������Ҫת�������֣�" << endl;	 
	cin >> n;
	cout << "������ת����Ŀ�����" << endl;
	cin >> m; 
	for (i = 0; ; i ++){           //������������תΪm����
		a[i] = n % m;         //��������
		n = n / m;            //����n
		if(n == 0) break;   //n=0ʱ���ٽ���ȡ���������ֱ������
	}
    j = i;                     //��¼ת�������λ��
	for (i=j;i>=0;i--){       //ת����ʽ�����
		if(a[i]==15) cout<<"F";
		  else if(a[i]==14) cout<<"E";
		         else if(a[i]==13) cout<<"D";
		                else if(a[i]==12) cout<<"C";
		                       else if(a[i]==11) cout<<"B";
		                              else if(a[i]==10) cout<<"A";
                                             else cout<<a[i];  //ʮ���Ƽ���������ת��Ϊ��ĸ
	}
	return 0;
}
