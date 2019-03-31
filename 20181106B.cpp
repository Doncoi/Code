#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5

int N, n, x, y, ans_y, ans_n;

struct Node
{
	int father;
} node[MAXN];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int find(int x)
{
	return (node[x].father == x ? x : node[x].father = find(node[x].father));
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(y == x)
	{
		return;
	}
	else
	{
		node[y].father = x;
	}
}

bool judge(int x, int y)
{
	return (find(x) == find(y));
}

void init()
{
	for(int i = 1; i <= n; ++ i)
	{
		node[i].father = i;
	}
	ans_y = ans_n = 0;
}

void solve()
{
	char ch = getchar();
	while(1)
	{
		x = read(), y = read();
		if(ch == 'c')
		{
			printf("merge %d - %d\n", x, y);
			merge(x, y);
		}
		else
		{
			printf("query %d - %d\n", x, y);
			if(judge(x, y))
			{
				++ ans_y;
			}
			else 
			{
				++ ans_n;
			}
		}
		
		ch = getchar();
		if(ch == '\n')
		{
			return;
		}
		
		if(ch > '0' && ch <= '9')
		{
			int res = ch - '0';
			while(!isdigit(ch)) {ch = getchar();}
			while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
			n = res;
			return;
		}
	}
}

void output()
{
	printf("%d,%d\n\n", ans_y, ans_n);
}

int main()
{
	N = read();
	n = read();
	while(N --)
	{
		init();
		solve();
		output();
	}
}
