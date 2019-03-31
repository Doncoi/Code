#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 45
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, k, ans;
int a[MAXN], b[MAXN], f[MAXN * 100];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void DP() {
	memset(f, 0, sizeof(f));
	int i = 0;
	while(f[i] <= n) {
		f[++ i] = INF;
		for(int j = 1; j <= k && i - a[j] >= 0; ++ j) 
			f[i] = min(f[i], f[i - a[j]] + 1);
	}

	if(i - 1 > ans) {
		for(int j = 1; j <= k; ++ j) b[j] = a[j];
		ans = i - 1;
	}
}

void DFS(int x) {
	if(x == k + 1) {
		DP();
		return;
	}
	for(int i = a[x - 1]; i <= a[x - 1] * n + 1; ++ i) {
		a[x] = i; DFS(x + 1);
	}
}

void init() {
	n = read(), k = read();
	a[1] = 1;
}

void solve() {
	DFS(2);
	for(int i = 1; i <= k; ++ i)
		printf("%d ", b[i]);
	printf("\nMAX=%d\n", ans);
}

int main() {
	init();
	solve();
}
