#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 610
#define MAXM 600010
#define MAXP 2000000
#define INF 0x3f3f3f3f
#define limit -100000000000000ll

struct Sum {
	int a, b, k; 
	long long c;
} sum[MAXN];

struct Node {
	int head, pre, flow;
	long long dis;
	bool vis;
} node[MAXN];
 
struct Edge {
	int from, to, next, cap;
	long long cost;
} edge[MAXM << 1];

int n, s, t, cnt = 1, res = 0, ans;
int q[MAXM * 4], ql, qr; 

template<typename type> 
inline type min(type a, type b) {
	return (a < b ? a : b);
}

template<typename type> 
inline void read(type &x) {
	char ch = getchar(); int flag = 1; type res = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	x = (res * flag);
}

inline void addEdge(int from, int to, long long cost, int cap) {
	edge[++ cnt].from = from, edge[cnt].to = to, edge[cnt].cap = cap;
	edge[cnt].cost = cost, edge[cnt].next = node[from].head, node[from].head = cnt;

	edge[++ cnt].from = to, edge[cnt].to = from, edge[cnt].cap = 0;
	edge[cnt].cost = -cost, edge[cnt].next = node[to].head, node[to].head = cnt;
} 

inline void divide(int x) {
	int a = sum[x].a, b;
	sum[x].k  = 0, b = std :: sqrt(a);
	for(int i  = 2; i <= std :: sqrt(a); ++ i) 
		while(!(a % i)) a /= i, sum[x].k ++;
	if(a > 1) sum[x].k ++;
}

inline bool SPFA() {
	for(int  i = s; i <= t; ++ i) 
		node[i].vis = false, node[i].dis = limit;
	q[ql = 0] = s, qr = 1;
	node[s].dis = 0ll, node[s].flow = INF, node[s].vis = true;

	while(ql < qr) {
		int u = q[ql % MAXP]; ++ ql, node[u].vis = false;
		for(int e = node[u].head, v; e; e = edge[e].next) {
			if(edge[e].cap <= 0 || node[v = edge[e].to].dis >= node[u].dis + edge[e].cost) continue;
			node[v].dis = node[u].dis + edge[e].cost, node[v].pre = e;
			node[v].flow = min(node[u].flow, edge[e].cap);
			if(!node[v].vis) q[qr % MAXP] = v, ++ qr, node[v].vis = 1;
		}
	}

	return node[t].dis > limit;
}

inline void init() {
	read(n), s = 0, t = n + 1;
	for(int i = 1; i <= n; ++ i) read(sum[i].a);
	for(int i = 1; i <= n; ++ i) read(sum[i].b);
	for(int i = 1; i <= n; ++ i) read(sum[i].c);

	for(int i = 1; i <= n; ++ i) {
		divide(i);
		if(sum[i].k & 1) addEdge(s, i, 0, sum[i].b);
		else addEdge(i, t, 0, sum[i].b);
	}
	for(int i = 1; i <= n; ++ i) {
		if(!(sum[i].k & 1)) continue;
		for(int j = 1; j <= n; ++ j) {
            if(!(sum[i].a % sum[j].a) && sum[i].k == sum[j].k + 1)
            	addEdge(i, j, sum[i].c * sum[j].k, INF);
            if(!(sum[j].a % sum[i].a) && sum[j].k == sum[i].k + 1)
            	addEdge(i, j, sum[i].k * sum[j].k, INF);
		}
	}
}

inline void solve() {
	while(SPFA()) {
		if((sum + node[t].dis * node[t].flow) < 0) {
			ans += (int)(res / (node[t].dis * -1)); break;
		} else {
			for(int i = t; i != s; i = edge[node[i].pre].from) {
				edge[node[i].pre].cap -= node[t].flow;
				edge[node[i].pre ^ 1].cap += node[t].flow;
			}
			ans += node[t].flow, res += node[t].dis * node[t].flow;
		}
	}

	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
