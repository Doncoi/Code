#include <bits/stdc++.h>
#define MAXN 5000 + 5
#define MAXM 20000 + 5
#define INF 0x3f3f3f3

int n, m, s, t;
int cnt = 0;

struct Point
{
	int head, dis, num;
	bool in_queue;
} node[MAXN];

struct Edge
{
	int to, next, dis;
} edge[MAXM * 2];

void addEdge(int u, int v, int w)
{
	edge[++ cnt].next = node[u].head;
	edge[cnt].to = v, edge[cnt].dis = w;
	node[u].head = cnt;
}

bool SPFA(int s, int n)
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
    	int x = q.front(); node[x].in_queue = false; q.pop();
    	for(int e = node[x].head, v; e; e = edge[e].next)
    	{
    		if(node[v = edge[e].to].dis > node[x].dis + edge[e].dis)
    		{
    			node[v].dis = node[x].dis + edge[e].dis;
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

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
	while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	n = read(), m = read(), s = read(), t = read();
	//std :: cout << m << std :: endl;
	for(int i = 1; i <= m; ++ i)
	{

		int x = read(), y = read(), z = read();
		addEdge(x, y, z), addEdge(y, x, z); 
	}

	SPFA(s, n);
	std :: cout << node[t].dis << std :: endl;
	return 0;
}