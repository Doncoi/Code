#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1005
#define MAXM 105
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, m, x, y, y1;
int c[MAXN], u[MAXN], f[MAXN], w[MAXM][MAXM] = {0};

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	y = read(), y1 = read();
	for(int i = 1; i <= y; ++ i) {
		c[i] = read(), u[i] =read();
		if(c[i] >= 1) ++ n;
		if(c[i] == 0) ++ m;
	}

	for(int i = 1; i <= y1; ++ i) {
		int from, to, value;
		from = read(), to = read(), value = read();
		w[from][to] = value, f[from] ++;
	}
}

void solve() {
	for(int i = n + 1; i <= y; ++ i) {
		for(int j = 1; j <= i - 1; ++ j) {
			if(c[j] > 0) {
				c[i] = c[i] + w[j][i] * c[j];
			} 
		}
		c[i] -= u[i];
	}

	int tmp = 0;
	for(int i = 1; i <= y; ++ i) {
		if(!f[i] && c[i] > 0) {
			printf("%d %d\n", i, c[i]);
			tmp = 1;
		}
	}

	if(!tmp) {
		printf("NULL\n");
	}
}	

int main() {
	init();
	solve();
}
