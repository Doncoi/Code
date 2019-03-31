#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 4005
#define MAXM 40000005
#define INF 0x7fffffff

int n, m, k, s, t, cnt, ans, sum = 2, add;
std :: queue<int> q;
std :: vector<int> num[110];

struct Ship {
	int capacity, landSum, land[MAXN];
} ship[15];

struct Node {
	int head, pre, pos, dis;
	bool vis;
} node[MAXN];

struct Edge {
	int from, to, next;
	int cap, flow, brother;
} edge[MAXM];

inline int read() {
	char ch = getchar();  int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

inline void addEdge(int from, int to, int flow) {
    edge[cnt].flow = flow, edge[cnt].brother = cnt + 1;
	edge[cnt].from = from, edge[cnt].to = to;
	edge[cnt].next = node[from].head, node[from].head = cnt ++;

	edge[cnt].flow = 0, edge[cnt].brother = cnt - 1;
	edge[cnt].from = to, edge[cnt].to = from;
	edge[cnt].next = node[to].head, node[to].head = cnt ++;
};

inline bool BFS() {
	while(q.empty()) q.pop();
	for(int i = 0; i < MAXN; ++ i) node[i].dis = -1;
	q.push(s), node[s].dis = 0;
	while(!q.empty()) {
		int u = q.front(), v;  q.pop();
		for(int e = node[u].head; e; e = edge[e].next) 
			if(edge[e].flow > 0 && node[v = edge[e].to].dis == -1) 
				node[v].dis = node[u].dis + 1, q.push(v);
	}

	return node[t].dis != -1;
}

int DFS(int x, int flow) {
	int u = x, v, maxFlow, pre = 0;
	if(u == t) return flow;
	for(int e = node[u].head; e; e = edge[e].next) {
		if(edge[e].flow > 0 && node[v = edge[e].to].dis == node[u].dis + 1) {
			maxFlow = DFS(v, std :: min(flow - pre, edge[e].flow));
			edge[e].flow -= maxFlow, edge[edge[e].brother].flow += maxFlow, pre += maxFlow;
		}
		if(pre == flow) break;	
	}

	if(pre == 0) node[u].dis = -1;
	return pre;
}

inline int maxFlow() {
	while(BFS()) 
		ans += DFS(s, INF);
	return ans;
}

inline bool check(int x) {
	for(int i = 1; i <= n; ++ i) num[i].push_back(++ sum);
	num[0].push_back(1), num[n + 1].push_back(2);
	for(int i = 1; i <= m; ++ i) {
		int y = ship[i].land[(x - 1) % ship[i].landSum + 1], z = ship[i].land[x % (ship[i].landSum) + 1];
		if(!z || y == n + 1) continue;
		y = num[y][x], z = num[z][x + 1];
		addEdge(y, z, ship[i].capacity);
	}
	for(int i = 1; i <= n; ++ i) 
		addEdge(num[i][x], num[i][x + 1], INF);
	add += maxFlow();
	return add >= k;
}

inline void init() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++ i) {
		ship[i].capacity = read(), ship[i].landSum = read();
		for(int j = 1; j <= ship[i].landSum; j ++) {
			ship[i].land[j] = read();
			if(ship[i].land[j] == -1) ship[i].land[j] = n + 1;
		}
	}

	for(int i = 1; i <= m; ++ i) num[i].clear();
	for(int i = 0; i <= n + 1; ++ i) num[i].push_back(0);
	ans = 0, s = 1, t = 2;
	for(int i = 1; i <= n; ++ i) num[i].push_back(++ sum);
	num[0].push_back(1), num[n + 1].push_back(2), add = 0;
}

int main() {
	init();
	while(true) {
		ans ++;
		if(check(ans)) { printf("%d\n", ans); break;}
		if(ans > 100) {printf("0\n"); break;}
	}
}