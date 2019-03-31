#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 15
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, m, t, k, a, b;
int x1, y1, x2, y2, f[MAXN * 10][MAXN * 10];
int x[MAXN], y[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read(), m = read(), t = read(), k = read();
	for(int i = 1; i <= n; ++ i) x[i] = read();
	for(int i = 1; i <= m; ++ i) y[i] = read();
	for(int i = 1; i <= n * m; ++ i)
		for(int j = 1; j <= n * m; ++ j) 
			if(i == j) f[i][j] = 0;
			else f[i][j] = INF;
	for(int i = 1; i <= n; ++ i)
		for(int j =1 ; j <= m; ++ j) {
			if(i > 1) {
				a = i - 1, b = j;
				f[(j - 1) * n + i][(b - 1) * n + a] = x[i] - x[i - 1];
			}
			if(j > 1) {
				a = i, b = j - 1;
				f[(j - 1) * n + i][(b - 1) * n + a] = y[j] - y[j - 1];
			}
			if(i < n) {
				a = i + 1, b = j;
				f[(j - 1) * n + i][(b - 1) * n + a] = x[i + 1] - x[i];
			}
			if(j < m) {
				a = i, b = j + 1;
				f[(j - 1) * n + i][(b - 1) * n + a] = y[j + 1] - y[j];
			}
		}

	for(int i = 1; i <= t; ++ i) {
		x1 = read(), y1 = read(), x2 = read(), y2 = read();
		f[(y1 - 1) * n + x1][(y2 - 1) * n + x2] = INF;
		f[(y2 - 1) * n + x2][(y1 - 1) * n + x1] = INF;
	}
	for(int i = 1; i <= k; ++ i) {
		x1 = read(), y1 = read(), x2 = read(), y2 = read();
		for(a = x1; a <= x2 - 1; ++ a)
			for(b = y1 + 1; b <= y2 - 1; ++ b) {
				f[(b - 1) * n + a][(b - 1) * n + a + 1] = INF;
				f[(b - 1) * n + a + 1][(b - 1) * n + a] = INF;
			}		
	}
}

void solve() {
	for(b = y1; b <= y2 - 1; ++ b) 
		for(a = x1 + 1; a <= x2 - 1; ++ a) {
			f[(b - 1) * n + a][b * n + a] = INF;
			f[b * n + a][(b - 1) * n + a] = INF;
		}

	for(int k = 1; k <= n * m; ++ k)
		for(int i = 1; i <= n * m; ++ i)
			for(int j = 1; j <= n * m; ++ j)
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);

	x1 = read(), y1 = read(), x2 = read(), y2 = read();
	printf("%d\n", f[(y1 - 1) * n + x1][(y2 - 1) * n + x2]);
}

int main() {
	init();
	solve();
}
