#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, sum;
int a[MAXN], f[MAXN], g[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
}

void solve() {
	f[1] = 1;
	for(int i = 2; i <= n; ++ i) {
		for(int j = 1; j < i; ++ j)
			if(a[j] < a[i] && f[j] > f[i])
				f[i] = f[j];
		++ f[i];	
	} 

	g[n] = 1;
	for(int i = n - 1; i >= 1; -- i) {
		for(int j = i + 1; j <= n; ++ j)
			if(a[i] > a[j] && g[i] < g[j])
				g[i] = g[j];
		++ g[i];
	}

	for(int i = 1; i <= n; ++ i)
		if(f[i] + g[i] - 1 > sum)
			sum = f[i] + g[i] - 1;

	printf("%d", n - sum);
}

int main() {
	init();
	solve();
}
