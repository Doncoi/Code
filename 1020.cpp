#include <cstdio>
#include <iostream>
#define MAXN 100 + 5

int n, x1, x2;
int dis[MAXN][MAXN];

int min(int x, int y)
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

void updateTime(int a, int b, int t)
{
	if(dis[a][b] == 0 || t < dis[a][b])
	{
		dis[a][b] = dis[b][a] = t;
	}
}

void calcTime()
{
	int t1, t2;
	for(int a = 1; a  <= n; ++ a)
	{
		for(int b = 1; b <= n; ++ b)
		{
			t1 = dis[a][b];
			if(t1 > 0)
			{
				for(int c = 1; c <= n; ++ c)
				{
					t2 = dis[b][c];
					if(t2 > 0 && a != c)
					{
						updateTime(a, c, t1 + t2);
					}
				}
			}
		}
	}
}

int getMaxn(int a, int b)
{
	int tmp, maxn = 0;
	for(int c = 1; c <= n; ++ c)
	{
		tmp = min(dis[a][c], dis[b][c]);
		if(maxn == 0 || maxn < tmp)
		{
			maxn = tmp;
		}
	}

	return maxn;
}

void calcPoint()
{
	int tmp, minn = 0;
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = i + 1; j <= n; ++ j)
		{
			tmp = getMaxn(i, j);
			if(minn == 0 || (minn != 0 && minn > tmp))
			{
				minn = tmp, x1 = i, x2 = j;
			} 
		}
	}

	printf("%d %d\n", x1, x2);
}

void init()
{
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			dis[i][j] = 0;
		}
	}

	int x, y, z;
	
	while(std :: cin >> x >> y >> z)
	{
		dis[x][y] = dis[y][x] = z;
	}
	
	/*
	do
	{
		x = y = z = 0;
		x = read(), y = read(), z = read();
		if(x && y && z)
		{
			dis[x][y] = dis[y][x] = z;
		}
	}  while(x || y || z);
	*/
}

void solve()
{
	calcTime();
	calcPoint();
}

int main()
{
	init();
	solve();
	return 0;
}
