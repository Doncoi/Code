#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5
#define MAXM 10000 + 5
#define INF 0x3f3f3f3f

using namespace std;

int n, m, d, s, t, cnt, ans;
int u[MAXM], v[MAXM], w[MAXM];
bool damaged[MAXM];

struct Node {
	int dis, head;
	bool vis;
} node[MAXN];

struct Edge {
	int to, next, cost;
} edge[MAXM];

struct Dist {
	int dist, x;

	Dist(int x = 0, int dist = INF) : dist(dist), x(x) {}
	bool operator () (Dist l, Dist r) {
		return l.dist > r.dist;
	}
};

std :: priority_queue<Dist, std :: vector<Dist>, Dist> q;
 
inline int min(int a, int b) {
	return (a < b ? a : b);
}

inline int read() {
	char ch = getchar(); int res = 0;
	while( ch < '0' || ch > '9' ) ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void addEdge(int from, int to, int cost) {
	edge[++ cnt].to = to, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt;
}

inline int Dijkstra() {
	for(int i = 1; i <= n; ++ i) node[i].dis = INF;
	node[s].dis = 0; q.push(Dist(s, 0));

	while(!q.empty()) {
		Dist tmp = q.top(); 
		q.pop();

		int u = tmp.x, d = node[u].dis;
		if(tmp.dist != d) continue;
		for(int e = node[u].head, v; e; e = edge[e].next) {
			if(node[v = edge[e].to].dis <= d + edge[e].cost) continue;
			node[v].dis = d + edge[e].cost;
			q.push(Dist(v, node[v].dis)); 
		}
	}

	return node[t].dis;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i)
	{
		u[i] = read(), v[i] = read(), w[i] = read();
	}
	d = read();
	for(int i = 1; i <= d; ++ i)
	{
		u[0] = read(), v[0] = read();
		for(int j = 1; j <= m; ++ j)
		{
			if((u[j] == u[0]) && (v[j] == v[0]))
			{
				damaged[j] = true; break;
			}
			if((u[j] == v[0]) && (v[j] == u[0]))
			{
				damaged[j] = true; break;
			}
		}
	}
	s = read(), t = read();

	for(int i = 1; i <= m; ++ i)
	{
		if(! damaged[i])
			addEdge(u[i], v[i], 0), addEdge(v[i], u[i], 0);
		else
			addEdge(u[i], v[i], w[i]), addEdge(v[i], u[i], w[i]);
	}

	cout << Dijkstra() << endl;
	return 0;
}
