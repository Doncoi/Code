#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 50000 + 5

int n, k, type, ans, x, y;
int father[MAXN * 3];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int find(int x)
{
	return (x == father[x] ? x : father[x] = find(father[x]));
}

void merge(int x, int y)
{
	if(find(x) != find(y))
	{
		father[find(x)] = find(y);
	}
}

int main()
{
	n = read(), k = read();
	for(int i = 1; i <= n * 3; ++ i)
	{
		father[i] = i;
	}

	for(int i = 1; i <= k; ++ i)
	{
		type = read(), x = read(), y = read();

		if(x > n || y > n || (type == 2 && x == y))
		{
			++ ans;
			continue;
		}
		if(type == 1)
		{
			if( find(x) == find(y + n) || 
				find(x) == find(y + n * 2) || 
				find(y) == find(n + x) ||
				find(y) == find(x + n * 2) )
			{
				++ ans;
				continue;
			}

			merge(x, y);
			merge(x + n, y + n);
			merge(x + 2 * n, y + 2 * n);
		}
		if(type == 2)
		{
			if( find(x) == find(y) ||
				find(x) == find(y + n) ||
				find(y) == find(x + n * 2) )
			{
				++ ans;
				continue;
			}

			merge(x, n * 2 + y);
			merge(x + n, y);
			merge(x + n * 2, y + n);
		}
	}

	printf("%d\n", ans);
	return 0;
}
