#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 15
#define MAXM 
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

const int delta = 30;

int height, a[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	for(int i = 1; i <= 10; ++ i) {
		a[i] = read();
	}
	height = read();
}

void solve() {
	int ans = 0;
	for(int i = 1; i <= 10; ++ i) {
		if((height + delta) >= a[i]) {
			++ ans;
		}
	}

	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
