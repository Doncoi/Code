#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 2005
#define MAXM 4000005
#define INF 0x7fffffff

int n, P, M, F, N, S;
int s, t, cnt, ans; 
std :: queue<int> q;

struct Node {
	int head, dep, pre;
	int visited;
} node[MAXN];

struct Edge {
	int from, to, next;
	int flow, cost;
} edge[MAXM];

inline int read() {
	int res = 0;  char ch = getchar();
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
		node[i].visited = false;
		node[i].dep = INF, node[i].pre = -1;
	}

	q.push(s);  node[s].visited = true, node[s].dep = 0;
	while(!q.empty()) {
		int u = q.front(), v;  q.pop(); node[u].visited = false;

		for(int e = node[u].head; e != -1; e = edge[e].next) 
			if(edge[e].flow > 0 && node[v = edge[e].to].dep > node[u].dep + edge[e].cost) {
				node[v].dep = node[u].dep + edge[e].cost, node[v].pre = e;
				if(!node[v].visited) node[v].visited = true, q.push(v);
			}
	}
	return node[t].dep < INF;
}
 
inline void solve() {
	while(SPFA()) {
		int maxFlow = INF;
		for(int e = t; e != s; e = edge[node[e].pre].from) 
			maxFlow = std :: min(maxFlow, edge[node[e].pre].flow);
		for(int e = t; e != s; e = edge[node[e].pre].from) {
			ans += edge[node[e].pre].cost * maxFlow;
			edge[node[e].pre].flow -= maxFlow, edge[node[e].pre ^ 1].flow += maxFlow;
		}
	}

	printf("%d\n", ans);
}

inline void makeGraph() {
	s = 0, t = MAXN - 1;
	for(int i = 0; i < MAXN; ++ i) node[i].head = -1;
	n = read(), P = read(), M = read(), F = read(), N = read(), S = read();

	for(int i = 1; i <= n; ++ i) {
		int tmp = read();
		addEdge(s, i, tmp, 0);
		addEdge(i + n, t, tmp, 0);
		if(i + 1 <= n) addEdge(i, i + 1, INF, 0);
		if(i + n + M <= n * 2) addEdge(i, i + n + M, INF, F);
		if(i + n + N <= n * 2) addEdge(i, i + n + N, INF, S);
		addEdge(s, i + n, INF, P);
	}
}

int main() {
	makeGraph();
	solve();
}