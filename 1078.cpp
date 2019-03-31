#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10005
#define MAXM 100005
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct Node {
	int father;
} node[MAXM];

struct Edge {
	int from, to, value;
} edge[MAXM];

int n, m, a[MAXN][MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline bool cmp(Edge a, Edge b) {
	return a.value < b.value;
}

inline int find(int x) {
	return (node[x].father == x) ? x : node[x].father = find(node[x].father);
}

int kruskal() {
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; ++ i)
		node[i].father = i;
	for(int e = 1; e <= m; ++ e) {
		int fx = find(edge[e].from);
		int fy = find(edge[e].to);
		if(fx != fy) {
			node[fy].father = fx;
			ans += edge[e].value, ++ cnt;
		}

		if(cnt == n - 1) 
			return ans;
	}
}

void init() {
	n = read();
	for(int i =1 ; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			a[i][j] = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			edge[++ m].from = i, edge[m].to = j,
			edge[m].value = a[i][j];
	std :: sort(edge + 1, edge + m + 1, cmp);
}

void solve() {
	printf("%d\n", kruskal());
}

int main() {
	init();
	solve();
}
