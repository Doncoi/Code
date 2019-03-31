#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 * 2 + 5 

struct Node
{
	int head, atk;
	bool mark;
} node[MAXN * 2];

struct Edge
{
	int to, next;
} edge[MAXN * 2];

int n, m, cnt, tot, adv;
int set[MAXN];
bool flag = false;

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void addEdge(int u, int v)
{
	edge[++ cnt].to = v, edge[cnt].next = node[u].head, node[u].head = cnt;
}

void addClause(int x, int xv, int y, int yv)
{
	x = x * 2 + xv, y = y * 2 + yv;
	addEdge(x ^ 1, y), addEdge(y ^ 1, x);
}

int type(int x)
{
	return node[x].atk >= adv ? 1 : -1; 
}

bool DFS(int u)
{
	if(node[u ^ 1].mark) return false;
	if(node[u].mark) return true;
	node[u].mark = true, set[tot ++] = u;

	for(int e = node[u].head; e; e = edge[e].next)
	{
		if(!DFS(edge[e].to))
		{
			return false;
		}
	}

	return true;
} 

void init()
{
	n = read(), m = read(), cnt = adv = 0;
	for(int i = 1; i <= n; ++ i)
	{
		node[i].atk = read(), adv += node[i].atk;
	}
	adv /= n;
	for(int i = 1; i <= m; ++ i)
	{
		int x = read(), y = read();
		addClause(x, 1, y, 1);
		if(type(x) == type(y))
		{
			addClause(x, 0, y, 0);	
		}
	}
}

void solve()
{
	for(int i = 1; i <= n * 2; i += 2)
	{
		if(!node[i].mark && !node[i + 1].mark)
		{
			tot = 0;
			if(!DFS(i))
			{
				for( ; tot > 0; node[set[-- tot]].mark = false);
				if(!DFS(i + 1))
				{
					return;
				}
			}
		}
	}

	flag = true;
}

void output()
{
	if(!flag) 
	{
		std :: cout << "PLEASE GO HOME TO STUDY" << std :: endl; 
	}
	else
	{
		for(int i = 1; i <= n; ++ i)
		{
			if(node[i << 1].mark)
			{
				std :: cout << "3 ";
			}
			else
			{
				type(i) == 1 ? std :: cout << "1 " : std :: cout << "2 ";
			}
		}
		std :: cout << std :: endl;
	}
}

int main()
{
	init();
	solve();
	output();
}
