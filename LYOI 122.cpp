#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1005
#define MAXM 1000005
#define INF 0x7fffffff

int n, s, t, length, cnt;
int a[MAXN], f[MAXN], g[MAXN];
int q[MAXN], ql, qr;

struct Node {
	int head, visit, dis, cur;
} node[MAXN]; 

struct Edge {
	int from, to, next, flow, cap;
} edge[MAXM << 1];

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

void LIS() {
	for(int i = 1; i <= n; ++ i) g[i] = INF;
	for(int i = 1; i <= n; ++ i) {
		int k = std :: upper_bound(g + 1, g + 1 + n, a[i]) - g;
		f[i] = k, g[k] = a[i], length = std :: max(length, f[i]);
	}
}

inline void addEdge(int from, int to, int cap) {
	edge[++ cnt].to = to, edge[cnt].cap = cap, edge[cnt].flow = 0;
	edge[cnt].next = node[from].head, node[from].head = cnt;

	edge[++ cnt].to = from, edge[cnt].cap = 0, edge[cnt].flow = 0;
	edge[cnt].next = node[to].head, node[to].head = cnt;
}

void makeGraph() {
	cnt = 0;
	for(int i = 1; i < MAXN; ++ i) 
		node[i].head = 0;
	for(int i = 1; i <= n; ++ i) {
		if(f[i] == 1) addEdge(s, i, 1);
		addEdge(i, i + n, 1);
		if(f[i] == length) addEdge(i + n, t, 1);
		for(int j = 1; j < i; ++ j) 
			if(a[j] <= a[i] && f[j] + 1 == f[i]) 
				addEdge(j + n, i, 1);
	}
}

void makeGraphAgain() {
	cnt = 0;
	for(int i = 0; i < MAXN; ++ i) 
		node[i].head = 0;
	for(int i = 1; i <= n; ++ i) {
		if(i == 1 || i == n) {
			if(f[i] == 1) addEdge(s, i, INF);
			addEdge(i, i + n, INF);
			if(f[i] == length) addEdge(i + n, t, INF);
		} else {
			if(f[i] == 1) addEdge(s, i, 1);
			addEdge(i, i + n, 1);
			if(f[i] == length) addEdge(i + n, t, 1);
		}
		for(int j = 1; j < i; ++ j) 
			if(a[j] <= a[i] && f[j] + 1 == f[i])
				addEdge(j + n, i, 1);
	}
}

bool BFS() {
	for(int i = 1; i < MAXN; ++ i) 
		node[i].visit = node[i].dis = 0;
	ql = qr = 1;
	q[qr ++] = s, node[s].dis = 0, node[s].visit = 1;

	while(ql != qr) {
		int u = q[ql ++], v;
		for(int e = node[u].head; e; e = edge[e].next) 
			if(!node[v = edge[e].to].visit && edge[e].cap > edge[e].flow) {
				node[v].visit = 1, node[v].dis = node[u].dis + 1;
				q[qr ++] = v;  if(v == t) return true;
			}
	}

	return false;
}

int DFS(int x, int flow) {
	int u = x, v, maxFlow = 0, tmp;
	if(u == t || flow == 0) return flow;

	for(int &e = node[u].cur; e; e = edge[e].next) {
		if(node[v = edge[e].to].dis = node[u].dis + 1){
			tmp = DFS(v, std :: min(flow, edge[e].cap - edge[e].flow));
			if(tmp > 0) {
				maxFlow += tmp, flow -= tmp;
				edge[e].flow += tmp, edge[((e - 1) ^ 1) + 1].flow -= tmp;
				if(flow <= 0) break;
			}
		}
	}

	return maxFlow;
}

inline int Dinic() {
	int maxFlow = 0;
	while(BFS()) {
		for(int i = s; i <= t; ++ i) 
			node[i].cur = node[i].head;
		maxFlow += DFS(s, INF);
	}
	return maxFlow;
}

int main() {
	n = read(), s = 0, t = n + n + 1;
	for(int i = 1; i <= n; ++ i) a[i] = read();

	LIS();  printf("%d\n", length);
	if(length == 1) {printf("%d\n%d", n, n); return 0;}
	makeGraph();
	printf("%d\n", Dinic());
	makeGraphAgain();  printf("%d\n", Dinic());
}
