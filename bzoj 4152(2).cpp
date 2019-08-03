#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define MAXN 300000
#define INF 0x3f

int n, s, t;
int cnt = 0;

struct Point
{
	int k, x, y;
} point[MAXN];

struct Node {
	int dis, head;
	bool vis;
} node[MAXN];

struct Edge {
	int to, next, cost;
} edge[MAXN * 8];

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

int Dijkstra() {
	for(int i = 1; i <= n; ++ i) node[i].dis = INF;
	node[s].dis = 0; q.push(Dist(s, 0));

	while(!q.empty()) {
		Dist tmp = q.top(); q.pop();

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

inline bool cmp_1(const Point& a, const Point& b)
{
	return a.x < b.x;
}

inline bool cmp_2(const Point& a, const Point& b)
{
	return a.y < b.y;
}

int main()
{
	n = read(); s = 1, t = n;
	for(int i = 1; i <= n; ++ i)
	{
		point[i].k = i;
		point[i].x = read(), point[i].y = read();
	}

	std :: sort(point + 1, point + n + 1, cmp_1);
	for(int i = 2; i <= n; ++ i)
	{
		addEdge(point[i - 1].k, point[i].k, point[i].x - point[i - 1].x);
		addEdge(point[i].k, point[i - 1].k, point[i].x - point[i - 1].x);
	}
	std :: sort(point + 1, point + n + 1, cmp_2);
	for(int i = 2; i <= n; ++ i)
	{
		addEdge(point[i - 1].k, point[i].k, point[i].y - point[i - 1].y);
		addEdge(point[i].k, point[i - 1].k, point[i].y - point[i - 1].y);
	}

	std :: cout << Dijkstra() << std :: endl;
}
