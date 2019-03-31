#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 50000 + 5

int n, m, ans, cnt = 0;

struct Node
{
	int father;
	bool flag;
} node[MAXN];

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
	while(scanf("%d%d", &n, &m) && n && m)
	{
		ans = 0;
		for(int i = 1; i <= n; ++ i)
		{
			node[i].father = i;
			node[i].flag = false;
		}
		for(int i = 1; i <= m; ++ i)
		{
			int x = read(), y = read();
			merge(x, y); 
		}

		for(int i = 1; i <= n; ++ i)
		{
			node[find(i)].flag = true;
		}

		for(int i = 1; i <= n; ++ i)
		{
			if(node[i].flag) 
			{
				++ ans;
			}
		}

		printf("Case %d: %d\n", ++ cnt, ans);
	}
}
