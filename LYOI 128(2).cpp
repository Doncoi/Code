//运输问题
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 205
#define MAXM 40005
#define INF 0x7fffffff

int n, m, s, t, cnt;
int a[MAXN], b[MAXN], cost[MAXN][MAXN];

struct Node {
	int head, pre, dis;
	bool vis;
} node[MAXN];

struct Edge {
	int from, to, next;
	int flow, cost;
} edge[MAXM];

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void addEdge(int from, int to, int flow, int cost) {
	edge[cnt].from = from, edge[cnt].to = to, edge[cnt].flow = flow, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt ++;

	edge[cnt].from = to, edge[cnt].to = from, edge[cnt].flow = 0, edge[cnt].cost = -cost;
	edge[cnt].next = node[to].head, node[to].head = cnt ++;
}

inline bool SPFA() {
	for(int i = 0; i < MAXN; ++ i) {
		node[i].vis = false;
		node[i].dis = INF, node[i].pre = -1;
	}

	std :: queue<int> q;
	q.push(s), node[s].vis = true, node[s].dis = 0;

	while(!q.empty()) {
		int u = q.front(), v;  q.pop(), node[u].vis = false;

		for(int e = node[u].head; e != -1; e = edge[e].next) 
			if(edge[e].flow > 0 && node[v = edge[e].to].dis > node[u].dis + edge[e].cost) {
				node[v].dis = node[u].dis + edge[e].cost, node[v].pre = e;
				if(!node[v].vis) node[v].vis = true, q.push(v);
			}
	} 
	
	return node[t].dis < INF;
}

inline void init() {
	for(int i = 0; i < MAXN; ++ i) 
		node[i].head = -1;
	s = 0, t = MAXN - 1, cnt = 0;

	m = read(), n = read();
	for(int i = 1; i <= m; ++ i) 
		addEdge(s, i, read(), 0);
	for(int i = 1; i <= n; ++ i) 
		addEdge(i + m, t, read(), 0);
	for(int i = 1; i <= m; ++ i) 
		for(int j = 1; j <= n; ++ j) 
			addEdge(i, j, INF, read());
}

inline void solve() {
	int ans = 0, maxFlow = INF;
	while(SPFA()) {
		for(int e = t; e != s; e = edge[node[e].pre].from) 
			maxFlow = std :: min(maxFlow, edge[node[e].pre].flow);
		for(int e = t; e != s; e = edge[node[e].pre].from) 
			edge[node[e].pre].flow -= maxFlow, edge[node[e].pre].flow += maxFlow;
		ans += maxFlow * node[t].dis;
	}

	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}