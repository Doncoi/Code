#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INf 0x3f3f3
#define MAXN 200 + 5
#define MAXM 40000 + 5

using namespace std;

struct Node
{
	int head, color;
	//dfs序，子树最小序
	int dfn, low;
	bool vis;
} node[MAXN];

struct Edge
{
	int to, next;
} edge[MAXM];

int n, m, ans;
//分别记录边数，连通块数，深度
int cnt, sum, deep;
//模拟栈
int top, stack[MAXN << 1];
//连通块入度
int indegree[MAXN];

void addEdge(int u, int v)
{
	edge[++ cnt].to = v;
	edge[cnt].next = node[u].head;
	node[u].head = cnt; 
}

void Tarjan(int u)
{
	node[u].dfn = node[u].low = ++ deep;
	node[u].vis = true, stack[++ top] = u;

	for(int e = node[u].head, v; e; e = edge[e].next)
	{
		if(!node[v = edge[e].to].dfn)
		{
			Tarjan(v);
			node[u].low = min(node[u].low, node[v].low);
		}
		else
		{
			if(node[v].vis)
				node[u].low = min(node[u].low, node[v].dfn);
		}
	}

	if(node[u].dfn == node[u].low)
	{
		++ sum, node[u].vis = false;
		while(stack[top] != u)
		{
			node[stack[top --]].color = sum;
		}

		-- top;
	}
}

void ()
{
	int u, v;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		while(scanf("%d", &v) && v) addEdge(i, v);
		
	for(int i = 1; i <= n; ++ i)
		node[i].dfn = node[i].low = 0, node[i].vis = false;
}

int main()
{
	for(int i = 1; i <= n; ++ i)
		if(! node[i].dfn) Tarjan(i);

	for(int u = 1; u <= n; ++ u)
		for(int e = node[u].head, v; e; edge[e].next)
			if(node[u].color != node[v = edge[e].to].color)
				indegree[node[v].color] ++;

	for(int i = 1; i <= cnt; ++ i)
		if(! indegree[i]) ++ ans;

	printf("%d\n", ans);
}
