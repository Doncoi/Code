#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, a, b, cnt_a, cnt_b;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read(), a = read();
	cnt_a = 1, cnt_b = 0;
}

void solve() {
	for(int i = 1; i < n; ++ i) {
		int tmp = read();
		if(!b) {
			if(tmp == a) {
				++ cnt_a;
			} else {
				b = tmp, ++ cnt_b;
			}
		} else {
			if(tmp == a) {
				++ cnt_a;
			} else if(tmp == b) {
				++ cnt_b;
			} else {
				printf("NO\n");
				return;
			}
		}
	}
		
	if(cnt_a == cnt_b) {
		printf("YES\n%d\n%d\n", a, b);
	} else {
		printf("NO\n");
	}
}

int main() {
	init();
	solve();
}
