#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 300000 + 5

struct Node
{
	int dep, dis;
	int head, fath;
	long long ans;
	bool vis;
} node[MAXN];

struct Edge
{
	int tar, len, nxt;
} edge[MAXN << 1];

int n, cnt, ans;
int max_dep, max_node;
int q[MAXN >> 1], head, tail;

inline int Read()
{
	int res = 0, flg = 1; char chr = getchar();
	while( ! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

inline void AddEdge(int u, int v, int w)
{
	edge[++ cnt].tar = v, edge[cnt].len = w;
	edge[cnt].nxt = node[u].head, node[u].head = cnt;
}

void Build(int u)
{
	for(int e = node[u].head, v; e; e = edge[e].nxt)
	{
		if(node[v = edge[e].to].dep) continue;
		node[v].dep = node[u].dep + 1;
		node[v].fath = u;
		if(node[v].dep > max_dep)
			max_dep = node[v].dep, max_node = v;
		Build(v);
	}

	node[max_node].dis = 1;
}

void DFS()
{

}

void BFS()
{
	while(head <= tail)
	{
		int u = q[head], e, v;
		for(e = node[u].head; e; e = edge[e].nxt)
		{
			if(node[v = edge[e].to].dis) continue;
			node[v].dis = node[u].dis + 1;
			//do something
			if(node[v].dis >= k) continue;
			q[++ tail] = v;
		}
	}
}

void Solve(int len)
{
	q[head = tail = 1] = max_node;
	BFS();
	q[head = tail = 1] = max_node;
	for(int i = 2; i <= k; ++ i)
	{
		q[++ tail] = node[q[tail - i]].fath;
	}	
	DFS();
}

int main()
{
	n = Read(), k =ead();
	for(int i = 1; i <= n; ++ i)
	{
		int u = Read(), v = Read(), w = Read();
		AddEdge(u, v, w), AddEdge(v, u, w);
	}
	node[1].dep = 1, Build(1);
	for(int i = 2; i <= k; ++ i)
	{
		Solve(i);
	}
	for(int i = 1; i <= n; ++ i)
	{
		std :: cout << node[i].ans << " " << std :: endl;
	}
}