#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205
#define MAXM 405
#define INF 0x3f3f3f3f

int n, m, s, t, cnt;
int pre[MAXN];

struct Node {
	int level;
	int head;
} node[MAXN];

struct Edge {
	int next, to, cap;
} edge[MAXM];

inline void addEdge(int from, int to, int flow) {
	edge[++ cnt].next = node[from].head, node[from].head = cnt, edge[cnt].to = to, edge[cnt].cap = flow;
	edge[++ cnt].next = node[to].head, node[to].head = cnt, edge[cnt].to = from, edge[cnt].cap = 0;
}

inline bool bfs() {
	static int q[MAXN], len;
	int u, v;

	for(int i = s; i <= t; ++ i) {
		node[i].level = -1;
		pre[i] = node[i].head;
	}
	q[len = 1] = s, node[s].level = 0;
   
	for(int i = 1; i <= len; ++ i) {
		u = q[i];
		for(int e = node[u].head; e; e = edge[e].next) {
			if(edge[e].cap > 0 && node[v = edge[e].to].level == -1) {
				node[v].level = node[u].level + 1;
				q[++ len] = v;

				if(v == t) {
					return true;
				}
			}
		}
	}

	return false;
}

inline int Dinic(int u, int flow) {
	if(u == t) {
		return flow;
	}

	int res = 0, v, delta;
	for(int &e = pre[u]; e; e = edge[e].next) {
		if(edge[e].cap > 0 && node[u].level < node[v = edge[e].to].level) {
			delta = Dinic(v, std :: min(edge[e].cap, flow - res));
			if(delta) {
				edge[e].cap -= delta;
				edge[e ^ 1].cap += delta;
				res += delta;
				if(res == flow) {
					break;
				}
			}
		}
	}

	if(res != flow) {
		node[u].level = -1;
	}
	return res;
}

inline int maxFlow() {
	int ans = 0;
	while(bfs()) {
		ans += Dinic(s, INF);
	}

	return ans;
}

int main() {
	while(scanf("%d %d", &m, &n) != EOF) {
		cnt = 1, s = 1, t = n;
		for(int i = 1; i <= n; ++ i) {
	    	node[i].head = 0;
		}

		for(int i = 1; i <= m; ++ i) {
			int from, to, flow;
			scanf("%d %d %d", &from, &to, &flow);
			addEdge(from, to, flow);
		}

		printf("%d\n", maxFlow());
	}

	return 0;
}
