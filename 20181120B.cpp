#include <cstdio>
#include <cstring>
#define MAXN 500 + 5

int n, cnt = 0;
int a[MAXN], ans[MAXN];

void calc()
{
	a[1] = 1, a[2] = 5, a[3] = 13, a[4] = 26, a[5] = 45, a[6] = 69;
	for(int i = 7; i <= 500; ++ i)
	{
		a[i] = i * i + (i - 1) * i * (i + 1) / 6;
	}
}

int main()
{
	calc();
	while(scanf("%d", &n) == 1)
	{
		ans[++ cnt] = a[n];
	}
	
	for(int i = 1; i <= cnt; ++ i)
	{
		printf("%d\n", ans[i]);
	}
}

