#include <cstdio>
#define MAXN 30000 + 5

int n, m, dp[MAXN] = {0};

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void init()
{
	n = read(), m = read();
}

void solve()
{
	while(m --)
	{
		int cost, value, tmp;
		cost = read(), tmp = read(), value = cost * tmp;
		for(int i = n; i >= cost; -- i)
		{
			dp[i] = dp[i] > dp[i - cost] + value ? dp[i] : dp[i - cost] + value;
		}
	}

	printf("%d\n", dp[n]);
}

int main()
{
	init();
	solve();
	return 0;
}
