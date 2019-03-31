#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 45
#define MAXM 805
#define INF 0x7fffffff

int n, m, s, t, cnt, tot, ans;
int map[MAXN][MAXN], num[MAXN][MAXN];

struct Node {
	int head, dep, pre[2];
	bool vis;
} node[MAXM];

struct Edge {
	int to, next, flow, cost;
	
	Edge(int from ,int to, int flow, int cost) : 
	to(to), flow(flow), cost(cost), next(node[from].head){
		node[from].head = cnt ++;
	}
};

std :: vector<Edge> edge;

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void addEdge(int from, int to, int flow, int cost) {
	edge.push_back(Edge(from, to, flow, cost));
	edge.push_back(Edge(to, from, 0, -cost));
}

inline void reset() {
	cnt = 0; edge.clear();
	for(int i = 0; i < MAXM; ++ i)
		node[i].head = -1;
}

inline void init() {
	m = read(), n = read();
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j < (i + m); ++ j) 
			map[i][j] = read(), num[i][j] = ++ tot;
}

inline bool SPFA() {
	for(int i = 0; i < MAXM; ++ i) 
		node[i].vis = false, node[i].dep = -INF;
	std :: queue<int> q;
	q.push(s), node[s].dep = 0, node[s].vis = true;

	while(!q.empty()) {
		int u = q.front(), v;  q.pop(), node[u].vis = false;
		for(int e = node[u].head; e != -1; e = edge[e].next) 
			if(edge[e].flow && node[v = edge[e].to].dep < node[u].dep + edge[e].cost) {
				node[v].dep = node[u].dep + edge[e].cost;
				node[v].pre[0] = e, node[v].pre[1] = u;
				if(!node[v].vis) q.push(v), node[v].vis = true;
			}
	}

	return node[t].dep != -INF;
}	

inline int MCMF() {
	int ans = 0, maxFlow;
	while(SPFA()) {
		maxFlow = INF;
		for(int e = t; e != s; e = node[e].pre[1])
			maxFlow = std :: min(maxFlow, edge[node[e].pre[0]].flow);
			
		for(int e = t; e != s; e = node[e].pre[1]) {
			edge[node[e].pre[0]].flow -= maxFlow;
			edge[node[e].pre[0] ^ 1].flow += maxFlow;
		}
		ans += node[t].dep * maxFlow;
	}

	return ans;
}

inline void makeGraphA() {
	reset();
	t = tot * 2 + 1;
	for(int i = 1; i <= m; ++ i) 
		addEdge(s, i, 1, 0);
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j < (i + m); ++ j)  
			addEdge(num[i][j], num[i][j] + tot, 1, map[i][j]);
	for(int i = 1; i < n; ++ i) 
		for(int j = 1; j < (i + m); ++ j) 
			addEdge(num[i][j] + tot, num[i + 1][j], 1, 0), 
			addEdge(num[i][j] + tot, num[i + 1][j + 1], 1, 0);
	for(int i = 1; i < (n + m); ++ i) 
		addEdge(num[n][i] + tot, t, 1, 0);
}

inline void makeGraphB() {
	reset();
	t = tot + 1;
	for(int i = 1; i <= m; ++ i)
		addEdge(s, i, 1, 0);
	for(int i = 1; i < n; ++ i) 
		for(int j = 1; j < (m + i); ++ j)
			addEdge(num[i][j], num[i + 1][j], 1, map[i][j]),
			addEdge(num[i][j], num[i + 1][j + 1], 1, map[i][j]);
	for(int i = 1; i < (n + m); ++ i) 
		addEdge(num[n][i], t, INF, map[n][i]);
}

inline void makeGraphC() {
	for(int i = 0; i < 2 * m; i += 2) 
		edge[i].flow = 1, edge[i + 1].flow = 0;
	for(int i = 2 * m; i < cnt; i += 2) 
		edge[i].flow = INF, edge[i + 1].flow = 0;
}

inline void solve() {
	makeGraphA();
	printf("%d\n", MCMF());
	makeGraphB();
	printf("%d\n", MCMF());
	makeGraphC();
	printf("%d\n", MCMF());
}

int main() {
	init();
	solve();
}
