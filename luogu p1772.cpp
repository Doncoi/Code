#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000 + 5
#define MAXM 200 + 5
#define INF 2147483647
using namespace std;

int n, m, K, E, d;
int s, t, cnt = 0, ans = 0;
int f[MAXN];
bool cot[MAXN][MAXM] = {false};
bool block[MAXM] = {false};

struct Node 
{
	int dis, head;
	bool vis;
} node[MAXM];

struct Edge 
{
	int to, next, cost;
} edge[MAXM * MAXM * 2];

struct Dist 
{
	int dist, x;

	Dist(int x = 0, int dist = INF) : dist(dist), x(x) {}
	bool operator () (Dist l, Dist r) 
	{
		return l.dist > r.dist;
	}
};

std :: priority_queue<Dist, std :: vector<Dist>, Dist> q;
 
inline int min(int a, int b) 
{
	return (a < b ? a : b);
}

inline int read() 
{
	char ch = getchar(); int res = 0;
	while( ch < '0' || ch > '9' ) ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void addEdge(int from, int to, int cost) 
{
	edge[++ cnt].to = to, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt;
}

inline int Dijkstra() 
{
	for(int i = 1; i <= n; ++ i) node[i].dis = INF;
	node[s].dis = 0; q.push(Dist(s, 0));

	while(!q.empty()) 
	{
		Dist tmp = q.top(); q.pop();

		int u = tmp.x, d = node[u].dis;
		if(tmp.dist != d) continue; 
		for(int e = node[u].head, v; e; e = edge[e].next) 
		{
			if(node[v = edge[e].to].dis <= d + edge[e].cost || block[v]) continue;
			node[v].dis = d + edge[e].cost;
			q.push(Dist(v, node[v].dis)); 
		}
	}

	return node[t].dis;
}

void init()
{
	n = read(), m = read(), K = read(), E = read();
	int x, y, z;
	for(int i = 1; i <= E; ++ i)
	{
		x = read(), y = read(), z = read();
		addEdge(x, y, z), addEdge(y, x, z);
	}
	d = read();
	for(int i = 1; i <= d; ++ i)
	{
		x = read(), y = read(), z = read();
		for(int j = y; j <= z; ++ j)
			cot[j][x] = true;
	}
	
	s = 1, t = n, f[0] = K * -1;
	for(int i = 1; i <= n; ++ i)
		f[i] = INF;
//	for(int j = 1; j <= m; ++ j)
//	{
//		for(int i = 1; i <= n; ++ i)
//		{
//			if(cot[i][j]) cout << "--";
//			else cout << "  ";		
//		}
//		cout << endl;
//	} 
}

void solve()
{
	for(int i = 1; i <= n; ++ i)
	{
		memset(block, false, sizeof(block));
		for(int j = i; j >= 1; -- j)
		{
			for(int k = 1; k <= m; ++ k)
			{
				if(cot[j][k]) block[k] = true;
			}

			int min_dis = Dijkstra();
			//cout << "(" << j << " ," << i << ") = " << min_dis << endl; 
			if(min_dis >= INF) break;
			//cout << i << ": " << f[i] << " " << (i - j + 1) << " " << min_dis << " " << (i - j + 1) * min_dis << endl;
			f[i] = min(f[i], f[j - 1] + (i - j + 1) * min_dis + K); 
		}
	}

	cout << f[n] << endl;
}

int main()
{
	init();
	solve();
}
