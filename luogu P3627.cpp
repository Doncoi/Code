#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3
#define MAXN 500000 + 5

using namespace std;

struct Node
{
	int weight, dis;	//每个点的money，同编号连通块在SPFA中的距离
	int head, color;	//每个点或同编号连通块的首边，每个点的颜色
	int dfn, low;	//dfs序和子树最小序
	bool vis;	//访问标记，同时充当in_stack和in_queue
} node[MAXN];

struct Edge
{
	int to, next, len;
} edge[MAXN];

int n, m, s, p, ans, tmp;
//边数，连通块数，深度
int cnt, CSS_cnt, deep;
//模拟栈
int top, stack[MAXN];
//存储边信息，记录缩点后的新点权值
int x[MAXN], y[MAXN], weight_cnt[MAXN];

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

void addEdge(int u, int v, int w)
{
	edge[++ cnt].to = v, edge[cnt].len = w;
	edge[cnt].next = node[u].head;
	node[u].head = cnt;
}

//Tarjan模板
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
		++ CSS_cnt;
		do
		{
			node[tmp = stack[top --]].vis = false;
			node[tmp].color = CSS_cnt;		
			//唯一要处理的是，顺便计算每个连通块的权值
			weight_cnt[CSS_cnt] += node[tmp].weight;
		} while(tmp != u);
	}
}

//SPFA模板
void SPFA()
{
	queue<int> q;
	for(int i = 1; i <= n; ++ i)
		node[i].dis = INF;

	int S = node[s].color; 
	node[S].dis = -weight_cnt[S];
    node[S].vis = true, q.push(S);

    while(! q.empty())
    {
    	int u = q.front(); node[u].vis = false; q.pop();
    	for(int e = node[u].head, v; e; e = edge[e].next)
    	{
    		if(node[v = edge[e].to].dis > node[u].dis + edge[e].len)
    		{
    			node[v].dis = node[u].dis + edge[e].len;
    			if(! node[v].vis)
    			{
    				q.push(v); 
    				node[v].vis = true;
    			}
    		}
    	}
    }
}

//清空head，vis，cnt，方便复用
void init()
{
	for(int i = 1; i <= n; ++ i)
		node[i].dfn = node[i].low = 0,
		node[i].head = node[i].dis = 0,
		node[i].vis = false;

	cnt = 0;
}

int main()
{
	init(); n = read(), m = read();
	for(int i = 1; i <= m; ++ i)
	{
		x[i] = read(),  y[i] = read();
		addEdge(x[i], y[i], 0);
	}
	for(int i = 1; i <= n; ++ i)
		node[i].weight = read();
	for(int i = 1; i <= n; ++ i)
		if(! node[i].dfn)
			Tarjan(i);

	// for(int i = 1; i <= n; ++ i)
	// 	cout << i << " color: " << node[i].color << " weight:" << node[i].weight << endl;
	// for(int i = 1; i <= CSS_cnt; ++ i)
	// 	cout << "color:" << i << " total:" << weight_cnt[i] << endl;

	//清空原图信息
	init();
	//缩点建图
	for(int i = 1; i <= m; ++ i)
	{
		int u = x[i], v = y[i];
		if(node[v].color != node[u].color)
			//点权转边权，要求最长路，故存储负权值
			addEdge(node[u].color, node[v].color, -(weight_cnt[node[v].color]));
	}

	// for(int i = 1; i <= cnt; ++ i)
	// 	cout << "edge " << i << " -> " << edge[i].to << " len: " << edge[i].len << endl;   

	s = read(), p = read();
	//单源最短路，SPFA只需要跑一次
	SPFA();
	//比较以每个酒吧作为终点的收益
	for(int i = 1; i <= p; ++ i)		
		if(- node[node[tmp = read()].color].dis > ans)
			ans = - node[node[tmp].color].dis;

	cout << ans << endl;
}