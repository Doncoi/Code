#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000
#define INF 0x7fffffff
#define min(a, b) (a < b ? a : b) 

int n, m, limit;
int a[10][12], f[12], sum[12];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void DFS(int x) {
	for(int i = 0; i <= f[x]; ++ i) {
		for(int j = 1; j <= m; ++ j)
			sum[j] += a[x][j] * i;
		if(x < n) {
			DFS(x + 1);
		} else {
			bool flag = false;
			for(int j = 2; j <= m; ++ j) 
				if(sum[j] != sum[j - 1]) {
					flag = true;
					break;
				}

			if(!flag)
				if(sum[1] * m < limit && sum[1] > 0 > 0)
					limit = min(limit, sum[1] * m);
		}

		for(int j = 1; j <= m; ++ j)
			sum[j] -= a[x][j] * i;
	}
}

void init() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			a[i][j] = read();

	for(int i = 1; i <= n; ++ i)
		f[i] = read();
	limit = MAXN + 1;
}

void solve() {
	DFS(1);
	if(limit <= MAXN) printf("%d\n", limit);
	else printf("alternative!\n");
}

int main() {
	init();
	solve();
}
