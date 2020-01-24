#include <queue> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3
#define MAXN 1000 + 5
#define MAXM 2000 + 5

using namespace std;

struct Node
{
	int head, dis;
	bool vis;
} node[MAXN];

struct Edge
{
	int to, next, cost, flow;
} edge[MAXM];

int n, m, ans, cnt;
int max_flow = 0, min_flow = 1;
int u, v, w, f;
queue<int> q;

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();} 
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

inline void addEdge(int u, int v, int w, int f)
{
	edge[++ cnt].to = v, edge[cnt].cost = w, edge[cnt].flow = f;
	edge[cnt].next = node[u].head, node[u].head = cnt;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		node[i].head = 0;
	for(int i = 1; i <= m; ++ i)
	{
		u = read(), v = read(), w = read(), f = read();
		max_flow = (max_flow > f ? max_flow : f);
		addEdge(u, v, w, f), addEdge(v, u, w, f);
	}
	
//	for(int i = 1; i <= n; ++ i)
//		cout << "node: " << i << " head: " << node[i].head << endl;
//	for(int i = 1; i <= cnt; ++ i)
//		cout << i << ": -> " << edge[i].to << " cost:" << edge[i].cost << " flow:" << edge[i].flow << endl;

	for(min_flow = 1; min_flow <= max_flow; ++ min_flow)
	{
		for(int i = 1; i <= n; ++ i)
			node[i].dis = INF, node[i].vis = false;

		node[1].dis = 0, node[1].vis = true; q.push(1);
		while(! q.empty())
		{
			u = q.front(); q.pop(); node[u].vis = false;
			for(int e = node[u].head, v; e; e = edge[e].next)
			{
				if(edge[e].flow < min_flow) continue;
				//cout << "current " << e << " :" << u << " -> " << edge[e].to << endl;
				if(node[v = edge[e].to].dis > node[u].dis + edge[e].cost)
				{
					node[v].dis = node[u].dis + edge[e].cost;
					if(! node[v].vis)
					{
						node[v].vis = true; q.push(v);
					}
				}
			}
		}
		
		if(node[n].dis != INF)
			ans = max(ans, min_flow * 1000000 / node[n].dis);
	}

	cout << ans << endl;
	return 0;
}
