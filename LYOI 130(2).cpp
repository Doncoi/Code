//
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205
#define MAXM 20005
#define INF 0x7fffffff

int n, sum, s, t, cnt, ans;
int a[MAXN];
std :: queue<int> q;

struct Node {
	int dis, pre, head;
	bool vis;
} node[MAXN];

struct Edge {
	int from, to, next;
	int flow, cost;
} edge[MAXM];

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar(); }
	return res;
}

inline void addEdge(int from, int to, int flow, int cost) {
	edge[cnt].from = from, edge[cnt].to = to;
	edge[cnt].flow = flow, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt ++;

	edge[cnt].from = to, edge[cnt].to = from;
    edge[cnt].flow = 0, edge[cnt].cost = -cost;
	edge[cnt].next = node[to].head, node[to].head = cnt ++;
	
	printf("(%d, %d, %d, %d, %d)\n", from, to, flow, cost, edge[cnt - 2].next); 
}

inline void init() {
	n = read(), s = 0, t = n + n + 1, ans = sum = cnt = 0;
	for(int i = 1; i <= n; ++ i) 
		a[i] = read(), sum += a[i];
	sum /= n;

	for(int i = 1; i <= n; ++ i) 
		addEdge(s, i, a[i], 0), addEdge(i + n, t, sum, 0), addEdge(i, i + n, INF, 0);
	for(int i = 1; i < n; ++ i) 
		addEdge(i + n, i + 1, INF, 1);
	for(int i = 2; i <= n; ++ i) 
		addEdge(i + n, i - 1, INF, 1);

	addEdge(n + n, 1, INF, 1), addEdge(n + 1, n, INF, 1);
}

inline bool SPFA() {
	for(int i = s; i <= t; ++ i) 
		node[i].dis = INF;
	int q[MAXN], l = 0, r = 1;
	q[1] = 0, node[0].dis = 0, node[0].vis = true;

	while(l < r) {
		for(int e = node[q[++ l]].head; e; e = edge[e].next) 
			if(edge[e].flow && node[q[l]].dis + edge[e].cost < node[edge[e].to].dis) {
				node[edge[e].to].dis = node[q[l]].dis + edge[e].cost, node[edge[e].to].pre = e;
				if(!node[edge[e].to].vis) q[++ r] = edge[e].to, node[edge[e].to].vis = true;
			} 

		node[q[l]].vis = false;
	}

	if(node[t].dis == INF) return false;

	int maxFlow = INF;
	for(int e = node[t].pre; e; e = node[edge[e].from].pre) maxFlow = std :: min(maxFlow, edge[e].flow);
	for(int e = node[t].pre; e; e = node[edge[e].from].pre) edge[e].flow -= maxFlow, edge[e ^ 1].flow += maxFlow;
	ans += node[t].dis * maxFlow;

	return true;
} 

int main() {
	init();
	while(SPFA());
	printf("%d\n", ans);
}