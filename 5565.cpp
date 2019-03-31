#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define MAXN 105
#define INF 0x3f3f3f3f

int n, q;
int num[MAXN] = {0}, f[MAXN][MAXN] = {0};
int tree[MAXN][5] = {0}, value[MAXN][MAXN] = {0};

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return res * flag;
}

inline void init() {
	n = read(), q = read();
	for(int i = 0; i <= n; ++ i) 
		for(int j = 0; j <= n; ++ j)
			value[i][j] = value[j][i] = -1;
	for(int i = 1; i < n; ++ i) {
		int x = read(), y = read();
		value[x][y] = value[y][x] = read();
	}
}

inline void build(int x, int y, int type);
inline void makeTree(int x);

//设tree[v,1]为节点v的左子树，tree[v,2]为节点v的右子树
inline void build(int x, int y, int type) {
	num[y] = value[x][y], tree[x][type] = y;
	value[x][y] = -1, value[y][x] = -1;
	makeTree(y);
}

inline void makeTree(int x) {
	int type = 0;
	for(int y = 0; y <= n; ++ y) 
		if(value[x][y] >= 0) {
			build(x, y, ++ type);
			if(type == 2) return;
		}
}

//f[i][j]表示以i为节点的根保留k条边的最大值，那么f[v][k]=max(f[v][k], 
//(f[tree[v][1]][i]+f[tree[v][2]][k-i-1]+num[v]))
inline void DFS(int u, int k) {
	if(k == 0) f[u][k] = 0;
	else if(tree[u][1] == 0 && tree[u][2] == 0) f[u][k] = num[u];
	else {
		f[u][k] = 0;
		for(int i = 0; i < k; ++ i) {
			if(!f[tree[u][1]][i])         DFS(tree[u][1], i);
			if(!f[tree[u][2]][k - i - 1]) DFS(tree[u][2], k - i - 1);
			f[u][k] = max(f[u][k], 
				      f[tree[u][1]][i] + f[tree[u][2]][k - i - 1] + num[u]);
		}	
	}
}

int main() {
	init();
	makeTree(1);
	DFS(1, q + 1);
	printf("%d\n", f[1][q + 1]);
}
