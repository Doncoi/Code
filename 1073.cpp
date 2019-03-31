#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 5005
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, m, p;
int father[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline int find(int x) {
	return (father[x] == x ? x : father[x] = find(father[x]));
}

inline void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) father[fx] = fy;
}

void init() {
	n = read(), m = read(), p = read();
	for(int i = 1; i <= n; ++ i) 
		father[i] = i;
	for(int i = 1; i <= m; ++ i) 
		merge(read(), read());
}

void solve() {
	while(p --) {
		int fx = find(read()), fy = find(read());
		if(fx == fy) printf("Yes\n");
		else printf("No\n");
	}
}

int main() {
	init();
	solve();
}
