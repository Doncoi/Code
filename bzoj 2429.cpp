#include <cmath> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5
#define MAXM 2000000 + 5

struct Node
{
	int x, y;
	int father;
} node[MAXN];

struct Edge
{
	int from, to;
	double dis;
} edge[MAXM];

int n, m, ans = 0;
double maxn = 0.0;
int cnt = 0;
int monkey[MAXN];

int find(int x)
{
	return (node[x].father == x ? x : node[x].father = find(node[x].father));
}

bool same(int x, int y)
{
	x = find(x), y = find(y);
	return (x == y);
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x == y) return;
	node[x].father = y;
}

inline int abs(int x)
{
	return (x > 0 ? x : x * -1);
}

inline bool cmp(const Edge &x, const Edge &y)
{
	return x.dis < y.dis;
}

inline void addEdge(int u, int v, double w)
{
	edge[++ cnt].from = u, edge[cnt].to = v, edge[cnt].dis = w;
}

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
	while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
} 

void Kruskal()
{
	std :: sort(edge + 1, edge + cnt + 1, cmp);
	for(int i = 1; i <= cnt; ++ i)
	{
		int u = edge[i].from, v = edge[i].to;
		if(! same(u, v))
		{
			merge(u, v);
			maxn = (maxn > edge[i].dis ? maxn : edge[i].dis);
		}
	}
}

void init()
{
	m = read();
	for(int i = 1; i <= m; ++ i)
	{
		monkey[i] = read();
	}
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		node[i].x = read(), node[i].y = read();
		node[i].father = i;
	}
	
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = i + 1; j <= n; ++ j)
		{
			int dltx = abs(node[i].x - node[j].x);
			int dlty = abs(node[i].y - node[j].y);
			double dlt = std :: sqrt(dltx * dltx + dlty * dlty);
			addEdge(i, j, dlt), addEdge(j, i, dlt);
		}
	}
}

void solve()
{
	Kruskal();
	std :: cout << maxn << std :: endl;
	for(int i = 1; i <= m; ++ i)
	{
		if(monkey[i] >= maxn) ++ ans;
	}
	std :: cout << ans << std :: endl;
}

int main()
{
	init();
	solve();
}


