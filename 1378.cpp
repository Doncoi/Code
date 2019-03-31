#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 305 
#define max(a, b) (a > b ? a : b)

int n, m;
int child[MAXN], brother[MAXN], son[MAXN], f[MAXN][MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = 1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return res * flag;
}

inline void init() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) {
		int a, b; scanf("%d%d", &a, &b); son[i] = b;
		if(a == 0) a = n + 1;
		brother[i] = child[a], child[a] = i;
	}
}

inline void DFS(int x, int y) {
	if(f[x][y] >= 0) return;
	if(x == 0 || y == 0) {f[x][y] = 0; return;}
	DFS(brother[x], y);
	for(int k = 0; k < y; ++ k) {
		DFS(brother[x], k); DFS(child[x], y - k - 1);
		f[x][y] = max(f[x][y], 
				  max(f[brother[x]][y], f[brother[x]][k] + f[child[x]][y - k - 1] + son[x]));
	}
	return;
}

int main() {
	for(int i = 0; i < MAXN; ++ i) 
		for(int j = 0; j < MAXN; ++ j) 
			f[i][j] = -1;
	init();
	DFS(child[n + 1], m);

	printf("%d\n", f[child[n + 1]][m]);
}
