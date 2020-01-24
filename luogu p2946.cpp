#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 2000 + 5
#define MOD 100000000
using namespace std;

int n, m;
//第一位
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
		//读入时即对能力值取模处理
		a[i] = read() % m;	
		//初始化，表示仅选取该队员的方案共一种
		f[i][a[i]] = 1;  
	}

	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < m; ++ j)
		{
			//处理负数取模的情况
			int tmp = ((j - a[i]) % m + m) % m;
			//统计方案数，需要将每一种决策的方案数加和
			f[i][j] = (f[i][j] + f[i - 1][j] + f[i - 1][tmp]) % MOD;
		}

	cout << f[n][0] << endl;
}
