#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define abs(a) a > 0 ? a : (a * -1)
#define MAXN 1005

struct Node {
	int x, y;
} node[MAXN];

struct Edge {
	int from, to, value;
} edge[MAXN * MAXN];

int n, m, tot, cnt, ID = 0;
int hash[MAXN][MAXN], t[MAXN];
char c[MAXN][MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch - '0'; ch = getchar();}
	return res * flag;
}

inline int len(int x1, int y1, int x2, int y2) {
	if(abs(x1 - x2) < 2) return abs(y1 - y2) - 1;
	if(abs(y1 - y2) < 2) return abs(x1 - x2) - 1;
	return MAXN;
}

inline int find(int x) {
	printf("Find Successfull\n");
	if(t[x] == -1 || t[x] == x) return x;
	else return t[x] == find(t[x]);
}

inline void addEdge(int x1, int y1, int x2, int y2) {
	printf("All Right\n");
	edge[++ cnt].from = hash[x1][y1], edge[cnt].to = hash[x2][y2], edge[cnt].value = len(x1, y1, x2, y2);
}
inline bool cmp(const Edge &a, const Edge &b) {
	return a.value > b.value;
}

inline void floodFill(int x, int y, int ID) {
	if(x < 1 || y < 1 || x > n || y > m || hash[x][y] || c[x][y] == '.') return;
	hash[x][y] = ID;
	if(x < n) floodFill(x + 1, y, ID);
	if(y < m) floodFill(x, y + 1, ID);
	if(x > 1) floodFill(x - 1, y, ID);
	if(y > 1) floodFill(x, y - 1, ID);
	if(x < n && y < m) floodFill(x + 1, y + 1, ID);
	if(x < n && y > 1) floodFill(x + 1, y - 1, ID);
	if(x > 1 && y > 1) floodFill(x - 1, y - 1, ID);
	if(x > 1 && y < m) floodFill(x - 1, y + 1, ID);
}

inline void kruskal() {
	std :: sort(edge + 1, edge + cnt + 1, cmp);
	int u, v, k = 0, cost = 0, e = 1;
	printf("All Kill\n");
	while(e <= cnt) {
		u = find(edge[e].from), v = find(edge[e].to);
		if(u != v) 
			cost += edge[e].value, ++ k, t[u] = v; 
		++ e;
	}
	printf("%d %d\n", k, cost);
}

inline void init() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> c[i][j];
			if(c[i][j] == '#') 
				++ tot, node[tot].x = i, node[tot].y = j;
		}
}

inline void solve() {
	memset(hash, 0, sizeof(hash));
	memset(t, -1, sizeof(t));
	for(int i = 1; i <= tot; ++ i) 
		if(!hash[node[i].x][node[i].y])
			floodFill(node[i].x, node[i].y, ++ ID);
	printf("%d\n", ID);
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m; ++ j)
			for(int k = 1 ; k <= n; ++ k)
				for(int l = 1; l <= m; ++ l)
					if(hash[i][j] && hash[k][l] && !(i == k && j == l) && hash[i][j] != hash[k][l])
						addEdge(i, j, k, l);
	kruskal();
}

int main() {
	init();
	solve();
}
