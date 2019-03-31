#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 200000 + 5
#define MAXM 500 + 5

int n, m, cnt = 0, Q;
int num[MAXN], lnk[MAXN], sum[MAXN], out[MAXN];

struct Node
{
	int l, r;
} a[MAXN];

void construct(int l, int r)
{
	for(int i = r; i >= l; -- i)
	{
		if(i + num[i] > a[lnk[i]].r)
		{
			sum[i] = 1, out[i] = i + num[i];
		}
		else
		{
			sum[i] = sum[i + num[i]] + 1, out[i] = out[i + num[i]];
		}
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	n = read(), m = std :: sqrt(n);
	if(m * m < n) ++ m;
	for(int i = 1; i <= n; ++ i) num[i] = read();
	for(int i = 1; i <= n; i += m) a[++ cnt].l = i, a[cnt].r = i + m - 1; 
	if(cnt < m) a[++ cnt].l = cnt * m + 1, a[cnt].r = n; cnt = 1;
	
	for(int i = 1; i <= n; ++ i)
	{
		if(i > a[cnt].r) ++ cnt;
		lnk[i] = cnt;
	}
	construct(1, n);

	Q = read();
	while(Q --)
	{
		//int x = read(), y = read();
		int x = read(), y = read() + 1;
		if(x == 1)
		{
			int ans = sum[y], x = out[y];
			for(int i = lnk[y]; i <= m && x <= n; ++ i)
			{
				ans += sum[x], x = out[x];
			}
			std :: cout << ans << std :: endl;
		}
		else
		{
			num[y] = read();
			construct(a[lnk[y]].l, a[lnk[y]].r);
		}
	}
}
