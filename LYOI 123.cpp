#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAXN 25
#define MAXM 1005
#define INF 0x7fffffff

struct Node {
	int dep, pre, head;
} node[MAXN + MAXM];

struct Edge {
	int to, next, flow;
} edge[MAXN * MAXM * 2];

int n, m, s, t, sum ,cnt = 1;
int a[MAXM];
std :: queue<int> q;

inline void addEdge(int from, int to, int flow) {
	edge[++ cnt].next = node[from].head, node[from].head = cnt;
	edge[cnt].to = to; edge[cnt].flow = flow;

	edge[++ cnt].next = node[to].head, node[to].head = cnt;
	edge[cnt].to = from, edge[cnt].flow = 0;
}

inline bool BFS(int x) {
	int u = x, v;
	for(int i = 0; i < (MAXN + MAXM); ++ i) 
		node[i].dep = 0;
	q.push(u), node[u].dep = 1;

	while(!q.empty()) {
		u = q.front();   q.pop();
		for(int e = node[u].head; e; e = edge[e].next) 
			if(edge[e].flow > 0 && !node[v = edge[e].to].dep) 		
				q.push(v), node[v].dep = node[u].dep + 1;
	}

	return node[t].dep;
}

int DFS(int x, int flow) {
	int res = 0, u = x, v, tmp;
	if(u == t) return flow;
	for(int e = node[u].head; e && flow; e = edge[e].next) 
		if(edge[e].flow > 0 && node[v = edge[e].to].dep > node[u].dep) {
			tmp = DFS(v, std :: min(flow, edge[e].flow));
			res += tmp, flow -= tmp, edge[e].flow -= tmp, edge[e ^ 1].flow += tmp;
		}

	return res;	
}

inline int Dinic() {
	int maxFlow = 0;
	while(BFS(s)) 
		maxFlow += DFS(s, MAXM);
	return maxFlow;
}

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void solve() {
	m = read(), n = read();
	s = 0, t = n + m + 1;
	for(int i = 1; i <= m; ++ i) {
		a[i] = read();
		addEdge(s, i, a[i]); 
		sum += a[i]; 
	}
	for(int i = 1; i <= n; ++ i) {
		int k = read();
		while(k --) 
			addEdge(read(), i + m, 1);
		addEdge(i + m, t, 1);
	}

	if(Dinic() != sum) printf("No Solution!\n");
	else {
		for(int i = 1; i <= m; ++ i) {
			printf("%d: ", i);
			for(int e = node[i].head; e; e = edge[e].next) 
				if(!edge[e].flow && !(e & 1)) 
					printf("%d ", edge[e].to - m);
			printf("\n");	
		}
	}
}

int main() {
	solve();
	return 0;
}
