#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, pre = 0, time_cost = 0;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read();
}

void solve() {
	for(int i = 1; i <= n; ++ i) {
		int tmp = read();
		if(tmp > pre) time_cost += ((tmp - pre) * 6 + 5);
		else time_cost += ((pre - tmp) * 4 + 5);
		pre = tmp;
		//printf("pre : %d    time_cost : %d\n", pre, time);
	}
	printf("%d\n", time_cost);
}

int main() {
	init();
	solve();
}
