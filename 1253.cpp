#include <cstdio>
#include <cstring>
#define MAXN 100 + 5
#define MAXM 100000 + 5
#define MAXK 1000000 + 5

int n, m;
int pos[MAXM], pos1[MAXN];
double f[MAXM][MAXN], val[MAXK];

double min(double x, double y)
{
	return (x < y ? x : y);
}

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
	 for(int i = 1; i <= n; ++ i)
	 {
	 	pos1[i] = read();
	 }
	 for(int i = 1; i <= m; ++ i)
	 {
	 	scanf("%d%lf", &pos[i], &val[i]);
	 }
	 memset(f, 127, sizeof(f));
	 for(int i = 1; i <= m; ++ i)
	 {
	 	f[i][0] = 0;
	 }
}

void solve()
{
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			f[i][j] = f[i - 1][j];
			if(pos[i] == pos1[j])
			{
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + val[i]);
			}
		}
	}

	if(f[m][n] >= 0x7fffffff)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%.2f\n", f[m][n]);
	}
}

int main()
{
	init();
	solve();
	return 0;
}

