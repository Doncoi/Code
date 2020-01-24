#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 220 + 5
#define MAXM 500 + 5
#define INF 0x3f3f3f3f

using namespace std;

int d, p, c, f;
int n, m, s, cnt, ans;
int u, v, w;

struct Node
{
	int head, num;
	int dis；
	bool in_queue;
} node[MAXN];

struct Edge
{
	int to, next, dis;
} edge[MAXM];

inline int read() {
	char ch = getchar(); int res = 0;
	while( ch < '0' || ch > '9' ) ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

void addEdge(int u, int v, int w)
{
	edge[++ cnt].next = node[u].head;
	edge[cnt].to = v, edge[cnt].dis = w;
	node[u].head = cnt;
}

bool SPFA()  //常规SPFA模板
{
	std :: queue<int> q;
	for(int i = 1; i <= n; ++ i)
	{
		node[i].dis = INF;
		node[i].in_queue = false;
		node[i].num = 0;
	}

	node[s].dis = 0, node[s].num ++;
    node[s].in_queue = true, q.push(s);

    while(! q.empty())
    {
    	int u = q.front(); node[u].in_queue = false; q.pop();
    	for(int e = node[u].head, v; e; e = edge[e].next)
    	{
    		if(node[v = edge[e].to].dis > node[u].dis + edge[e].dis)
    		{
    			node[v].dis = node[u].dis + edge[e].dis;
    			if(! node[v].in_queue)
    			{
    				q.push(v); node[v].in_queue = true; node[v].num ++;
    				if(node[v].num > n) return false;
    			}
    		}
    	}
    }

    return true;
}

int main()
{
	d = read(), p = read(); 
	n = read(), m = read(), s = read();

	for(int i = 1; i <= p; ++ i)
	{
		u = read(), v = read();
		addEdge(u, v, d * -1);	//转为负权
	}
	for(int i = 1; i <= m; ++ i)
	{
		u = read(), v = read(), w = read();
		addEdge(u, v, w - d);  //-(d-w) = w-d
	}

	bool flag = SPFA();
	
	if(flag)	//无负环
	{
		ans = INF;
		for(int i = 1; i <= n; ++ i)
			if(ans > node[i].dis)
				ans = node[i].dis;
		//补上起点的收入
		ans = ans * -1 + d;
	}
	else	//有负环
	{
		ans = -1;
	}

	cout << ans << endl;
}