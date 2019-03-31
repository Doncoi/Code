#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 50005

struct Node
{
	int l, s;
} node[MAXN * 6];

int n, tot, len, c[MAXN * 6];
int x, y, z;

int cmp(Node x, Node y)
{
	if(x.l < y.l)
	{
		return 1;
	}
	if(x.l == y.l && x.s >= y.s)
	{
		return 1;
	}
	return 0;
}

void addNode(int x, int y, int z)
{
	node[++ tot].l = x, node[tot].s = y;
	node[++ tot].l = x, node[tot].s = z;
	node[++ tot].l = y, node[tot].s = z;
	node[++ tot].l = y, node[tot].s = x;
	node[++ tot].l = z, node[tot].s = x;
	node[++ tot].l = z, node[tot].s = y;
}

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void init()
{
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		x = read(), y = read(), z = read();
		addNode(x, y, z);
	}
	std :: sort(node + 1, node + tot + 1, cmp);
}

void solve()
{
	for(int i = 1; i <= tot; ++ i)
	{
		if(node[i].s > c[len])
		{
			c[++ len] = node[i].s;
		}
		else
		{
			int l = 1, r = len, mid, maxn;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(node[i].s <= c[mid])
				{
					maxn = mid, r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}

			c[maxn] = node[i].s;
		}
	}

	printf("%d\n", len);
}

int main()
{
	init();
	solve();
	return 0;
}
