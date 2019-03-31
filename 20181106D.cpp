#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 30000 + 5

int N, n, m, ans;

struct Node
{
	int father;
	int cnt;
} node[MAXN];

int max(int x, int y)
{
	return (x > y ? x : y);
}

int find(int x)
{
	return (node[x].father == x ? x : node[x].father = find(node[x].father));
}

void merge(int x, int y)
{	
	int a = find(x), b = find(y);
	if(a == b)
	{
		return;
	}
	else
	{
		node[b].father = a;
	}
}

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	N = read();
	while(N --)
	{
		n = read(), m = read(), ans = -1;
		for(int i = 1; i <= n; ++ i)
		{
			node[i].father = i;
			node[i].cnt = 0;
		}
		for(int i = 1; i <= m; ++ i)
		{
			int x = read(), y = read();
			merge(x, y);
		}

		for(int i = 1; i <= n; ++ i)
		{
			ans = max(ans, ++ node[find(i)].cnt);
		}

		printf("%d\n", ans);
	}
}
