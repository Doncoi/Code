#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10000 + 5
#define MAXM 50000 + 5

using namespace std;

struct Node
{
	//首边，所属连通块
	int head, color;
	//dfs序，子树最小序
	int dfn, low;
	int outdegree;
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
int x, y, tmp;
int CSS_count[MAXN], outdegree[MAXN];

void addEdge(int u, int v)
{
	edge[++ cnt].to = v;
	edge[cnt].next = node[u].head;
	node[u].head = cnt; 
	node[u].outdegree ++;
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
		++ sum;
		do
		{
			node[tmp = stack[top --]].vis = false;
			node[tmp].color = sum;	
			CSS_count[sum] ++;
			//outdegree[sum] += node[tmp].outdegree;	
		} while(tmp != u);
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
	{
		node[i].dfn = node[i].low = 0;
		node[i].vis = false;
		node[i].outdegree = 0;
	}
	for(int i = 1; i <= m; ++ i)
	{
		cin >> x >> y;
		addEdge(x, y);
	}
	for(int i = 1; i <= n; ++ i)
	{
		if(! node[i].dfn)
			Tarjan(i);
	}
	
	for(int u = 1; u <= n; ++ u)
	{
		for(int e = node[u].head, v; e; e = edge[e].next)
		{
			if(node[v = edge[e].to].color != node[u].color)
			{
				++ outdegree[node[u].color];
			}
		}
	}

	for(int i = 1; i <= sum; ++ i)
	{
		if(outdegree[i] == 0)
		{
			if(! ans) ans = CSS_count[i];
			else ans = -1;
		}
	}
	
	cout << (ans == -1 ? 0 : ans);
}
