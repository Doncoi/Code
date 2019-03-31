#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 505
#define MAXM 300005
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
#define abs(x) x > 0 ? x : x*-1

const int delta[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

struct Node {
	int height;
	bool vis;
} node[MAXN][MAXN];

struct QueueNode {
	int x, y;
} q[MAXM], g[MAXN];

int n, m, pre;
int f[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void reset() {
	for(int i = 0; i < MAXN; ++ i) 
		for(int j = 0; j < MAXN; ++ j) 
			node[i][j].vis = false;
}

inline void BFS() {
	int ql = 0, qr = 0;
	for(int i = 1; i <= m; ++ i) {
		node[1][i].vis = true;
		q[++ qr].x = 1, q[qr].y = i;
	}
	while(ql < qr) {
		QueueNode u = q[++ ql], v;
		for(int i = 0; i < 4; ++ i) {
			v.x = u.x + delta[i][0], v.y = u.y + delta[i][1];
			if(v.x > n || v.x < 1 || v.y > m ||  v.y < 1) continue;
			if(node[u.x][u.y].height <= node[v.x][v.y].height) continue;
			if(node[v.x][v.y].vis) continue;
			node[v.x][v.y].vis = true, q[++ qr] = v;
		}
	}
}

inline void DFS(int x, int y) {
	node[x][y].vis = true;
	if(x == n) {
		g[pre].x = min(g[pre].x, y);
		g[pre].y = max(g[pre].y, y);
	}
	for(int i = 0; i < 4; ++ i) {
		int xx = x + delta[i][0];
		int yy = y + delta[i][1];
		if(xx > n || xx < 1 || yy > m || yy < 1) continue;
		if(node[x][y].height <= node[xx][yy].height) continue;
		if(!node[xx][yy].vis) DFS(xx, yy);
	}
}

inline void init() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j) 
			node[i][j].height = read();
	BFS();
}

inline void solve() {
	int res = 0;
	for(int i = 1; i <= m; ++ i) 
		if(!node[n][i].vis) ++ res;
	if(res) {
		printf("0\n%d\n", res);
		return;
	} else {
		printf("1\n");
		for(int i = 1; i <= m; ++ i) {
			reset();
			pre = i, g[pre].x = m + 1, g[pre].y = 0;
			DFS(1, i);
		}
	}
	f[0] = 0;
	for(int i = 1; i <= m; ++ i) {
		f[i] = 1 << 30;
		for(int j = 1; j <= m; ++ j)
			if(i >= g[j].x && i <= g[j].y)
				f[i] = min(f[i], f[g[j].x - 1] + 1);
	}
	printf("%d\n", f[m]);
}

int main() {
	init();
	solve();
}
