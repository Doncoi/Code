#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAXN 105
#define INF 0x7fffffff
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, cnt, uppoint, s, t, A, B;
int T[MAXN];
double mDis, minn;
double dis[MAXN * 4][MAXN * 4];

struct Node {
	int x, y;
	int pos, vis;
} node[MAXN * 4];

struct Edge {
	double len;
	int to;
} edge[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline double getDis(int x1, int y1, int x2, int y2) {
	double dis;
	dis = std :: sqrt(abs(x1 - x2) * abs(x1 - x2) + 
					  abs(y1 - y2) * abs(y1 - y2));
	return dis;
}

inline void createHeap(int son) {
	int father = son >> 1;
	if(!father) return;
	if(edge[son].len < edge[father].len) {
		std :: swap(node[edge[son].to].pos, node[edge[father].to].pos);
		std :: swap(edge[son], edge[father]);
		createHeap(father);
	}
}

inline void deleteHeap(int father) {
	int son = father << 1;
	if(son > cnt) return;
	if((son + 1 <= cnt) && (edge[son + 1].len < edge[son].len)) ++ son;
	if(edge[son].len < edge[father].len) {
		std :: swap(node[edge[son].to].pos, node[edge[father].to].pos);
		std :: swap(edge[son], edge[father]);
		deleteHeap(son);
	}
}

void dijkstra(int k) {
	cnt = 0;
	for(int i = 1; i <= s * 4; ++ i) {
		edge[++ cnt].to = i, edge[cnt].len = dis[k][i];
		node[i].pos = i, createHeap(cnt), node[i].vis = false;
	}

	while(1) {
		if((edge[1].to >= B * 4 - 3) && (edge[1].to <= B * 4)){
			node[edge[1].to].vis = true, mDis = edge[1].len;
			minn = min(minn, mDis), uppoint = edge[1].to;
			std :: swap(node[edge[1].to].pos, node[edge[cnt].to].pos);
			std :: swap(edge[1], edge[cnt]);
			-- cnt, deleteHeap(1);
		} else {
			node[edge[1].to].vis = true;
			mDis = edge[1].len, uppoint = edge[1].to;
			std :: swap(node[edge[1].to].pos, node[edge[cnt].to].pos);
			std :: swap(edge[1], edge[cnt]);
			-- cnt, deleteHeap(1);
		}

		if(!cnt) break;
		for(int i = 1; i <= s * 4; ++ i) 
			if(!node[i].vis && (mDis + dis[uppoint][i] < edge[node[i].pos].len)) {
				edge[node[i].pos].len = mDis + dis[uppoint][i];
				createHeap(node[i].pos);
			}
	}
}

void init() {
	minn = INF, s = read(), t = read(), A = read(), B = read();
	for(int i = 1; i <= s; ++ i) {
		node[i * 4 - 3].x = read(), node[i * 4 - 3].y = read();
		node[i * 4 - 2].x = read(), node[i * 4 - 2].y = read();
		node[i * 4 - 1].x = read(), node[i * 4 - 1].y = read();
		node[i * 4].x = (node[i * 4 - 3].x == node[i * 4 - 2].x) ? 
						(node[i * 4 - 1].x) : 
						(node[i * 4 - 3].x == node[i * 4 - 1].x ? 
						 node[i * 4 - 2].x : node[i * 4 - 3].x);
		node[i * 4].x = (node[i * 4 - 3].x == node[i * 4 - 2].x) ? 
						(node[i * 4 - 1].x) : 
						(node[i * 4 - 3].x == node[i * 4 - 1].x ? 
						 node[i * 4 - 2].x : node[i * 4 - 3].x);
		T[i] = read();
	}

	for(int i = 1; i <= s * 4; ++ i)
		for(int j = i + 1; j <= s * 4; ++ j) {
			double tmp = getDis(node[i].x, node[i].y, node[j].x, node[j].y);
			dis[i][j] = dis[j][i] = ((i - 1) / 4 == (j - 1) / 4) ? 
									tmp * T[(i - 1) / 4 + 1] : t;
		}
}

void solve() {
	n = read();
	while(n --) {
		init();
		dijkstra(A * 4 - 3);
		dijkstra(A * 4 - 2);
		dijkstra(A * 4 - 1);
		dijkstra(A * 4);
		printf("%.1lf\n", minn);
	}
}

int main() {
	solve();
}
