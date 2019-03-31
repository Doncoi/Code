#include <cstdio>
#include <algorithm>
#define MAXN 10005

int n, m;
int a[MAXN];

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();} 
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

void init()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		a[i] = read();
	}
}

void solve()
{	
	//freopen("martian.in", "r", stdin);
	//freopen("martian.out", "w", stdout);
	
	for(int i = 1; i <= m; ++ i)
	{
		std :: next_permutation(a + 1, a + n + 1);
	}
	for(int i = 1; i <= n; ++ i)
	{
		printf("%d ", a[i]);
	}
	
	//fclose(stdin);
	//fclose(stdout);
}

int main()
{
	init();
	solve();
}
