#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 300 + 5
#define MAXM

int n, m, q;
int x, y, t;
long long hp[3], k, w;	
int type[MAXN][MAXN];
long long damage[MAXN][MAXN], sum[MAXN][MAXN];

long long read()
{
	long long res = 0; int flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (long long)(res * flg);
}

inline int max(int x, int y)
{
	return x > y ? x : y;
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}

inline int abs(int x)
{
	return x >= 0 ? x : (x * -1);
}

int main()
{
	n = read(), m = read();
	hp[0] = read(), hp[1] = read(), hp[2] = read(), k = read(), w = read();
	
	for(int i = 1; i <= k; ++ i)
	{
		for(int j = 1; j <= k; ++ j)
		{
			damage[i][j] = read();
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			type[i][j] = read() - 1;
		}
	}

	q = read();
	while(q --)
	{
		t = read(), x = read() - k / 2 - 1, y = read() - k / 2 - 1;
		for(int i = 1; i <= k; ++ i)
		{
			for(int j = 1; j <= k; ++ j)
			{
				if(x + i <= 0 || x + i > n || y + j <= 0 || y + j > m)
				{
					continue;
				}

				sum[x + i][y + j] += damage[i][j];
				if(t == 0)
				{
					for(int dx = -1; dx <= 1; ++ dx)
					{
						for(int dy = -1; dy <= 1; ++ dy)
						{
							if(! dx && ! dy)
							{
								continue;
							}
							if(x + i + dx <= 0 || x + i + dx > n)
							{
								continue;
							}
							if(y + j + dy <= 0 || y + j + dy > m)
							{
								continue;
							}
							sum[x + i + dx][y + j + dy] += w;
						}
					}
				}
			}
		}
	}

	long long cnt[3] = {0, 0, 0}, ans = 0;
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			long long res = std :: max(0ll, hp[type[i][j]] - sum[i][j]);
			if(!res) 
			{
				cnt[type[i][j]] ++;
			}
			ans += hp[type[i][j]] - res;
		}
	}

	printf("%lld %lld %lld\n%lld\n", cnt[0], cnt[1], cnt[2], ans);
}
