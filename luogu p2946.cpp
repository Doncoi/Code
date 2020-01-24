#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 2000 + 5
#define MOD 100000000
using namespace std;

int n, m;
//��һλ
int f[MAXN][MAXN], a[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}


int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		//����ʱ��������ֵȡģ����
		a[i] = read() % m;	
		//��ʼ������ʾ��ѡȡ�ö�Ա�ķ�����һ��
		f[i][a[i]] = 1;  
	}

	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < m; ++ j)
		{
			//������ȡģ�����
			int tmp = ((j - a[i]) % m + m) % m;
			//ͳ�Ʒ���������Ҫ��ÿһ�־��ߵķ������Ӻ�
			f[i][j] = (f[i][j] + f[i - 1][j] + f[i - 1][tmp]) % MOD;
		}

	cout << f[n][0] << endl;
}
