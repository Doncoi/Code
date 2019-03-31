#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 11
#define MAXM 1 <<15
#define INF 0x7fffffff

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Node {
	int x, y, z;

	Node(int _x = 0, int _y = 0, int _z = 0) {
		x = _x, y = _y, z = _z;
	}
}; 

int n, m, k, w;
int a[MAXN][MAXN][MAXN][MAXM];
int key[MAXN][MAXN];
int dis[MAXN][MAXN][MAXM];
bool vis[MAXN][MAXN][MAXM];
std :: queue<int> q;

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline bool check(int x, int y) {
	return (x > 0 && y > 0 && x <= n && y <= m);
}

int main() {
	n = read(), m = read(), k = read();
	for(int i = 1, b, c, d, e, f; i <= k; ++ i) {
		b = read(), c = read(), d = read(), e = read(), f = read();
		if(!f) a[d][e][b][c] = a[b][c][d][e] - 1;
		else a[d][e][b][c] = a[b][c][d][e] |= 1 << f;
	}
	w = read();
	for(int i = 1, b, c, d; i <= w; ++ i) 
		b = read(), c = read(), d = read(), key[b][c] |= 1 << d;

	memset(dis, 0, sizeof(dis));
	dis[1][1][0] = 0;
	q.push(Node(1, 1, 0));
	Node pre;  int ans = INF;
	while(!q.empty()) {
		pre = q.front(), q.pop(), vis[pre.x][pre.y][pre.z] = false;
		for(int i = 0, p, q, r; i < 4; ++ i) {
			p = pre.x + dx[i], q = pre.y + dy[i];
			if(check(p, q)) 
				if(dis[p][q][pre.z] > dis[pre.x][pre.y][pre.z] + 1)
					if(a[p][q][pre.x][pre.y] != -1)
						if((pre.z & a[p][q][pre.x][pre.y]) == a[p][q][pre.x][pre.y]) 
							if(!vis[p][q][pre.z | key[p][q]]) 
								vis[p][q][pre.z | key[p][q]] = true, 
								q.push(Node(p, q, pre.z | key[p][q]));
		}
	}
	
	for(int i = 0; i < (1 << (w + 1)); ++ i)
		ans = std :: min(ans, dis[n][m][i]);
	(ans == INF) ? printf("-1\n") : printf("%d\n", ans);
}