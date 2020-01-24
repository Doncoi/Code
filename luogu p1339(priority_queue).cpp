#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#define MAXN 1000000 + 5
#define INF 0x3f3f3f3

int n, m, s, t, cnt, ans;

struct Node {
	int dis, head;
	bool vis;
} node[MAXN];

struct Edge {
	int to, next, cost;
} edge[MAXN];

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

void init()
{
	n = read(), m = read(), s = read(), t = read();
	for(int i = 1; i <= m; ++ i)
	{
		int x = read(), y = read(), z = read();
		addEdge(x, y, z); addEdge(y, x, z);
	} 
}

void solve()
{
	std :: cout << Dijkstra() << std :: endl;
}

int main()
{
	init();
	solve();
	return 0;
}

/*
7 11 5 4

2 4 2

1 4 3

7 2 2

3 4 3

5 7 5

7 3 3

6 1 1

6 3 4

2 4 3

5 6 3

7 2 1
*/
