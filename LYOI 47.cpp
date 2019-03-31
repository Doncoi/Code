#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 3000 + 5

int n, m, maxn = 0;
int map[MAXN][MAXN];

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(! isdigit(ch)) {if(ch == '-') flag = -1; ch = getchar();}
	while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i)
	{
		map[read()][read()] = -1;
	}

	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			if(map[i][j] == -1)
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
			}

			maxn = max(maxn, map[i][j]);
		}
	}

	std :: cout << maxn << std :: endl;
	return 0;
}
