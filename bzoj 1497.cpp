#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 60005
#define MAXM 320005
#define INF 0x7fffffff

struct Node {
	int dep, pre, head;
} node[MAXN];

struct Edge {
	int to, next, flow;
} edge[MAXM];

int n, m, s, t, cnt = 1, ans = 0;
std :: queue<int> q;

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void addEdge(int from, int to, int flow) {
	edge[++ cnt].next = node[from].head, node[from].head = cnt;
	edge[cnt].to = to; edge[cnt].flow = flow;

	edge[++ cnt].next = node[to].head, node[to].head = cnt;
	edge[cnt].to = from, edge[cnt].flow = 0;
}

inline bool BFS(int x) {
	int u = x, v;
	for(int i = 0; i < MAXN; ++ i) 
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

inline void init() {
	n = read(), m = read();
	s = n + m + 1, t = s + 1;
	for(int i = 1; i <= n; ++ i) 
		addEdge(i + m, t, read());
	for(int i = 1; i <= m; ++ i) {
		int x = read(), y = read(), z = read();
		ans += z;
		addEdge(s, i, z), addEdge(i, x + m, INF), addEdge(i, y + m, INF);
	}
}

inline void solve() {
	ans -= Dinic();
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
