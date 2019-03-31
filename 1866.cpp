#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 505 
#define max(a, b) (a > b ? a : b)

struct Node {
	int w, v, b, c, d;
} node[MAXN];

int n, m, tmpw, tmpn;
int f[MAXN][MAXN * 5];
bool map[MAXN][MAXN] = {false};

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = 1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return res * flag;
}

inline void floyd() {
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			for(int k = 1; k <= n; ++ k)
				if(map[k][i] && map[i][j]) map[k][j] ^= 1;
}

inline void merge() {
	tmpw = 0, tmpn = n;
	for(int i = 1; i <= tmpn; ++ i) 
		for(int j = 1; j <= tmpn; ++ j) {
			if(map[i][j] && map[j][i] && i != j && node[i].w && node[j].w) {
				node[++ tmpn].v = node[i].v + node[j].v, node[tmpn].w = node[i].w + node[j].w;
				node[i].w = -- tmpw, node[j].w = tmpw; 
			}
			if(node[node[j].d].w < 0 && node[j].w && map[j][node[j].d]) {
				node[n - node[node[j].d].w].w += node[j].w;
				node[n - node[node[j].d].w].v += node[j].v;
				node[j].w = node[node[j].d].w;
			}
			if(node[node[j].d].w < 0 && node[j].w) {
                if((map[j][node[j].d] && map[node[j].d][j]) || (!map[j][node[j].d] && map[node[j].d][j]))
                	node[j].d = n - node[node[j].d].w;
			}
		}
}

inline int DFS(int x, int k) {
	if(f[x][k] > 0) return f[x][k];
	if(x == 0 || k <= 0) return 0;
	f[node[x].b][k] = DFS(node[x].b, k);
	f[x][k] = f[node[x].b][k];

	int y = k - node[x].w;
	for(int i = 0; i <= y; ++ i) {
       	f[node[x].c][y - i] = DFS(node[x].c, y - i);
       	f[node[x].b][i] = DFS(node[x].b, i);
       	f[x][k] = max(f[x][k], node[x].v + f[node[x].c][y - i] + f[node[x].b][i]);
	}
	return f[x][k];
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) node[i].w = read();
	for(int i = 1; i <= n; ++ i) node[i].v = read();	
	for(int i = 1; i <= n; ++ i) {node[i].d = read(); map[node[i].d][i] ^= 1;}

	floyd();   merge();

	for(int i = 1; i <= tmpn; ++ i)
		if(node[i].w) node[i].b = node[node[i].d].c, node[node[i].d].c = i;
	printf("%d\n", DFS(node[0].c, m));
}
